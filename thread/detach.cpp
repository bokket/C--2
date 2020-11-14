#include <iostream>
#include <string>
#include <thread>
#include <unistd.h>
using namespace std;

class A
{
    public:
        int m; 
        A(int a) :m(a) {}//cout<<"A::A(int a)构造函数执行"<<this<<"thread_id()"<<this_thread::get_id()<<endl;}
        A(const A& a) :m(a.m) {}//cout<<"A::A(const A)拷贝构造函数执行"<<this<<"thread_id()"<<this_thread::get_id()<<endl;}
        ~A() {cout<<"A::~A析构函数执行"<<endl;}
        void thread_work(int num)
        {
            cout<<"A::thread_work()执行"<<this<<"thread_id()"<<this_thread::get_id()<<endl;
        }
        
};

/*void myprint(const int i,const A& mybuf)
{
    //cout<<i<<endl;
    //cout<<mybuf<<endl;
    cout<<&mybuf<<endl;
}*/

/*void myprint2(A& buf)
{
    buf.m=11;
    cout<<"&mybuf : "<<&buf<<"thread_id()"<<this_thread::get_id()<<endl;
}*/

void myprint2(unique_ptr<int> p)
{
    cout<<&p<<endl;
    //cout<<"&mybuf : "<<&<<"thread_id()"<<this_thread::get_id()<<endl;
}
int main()
{
    std::thread
   /* cout<<"main_id()"<<this_thread::get_id()<<endl;
    int i=1;
    thread t(myprint2,A(i));
    t.detach();
    return 0;*/
    /*A t(10);
    thread s(myprint2,ref(t));
    s.detach();*/
    //unique_ptr<int > p(new int(100));
    //cout<<&p<<endl;
    //thread t(myprint2,move(p));
    A a(10);
    thread t(ref(a),11);
    //cout<<&p<<endl;
    t.join();
}
/*

int main()
{
    int i=10;
    int &j=i;
    //char str[]="hello";
    const int k=1000;
    thread t(myprint,i,(A)k);
    t.detach();
    //sleep(3);
}*/
