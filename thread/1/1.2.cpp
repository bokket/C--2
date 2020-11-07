//
// Created by bokket on 2020/11/6.
//

#include <iostream>
#include <thread>
using namespace std;
struct A
{
    void operator()() const
    {
        cout<<1;
    }
};
int main()
{
    A a;
    thread t1(a);
    // thread t(A()); // ()被视为函数声明
    // 解决most vexing parse的方法
    thread t2{A()};
    thread t3((A()));
    thread t4{[] { cout << 1; }};
    t1.join();
    t2.join();
    t3.join();
    t4.join();
}