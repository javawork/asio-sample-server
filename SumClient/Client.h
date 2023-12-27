#pragma once

#include <iostream>
#include <boost/asio.hpp>
#include <boost/asio/buffer.hpp>
#include <boost/bind/bind.hpp>
#include "../Shared/Packet.h"
#include "../Shared/sum.pb.h"
#include "CircularBuffer.h"

static asio::chrono::milliseconds gTimerDelay = asio::chrono::milliseconds(10);
constexpr int MaxCount = 500;

static int GenerateRandomNumber()
{
    return rand() % 10 + 1;
}


class Client
{
public:
    Client(asio::io_context& ioContext) : _socket(ioContext), _timer(ioContext, gTimerDelay), _sum(0), _count(0)
    {
        memset(_recvBuffer, 0, RecvBufferSize);
        _timer.async_wait(
            boost::bind(&Client::OnTimer, this));
    }

    ~Client()
    {
    }

    void Connect(std::string host, int port)
    {
        asio::ip::tcp::endpoint endpoint(asio::ip::make_address(host), port);
        _socket.async_connect(endpoint, boost::bind(&Client::OnConnect, this, asio::placeholders::error));
    }

    void AsyncWrite(asio::mutable_buffer& buffer)
    {
        asio::async_write(_socket, buffer,
            boost::bind(&Client::OnWrite, this, asio::placeholders::error, asio::placeholders::bytes_transferred));
    }

private:
    void OnTimer()
    {
        //std::cout << "OnTimer" << std::endl;

        pbsum::Add pbMsg;
        pbMsg.set_num(GenerateRandomNumber());

        const size_t requiredSize = PacketUtil::RequiredSize(pbMsg);
        auto buffer = asio::buffer(_buffer.Allocate(requiredSize), requiredSize);
        if (!PacketUtil::Serialize(buffer, pbsum::MessageCode::ADD, pbMsg))
        {
            // todo: error
        }

        AsyncWrite(buffer);

        _sum += pbMsg.num();
        ++_count;

        if (_count < MaxCount)
        {
            _timer.expires_at(_timer.expiry() + gTimerDelay);
            _timer.async_wait(boost::bind(&Client::OnTimer, this));
        }
        else
        {
            pbsum::LocalSum pbParity;
            pbParity.set_sum(_sum);

            const size_t requiredSize = PacketUtil::RequiredSize(pbParity);
            auto buffer = asio::buffer(_buffer.Allocate(requiredSize), requiredSize);
            if (!PacketUtil::Serialize(buffer, pbsum::MessageCode::LOCAL_SUM, pbParity))
            {
                // todo: error
            }

            AsyncWrite(buffer);

            std::cout << "done!" << std::endl;
        }

    }

    void OnConnect(const boost::system::error_code& err)
    {
        std::cout << "OnConnect" << std::endl;
        if (!err)
        {
            AsyncRead();
        }
    }

    void OnWrite(const boost::system::error_code& err, size_t bytes_transferred)
    {
        //std::cout << "OnWrite " << bytes_transferred << std::endl;
        if (!err)
        {

        }
        else
        {
            std::cout << "error code: " << err.value() << ", msg: " << err.message() << std::endl;
        }
    }

    void OnRead(const boost::system::error_code err, size_t size)
    {
        std::string msg(_recvBuffer, size);
        std::cout << "OnRead size: " << size << std::endl;

        if (!err)
        {
            HandlePacket(_recvBuffer, size);
            AsyncRead();
        }
        else
        {
            std::cout << "error code: " << err.value() << ", msg: " << err.message() << std::endl;
        }
    }

    void AsyncRead()
    {
        memset(_recvBuffer, 0, RecvBufferSize);
        _socket.async_read_some(
            asio::buffer(_recvBuffer, RecvBufferSize),
            boost::bind(
                &Client::OnRead, this,
                asio::placeholders::error,
                asio::placeholders::bytes_transferred
            )
        );
    }

    void HandlePacket(char* ptr, size_t size)
    {
        asio::mutable_buffer buffer = asio::buffer(ptr, size);
        int offset = 0;
        PacketHeader header;
        PacketUtil::ParseHeader(buffer, &header, offset);

        //std::cout << "HandlePacket " << pbsum::MessageCode_Name(header.Code) << std::endl;
    }

private:
    static const int RecvBufferSize = 1024;

    asio::ip::tcp::socket _socket;
    char _recvBuffer[RecvBufferSize];
    asio::steady_timer _timer;
    int _sum;
    int _count;
    CircularBuffer _buffer;
};
