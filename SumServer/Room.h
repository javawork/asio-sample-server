#pragma once

#include <iostream>
#include <set>
#include <boost/asio.hpp>
#include <boost/asio/buffer.hpp>
#include <boost/enable_shared_from_this.hpp>
#include "../Shared/sum.pb.h"

using namespace boost;
using boost::asio::ip::tcp;

class Member
{
public:
    Member() {}
    virtual ~Member() = default;
    virtual void SetName(const std::string& msg) = 0;
    virtual std::string GetName() = 0;
    virtual void Send(asio::mutable_buffer& buffer) = 0;
};

typedef boost::shared_ptr<Member> MemberPtr;

class Room
{
public:
    Room(asio::io_context& io_context) : _strand(boost::asio::make_strand(io_context)), _globalSum(0), _localSum(0)
    {}

    void Join(MemberPtr member)
    {
        asio::dispatch(asio::bind_executor(_strand, [this, member]
            {
                _members.insert(member);
            }));


    }

    void Leave(MemberPtr member)
    {
        asio::dispatch(asio::bind_executor(_strand, [this, member]
            {
                _members.erase(member);
                if (_members.size() == 0)
                {
                    _globalSum = 0;
                    _localSum = 0;
                    std::cout << _globalSum << ", " << _localSum << std::endl;
                }
            }));
    }

    void Broadcast(asio::mutable_buffer& buffer)
    {
        std::for_each(_members.begin(), _members.end(),
            [&buffer](MemberPtr p) {
                p->Send(buffer);
            });
    }

    void Add(int num)
    {
        asio::dispatch(asio::bind_executor(_strand, [this, num]
            {
                _globalSum += num;
            }));

        // without strand
        // _globalSum += num;

    }

    void LocalSum(int num)
    {

        asio::dispatch(asio::bind_executor(_strand, [this, num]
            {
                _localSum += num;
                std::cout << "GlobalSum: " << _globalSum << std::endl;
                std::cout << "LocalTotal: " << _localSum << std::endl;
            }));

        // without strand
        //_localSum += num;
    }


private:
    std::set<MemberPtr> _members;
    boost::asio::strand<boost::asio::io_context::executor_type> _strand;
    int _globalSum;
    int _localSum;
};