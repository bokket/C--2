//
// Created by bokket on 2020/12/24.
//

#include "TcpServer.h"
using namespace bokket;

TcpServer::TcpServer() {}
TcpServer::~TcpServer() {}
void TcpServer::start() {}
int TcpServer::crealisten()
{
     int op=1;
     int lfd=socket(AF_INET,SOCK_STREAM,0);
     struct sockaddr_in serv_addr;

     //no nonblock io
     fcntl(lfd,F_SETFL,O_NONBLOCK);

     setsockopt(lfd,SOL_SOCKET,SO_REUSEADDR,&op,sizeof(op));
     serv_addr.sin_family=AF_INET;
     serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
     serv_addr.sin_port=htons(1234);

     int ret=bind(lfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));

     ret=listen(lfd,MAX);

     return lfd;
}

void TcpServer::start()
{
    struct epoll_event ev,event[MAX];
    int lfd,cfd,sockfd;

}