
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

};

int main()
{
    int x=0;
    A a(x);
    thread t(a);
    try
    {
        doSomethingHere();
        t.join();
        throw;
    }
    catch(const std::exception& e)
    {
        t.join();
    }
    
}