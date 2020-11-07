//
// Created by bokket on 2020/11/6.
//

#include <iostream>
#include <thread>
using namespace std;

void do_something(int &i)
{
    ++i;
    cout<<i<<endl;
}
struct A
{
    int &i;
    A(int &i_)
        :i(i_)
    {}

    void operator()()
    {
        //cout<<i<<endl;
        for(unsigned j=0;j<100;j++)
            do_something(i);
    }

/*private:
    int i;*/
};
/*void f()
{
    int x=0;
    A a(x);//构造对象
    thread t(a);//构造线程对象
    //t.detach();// 不等待t结束
    t.join();
     // 函数结束后t可能还在运行，调用doSomething(i)，i是x的引用，而x已经销毁
}*/
int main()
{
    int x=0;
    A a(x);
    thread t(a);
    //thread t(f);
    //t.detach();
    t.join();// 等待t结束
    cout<<t.joinable()<<endl;
    //t.detach();
}