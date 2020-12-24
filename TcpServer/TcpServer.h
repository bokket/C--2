//
// Created by bokket on 2020/12/24.
//

#ifndef C_2_TCPSERVER_H
#define C_2_TCPSERVER_H


#include <sys/socket.h>
#include <sys/epoll.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>
#include <string>
#include <iostream>

namespace bokket
{
class TcpServer
{
    TcpServer();
    ~TcpServer();
    void start();

private:
    int crealisten();
};
}


#endif //C_2_TCPSERVER_H
