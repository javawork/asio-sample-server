#pragma once

#include <boost/asio.hpp>
#include <boost/asio/buffer.hpp>
#include <boost/bind/bind.hpp>
#include <boost/enable_shared_from_this.hpp>
#include "../Shared/Packet.h"
#include "Room.h"

using namespace boost;

class Session
    : public Member
    , public boost::enable_shared_from_this<Session>
{
public:
    Session(asio::io_context& ioContext, Room& room)
        : _socket(ioContext)
        , _room(room)
        , _strand(boost::asio::make_strand(ioContext))
    {
        memset(_recvBuffer, 0, RecvBufferSize);
        memset(_sendBuffer, 0, SendBufferSize);
    }

    void Start()
    {
        _room.Join(this->shared_from_this());
        AsyncRead();
    }

    asio::ip::tcp::socket& GetSocket()
    {
        return _socket;
    }

    void SendChat(const std::string& msg) override
    {
        std::cout << "SendChat " << msg.c_str() << std::endl;
        AsyncWrite(msg.c_str(), msg.size());
    }

    void SetName(const std::string& name) override
    {
        _name = name;
    }

    std::string GetName() override
    {
        return _name;
    }

    void Send(asio::mutable_buffer& buffer) override
    {
        AsyncWrite(static_cast<const char*>(buffer.data()), buffer.size());
    }

protected:
    void AsyncRead()
    {
        memset(_recvBuffer, 0, RecvBufferSize);
        _socket.async_read_some(
            boost::asio::buffer(_recvBuffer, RecvBufferSize),
            boost::bind(
                &Session::OnRead, this,
                boost::asio::placeholders::error,
                boost::asio::placeholders::bytes_transferred
            )
        );

    }

    void OnRead(const boost::system::error_code err, size_t size)
    {
        //std::cout << "OnRead " << size << std::endl;

        if (!err)
        {
            HandlePacket(_recvBuffer, size);
            AsyncRead();
        }
        else
        {
            std::cout << "error code: " << err.value() << ", msg: " << err.message() << std::endl;
            _room.Leave(this->shared_from_this());
        }
    }

    void AsyncWrite(const char* message, size_t size)
    {
        memcpy(_sendBuffer, message, size);
        asio::async_write(_socket, boost::asio::buffer(_sendBuffer, size),
            boost::asio::bind_executor(_strand, boost::bind(
                &Session::OnWrite, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred)));
    }

    void OnWrite(const boost::system::error_code& err, size_t bytes_transferred)
    {
        if (!err)
        {
        }
        else
        {
            std::cout << "error code: " << err.value() << ", msg: " << err.message() << std::endl;
            _room.Leave(this->shared_from_this());
        }
    }
    void HandlePacket(char* ptr, size_t size)
    {
        asio::mutable_buffer buffer = asio::buffer(ptr, size);
        int offset = 0;

        while (offset < size)
        {
            PacketHeader header;
            PacketUtil::ParseHeader(buffer, &header, offset);

            //std::cout << "HandlePacket " << pbsum::MessageCode_Name(header.Code) << std::endl;
            switch (header.Code)
            {
            case pbsum::MessageCode::ADD:
                HandleAdd(buffer, header, offset);
                break;
            case pbsum::MessageCode::LOCAL_SUM:
                HandleLocalSum(buffer, header, offset);
                break;
            }
        }
    }

    void HandleAdd(asio::mutable_buffer& buffer, const PacketHeader& header, int& offset)
    {
        pbsum::Add pbMsg;
        PacketUtil::Parse(pbMsg, buffer, header.Length, offset);
        //std::cout << "Get Num: " << pbMsg.num() << std::endl;
        _room.Add(pbMsg.num());
    }

    void HandleLocalSum(asio::mutable_buffer& buffer, const PacketHeader& header, int& offset)
    {
        pbsum::LocalSum pbMsg;
        PacketUtil::Parse(pbMsg, buffer, header.Length, offset);
        //std::cout << "Get LocalSum: " << pbMsg.sum() << std::endl;
        _room.LocalSum(pbMsg.sum());
    }


private:
    tcp::socket _socket;
    const static int RecvBufferSize = 1024;
    char _recvBuffer[RecvBufferSize];
    const static int SendBufferSize = 1024;
    char _sendBuffer[SendBufferSize];

    Room& _room;
    asio::strand<asio::io_context::executor_type> _strand;
    std::string _name;
};

typedef boost::shared_ptr<Session> SessionPtr;