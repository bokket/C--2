#include <iostream>
#include <thread>
using namespace std;

void do_something(int &i)
{
    ++i;
    cout<<i<<endl;
}

class thread_guard
{
    thread &t;
public:
    explicit thread_guard(thread & x) : t(x) {}
    ~thread_guard() 
    { 
        if (t.joinable())  
            t.join();
    }
    thread_guard(const thread_guard&)= delete;
    thread_guard& operator = (const thread_guard &) =delete;
};
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

};

void f()
{
    int x=0;
    A a(x);
    thread t(a);
    thread_guard g(t);
    doSomethingHere();
}
// 局部对象逆序销毁，优先销毁thread_guard对象，从而调用t.join()