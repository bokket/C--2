#include <iostream>
#include <vector>
#include <list>
#include <mutex>
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
                
                //{
                    mutex1.lock();
                    mutex2.lock();
                    msgQueue.push_back(i);
                    mutex2.unlock();
                    mutex1.unlock();
                //}
            }
        }

        bool outmsgProc(int &commond)
        {
            lock_guard<std::mutex> myguard(mymutex);
            if(!msgQueue.empty())
            {
                int command=msgQueue.front();
                msgQueue.pop_front();
                return true;
            }
            return false;
        }

        void outmsgRecv()
        {
            int commond=0;
            for(int i=0;i<100000;i++)
            {
                bool result=outmsgProc(commond);
                if(result)
                {
                    cout<<"outmsgRecv()执行，取出一个元素"<<endl;
                }
                /*if(!msgQueue.empty())
                {
                    int command=msgQueue.front();
                    msgQueue.pop_front();

                }*/
                else
                {
                    cout<<"outmsgRecv()执行为空，目前消息队列为空"<<i<<endl;
                    msgQueue.push_back(i);
                }
            }
        }
    private:
        list<int> msgQueue;
        
        mutex mymutex;
        mutex mutex1;
        mutex mutex2;
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