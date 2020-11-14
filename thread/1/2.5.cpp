#include <iostream>
#include <thread>

using namespace std;

void f(int i,string s)
{
    cout<<"f()"<<endl;
}

void ops(int a)
{
    char buffer[1024];
    sprintf(buffer,"%i",a);
    thread t(f,3,(buffer));
    t.detach();
}
int main()
{
    ops(1);
}