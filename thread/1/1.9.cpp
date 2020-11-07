#include <iostream>
#include <thread>

using namespace std;

class A
{
    public:
        void f(int i)
        {
            cout<<i<<endl;
        }
};
int main()
{
    A a;
    thread t(&A::f,&a,42);// 第一个参数为类中成员函数地址，第二个参数为实例地址
    t.join();
}