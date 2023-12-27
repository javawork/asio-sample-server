#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#include "../Shared/sum.pb.h"
#include "Client.h"

static void ExecuteCommand(const std::string& line, Client& client)
{
    typedef std::vector<std::string> Tokens;
    Tokens tokens;
    boost::split(tokens, line, boost::is_any_of(" "));
    const std::string& mainCmd = tokens[0];
    // todo: execute command
}

int main()
{
    srand(time(0));
    asio::io_context ioContext;
    Client client(ioContext);
    client.Connect(std::string("127.0.0.1"), 4242);
    std::thread t(boost::bind(&boost::asio::io_context::run, &ioContext));

    char cmd[256] = { 0, };
    while (true)
    {
        std::cin.getline(cmd, 256);
        if ( strcmp(cmd, "exit") == 0)
            break;
        ExecuteCommand(cmd, client);
        memset(cmd, 0, 256);
    }

    t.join();
}