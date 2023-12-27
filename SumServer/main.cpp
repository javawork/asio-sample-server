#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>
#include "Room.h"
#include "Session.h"

using namespace boost;
using boost::asio::ip::tcp;


class Server
{
public:
    Server(asio::io_context& io_context, int port)
        : _acceptor(io_context, tcp::endpoint(tcp::v4(), port))
        , _ioContext(io_context)
        , _room(io_context)
    {

    }

    void Start()
    {
        Session* session = new Session(_ioContext, _room);
        SessionPtr sessionPtr(session);
        _acceptor.async_accept(sessionPtr->GetSocket(),
            boost::bind(&Server::OnAccept, this, sessionPtr, asio::placeholders::error));
    }

protected:
    void OnAccept(SessionPtr session, boost::system::error_code ec)
    {
        if (!ec)
        {
            std::cout << "Connected " << std::endl;
            session->Start();
        }
        Start();
    }

private:
    tcp::acceptor _acceptor;
    asio::io_context& _ioContext;
    Room _room;
};

int main()
{
    try
    {
        constexpr int port = 4242;
        boost::asio::io_context io_context;
        Server s(io_context, port);
        s.Start();
        std::cout << "server start " << port << std::endl;
        std::thread t1(boost::bind(&boost::asio::io_context::run, &io_context));
        std::thread t2(boost::bind(&boost::asio::io_context::run, &io_context));
        io_context.run();
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }

}