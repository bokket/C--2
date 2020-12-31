//
// Created by bokket on 2020/12/30.
//

#ifndef C_2_ADDRESS_H
#define C_2_ADDRESS_H


#include <memory>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

namespace bokket
{

class Address
{
public:
    typedef shared_ptr<Address> ptr;
public:
    static Address::ptr Create(const sockaddr* addr,socklen_t addrlen);

    static bool Lookup(vector<Address::ptr>& result,const string& host
                       ,int family=AF_INET,int type=0,int protocol=0);
    static Address::ptr LookupAny(const string& host
                                  ,int family=AF_INET,int type=0,int protocol=0);
    static shared_ptr<IPAddress> LookupAnyIPAddress(const string & host
                                                    ,int family=AF_INET,int type=0,int protocol=0);

    static bool GetInterfaceAddress
};
}

#endif //C_2_ADDRESS_H
