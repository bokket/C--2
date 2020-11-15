#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <list>
template<typename T>
class SynQueue
{
    bool isFull () const
    {
        return m_queue.size()==m_maxsize;
    }
    bool isEmpty() const
    {
        return m_queue.empty();
    }
    public:
        SynQueue(int maxSize) :m_maxsize(maxSize)
        {

        }
        void put(const T &x)
        {
            std::lock_guard<std::mutex> locker(m_mutex);
            while(isFull())
            {
                cout<<"缓冲区满了， 需要等待...."<<endl;
                m_notFull.wait(m_mutex);
            }
            m_queue.push_back(x);
            m_notEmpty.notify_one();
        }
        void Take(T& x)
        {
             std::lock_guard<std::mutex> locker(m_mutex);
            while(isEmpty())
            {
                cout<<"缓冲区空了， 需要等待...."<<endl;
                m_notEmpty.wait(m_mutex);
            }
            x=m_queue.front();
            m_queue.pop_front();
            m_notFull.notify_one();
        }
        bool Empty()
        {
            std::lock_guard<std::mutex> locker(m_mutex);
            return m_queue.empty();
        }
        bool Full()
        {
            std::lock_guard<std::mutex> locker(m_mutex);
            return m_queue.size()==m_maxsize;
        }
        size_t Size()
        {
            std::lock_guard<std::mutex> locker(m_mutex);
            return m_queue.size();
        }
        int Count()
        {
            return m_queue.size();
        }
    private:
        std::list<T> m_queue;
        std::mutex m_mutex;
        std::condition_variable_any m_notEmpty;
        std::condition_variable_any m_notFull;
        int m_maxsize;
};

int main()
{
    SynQueue s;
    thread t1(&s::put,&s);
    thread t2(&s::Take,&s);
    t1.join();
    t2.join();
}