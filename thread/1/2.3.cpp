#include <iostream>
#include <thread>

using namespace std;

void f(int i)
{
    cout<<i<<endl;
}

thread g()
{
    return thread(f,42);
}

int main()
{
    thread t{(g())};
    //thread t((g()));
    //thread t(g());
    //thread t{g()};
    t.join();
}