#include <iostream>
#include <thread>

using namespace std;

void f(int &n)
{
    ++n;
}
int main()
{
    int i=1;
    thread t(f,ref(i));
    t.join();
    cout<<i<<endl;
}