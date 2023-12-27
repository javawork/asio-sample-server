#pragma once
#include <boost/asio/buffer.hpp>
#include <google/protobuf/message.h>

using namespace boost;

struct PacketHeader
{
    short Length;
    short Code;
};

class PacketUtil
{
public:

    static bool ParseHeader(const asio::mutable_buffer& buffer, PacketHeader* header, int& offset)
    {
        if (buffer.size() <= offset)
            return false;

        const size_t remainedSize = buffer.size() - offset;
        if (remainedSize < sizeof(PacketHeader))
            return false;

        const char* headerPtr = static_cast<char*>(buffer.data()) + offset;
        memcpy(header, headerPtr, sizeof(PacketHeader));
        offset += sizeof(PacketHeader);
        return true;
    }

    static size_t RequiredSize(const google::protobuf::Message& msg)
    {
        return sizeof(PacketHeader) + msg.ByteSizeLong();
    }

    static bool Serialize(const asio::mutable_buffer& buffer, const short packetCode, const google::protobuf::Message& msg)
    {
        const size_t requiredSize = RequiredSize(msg);
        if (buffer.size() < requiredSize)
            return false;


        PacketHeader header;
        header.Length = static_cast<short>(msg.ByteSizeLong());
        header.Code = packetCode;

        // write header
        memcpy(buffer.data(), &header, sizeof(PacketHeader));

        // write payload
        char* payloadPtr = static_cast<char*>(buffer.data()) + sizeof(PacketHeader);
        if (!msg.SerializeToArray(payloadPtr, static_cast<int>(buffer.size()) - sizeof(PacketHeader)))
            return false;

        return true;
    }

    static bool Parse(google::protobuf::Message& msg, const asio::mutable_buffer& buffer, const int payloadSize, int& offset)
    {
        if (buffer.size() <= sizeof(PacketHeader))
            return false;

        const char* payloadPtr = static_cast<char*>(buffer.data()) + offset;
        const size_t remainedSize = buffer.size() - offset;
        const bool parseResult = msg.ParseFromArray(payloadPtr, payloadSize);
        if (parseResult)
        {
            offset += static_cast<int>(msg.ByteSizeLong());
            return true;
        }
        else
        {
            return false;
        }
    }
};
