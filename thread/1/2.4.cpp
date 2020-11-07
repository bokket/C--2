#include <iostream>
#include <thread>

using namespace std;

void func1()
{
    cout<<"func1()"<<endl;
}
void func2()
{
    cout<<"func2()"<<endl;
}
void f(thread t)
{
    cout<<" this is thread t "<<endl;
    t.join();
}
void g()
{
    f(thread(func1));
    thread t(func2);
    f(move(t));
}
int main()
{
    g();
}