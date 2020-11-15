#include <iostream>
#include <vector>
#include <list>
#include <mutex>
#include <thread>
using namespace std;

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
        mutex mutex;
};
