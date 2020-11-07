#include <iostream>
#include <thread>

using namespace std;
void f()
{
    cout<<" f() "<<endl;
}
void g()
{
    cout<<" g() "<<endl;
}
int main()
{
    thread t1(f);
    thread t2=move(t1);//t1所有权给t2，t2关联执行f的线程
    //t2.join();
    t1=thread(g);//t1重新关联一个执行g的线程
    //t1.join();
    //t1.detach();
    thread t3;
    t3=move(t2);//t3关联t2的线程----f()，t2无关联
    //t3.join();
    t1 = move(t3); // t1已有关联g的线程，调用std::terminate终止程序
    t1.join();
}