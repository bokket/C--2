//
// Created by bokket on 2020/11/6.
//

#include <iostream>
#include <thread>
using namespace std;
void hello()
{
    cout<<"Hello concurrent world\n";
}

int main()
{
    cout<<"xiyou"<<endl;
    thread t(hello);
    cout<<"linux"<<endl;
    t.join();
    cout<<"group"<<endl;
}