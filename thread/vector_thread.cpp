#include <iostream>
#include <vector>
#include <list>

#include <thread>
using namespace std;


/*
void myprint(int i)
{
    cout<<"线程开始"<<endl;
    cout<<"线程结束"<<endl;
}*/
class A
{
    public:
        void inmsgRecv()
        {
            for(int i=0;i<100000;i++)
            {
                cout<<"inmsgRecv()执行，插入"<<endl;
                msgQueue.push_back(i);
            }
        }
        void outmsgRecv()
        {
            for(int i=0;i<100000;i++)
            {
                if(!msgQueue.empty())
                {
                    int command=msgQueue.front();
                    msgQueue.pop_front();

                }
                else
                {
                     cout<<"outmsgRecv()执行为空，目前消息队列为空"<<i<<endl;
                    msgQueue.push_back(i);
                }
            }
        }
    private:
        list<int> msgQueue;
};

int main()
{
    /*vector<thread> mythread;
    for(int i=0;i<10;i++)
        mythread.push_back(thread(myprint,i));

    for(auto iter=mythread.begin();iter!=mythread.end();iter++)
        iter->join();*/
    A a;
    thread myout(&A::outmsgRecv,&a);
    thread myin(&A::inmsgRecv,&a);

    myout.join();
    myin.join();
}