#include <iostream>
#include <thread>

using namespace std;

void f(unique_ptr<int> p)
{
    cout<<*p;
}
int main()
{
    unique_ptr<int> p(new int(2));
    thread t(f,move(p));
    t.join();
}