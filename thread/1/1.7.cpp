#include <iostream>
#include <thread>

using namespace std;

void f(int i=1)
{
    cout<<i;
}

int main()
{
    thread t(f,42);
    t.join();
}
