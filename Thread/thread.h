//
// Created by bokket on 2021/1/3.
//

#ifndef C_2_THREAD_H
#define C_2_THREAD_H

#include <thread>
#include <functional>
#include <memory>
#include <pthread.h>
#include <semaphore.h>
#include <stdint.h>
#include <atomic>

#include "noncopyable.h"

using namespace std;

namespace bokket
{

class Semaphore: public Noncopyable
{
private:
    sem_t m_semaphore;
public:
    Semaphore(uint32_t count=0);
    ~Semaphore();

    void wait();
    void notify();
};

template<class T>
struct ScopedLockImpl
{
private:
    T& m_mutex;
    bool m_locked;
public:
    ScopedLockImpl(T & mutex)
                    :m_mutex(mutex)
    {
        m_mutex.lock();
        m_locked=true;
    }


    ~ScopedLockImpl()
    {
        unlock();
    }
    void lock()
    {
        //m_locked==false
        if(!m_locked)
        {
            m_mutex.lock();
            m_locked=true;
        }
    }
    void unlock()
    {
        //m_locked==true
        if(m_locked)
        {
            m_mutex.unlock();
            m_locked=false;
        }
    }
};


template<class T>
struct ReadScopedLockImpl
{
private:
    T& m_mutex;
    bool m_locked;
public:
    ReadScopedLockImpl(T& mutex)
                        :m_mutex(mutex)
    {
        m_mutex.rdlock();
        m_locked=true;
    }
    ~ReadScopedLockImpl()
    {
        unlock();
    }

    void lock()
    {
        if(!m_locked)
        {
            m_mutex.rdlock();
            m_locked=true;
        }
    }
    void unlock()
    {
        if(m_locked)
        {
            m_mutex.unlock();
            m_locked= false;
        }
    }
};

template<class T>
struct WriteScopedLockImpl
{
private:
    T& m_mutex;
    bool m_locked;
public:
    WriteScopedLockImpl(T& mutex)
                :m_mutex(mutex)
    {
        m_mutex.wrlock();
        m_locked=true;
    }
    ~WriteScopedLockImpl()
    {
        unlock();
    }

    void lock()
    {
        if(!m_locked)
        {
            m_mutex.wrlock();
            m_locked=true;
        }
    }
    void unlock()
    {
        if(m_locked)
        {
            m_mutex.unlock();
            m_locked=false;
        }
    }
};

class Mutex: public Noncopyable
{
public:
    typedef ScopedLockImpl<Mutex> Lock;
private:
    pthread_mutex_t m_mutex;
public:
    Mutex()
    {
        pthread_mutex_init(&m_mutex,NULL);
    }

    ~Mutex()
    {
        pthread_mutex_destroy(&m_mutex);
    }

    void lock()
    {
        pthread_mutex_lock(&m_mutex);
    }
    void unlock()
    {
        pthread_mutex_unlock(&m_mutex);
    }
};

class NullMutex: public Noncopyable
{
public:
    typedef ScopedLockImpl<NullMutex> Lock;
public:
    NullMutex() {}
    ~NullMutex() {}
    void lock() {}
    void unlock() {}
};


class RWMutex: public Noncopyable
{
public:
    typedef ReadScopedLockImpl<RWMutex> ReadLock;
    typedef WriteScopedLockImpl<RWMutex> WeadLock;
private:
    pthread_rwlock_t m_lock;
public:
    RWMutex()
    {
        pthread_rwlock_init(&m_lock,NULL);
    }
    ~RWMutex()
    {
        pthread_rwlock_destroy(&m_lock);
    }
    void rdlock()
    {
        pthread_rwlock_rdlock(&m_lock);
    }
    void wrlock()
    {
        pthread_rwlock_wdlock(&m_lock);
    }
    void unlock()
    {
        pthread_rwlock_unlock(&m_lock);
    }
};

class NullRWMutex: public Noncopyable
{
public:
    typedef ReadScopedLockImpl<NullMutex> ReadLock;
    typedef WriteScopedLockImpl<NullMutex> WriteLock;
public:
    NullRWMutex() {}
    ~NullRWMutex() {}
    void rdlock() {}
    void wrlock() {}
    void unlock() {}
};

class Spinlock: public Noncopyable
{
public:
    typedef ScopedLockImpl<Spinlock> Lock;
private:
    pthread_spinlock_t m_lock;
public:
    Spinlock()
    {
        pthread_spin_init(&m_lock,NULL);
    }
    ~Spinlock()
    {
        pthread_spin_destroy(&m_lock);
    }
    void lock()
    {
        pthread_spin_lock(&m_lock);
    }
    void unlock()
    {
        pthread_spin_unlock(&m_lock);
    }
};

class CASLock: public Noncopyable
{
public:
    typedef ScopedLockImpl<CASLock> Lock
private:
    volatile atomic_flag m_mutex;
public:
    CASLock()
    {
        m_mutex.clear();
    }
    ~CASLock()
    {

    }

    void lock()
    {
        while(atomic_flag_test_and_set(&m_mutex,memory_order_acquire));
    }
    void unlock()
    {
        atomic_flag_clear(&m_mutex,memory_order_release);
    }
};

class Thread
{
public:
    typedef shared_ptr<Thread> ptr;
public:
    Thread(function<void()> cb,const string & name);
    ~Thread();

    pid_t getId() const { return m_id; }

    const string & getName() const { return m_name; }

    void join();

    static Thread* GetThis();
    static const string& GetName();
    static void SetName(const string & name);

private:
    Thread(const Thread &)=delete;
    Thread(const Thread &&)=delete;
    Thread & operator=(const Thread &)=delete;

    static void *run(void* arg);
private:
    pid_t m_id=1;
    pthread_t m_thread=0;
    function<void()> m_cb;
    string m_name;

    Semaphore m_semaphore;
};

}



#endif //C_2_THREAD_H
