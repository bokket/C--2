//
// Created by bokket on 2021/1/3.
//

#include "thread.h"
#include "./log/log.h"
#include "./util/util.h"

using namespace std;

namespace bokket
{

static thread_local Thread* t_thread=NULL;
static thread_local string t_thread_name="UNKNOW";


static bokket::Logger::ptr g_logger=BOKKET_LOG_NAME("system");

Semaphore::Semaphore(uint32_t count)
{
    if(sem_init(&m_semaphore,0,count))
    {
        throw logic_error("sem_init error");
    }
}
Semaphore::~Semaphore()
{
    sem_destroy(&m_semaphore);
}

void Semaphore::wait()
{
    if(sem_wait(&m_semaphore))
    {
        throw logic_error("sem_wait error");
    }
}
void Semaphore::notify()
{
    if(sem_post(&m_semaphore))
    {
        throw logic_error("sem_post error");
    }
}


Thread * Thread::GetThis()
{
    return t_thread;
}
const string & Thread::GetName()
{
    return t_thread_name;
}

void Thread::SetName(const string &name)
{
    if(t_thread)
        t_thread->m_name=name;

    t_thread_name=name;
}
Thread::Thread(function<void()> cb,const string & name)
                :m_cb(cb)
                ,m_name(name)
{
    if(name.empty())
        m_name="UNKNOW";

    int rt=pthread_create(&m_thread,NULL,&Thread::run,this);
    if(rt)
    {
        BOKKET_LOG_ERROR(g_logger) << "pthread_create thread fail,rt=" << rt
        <<"name ="<<name;
        throw logic_error("pthread_create error");
    }

    m_semaphore.wait();
}

Thread::~Thread()
{
    if(m_thread)
        pthread_detach(m_thread);
}

void Thread::join()
{
    if(m_thread)
    {
        int rt=pthread_join(m_thread,NULL);

        if(rt)
        {
            BOKKET_LOG_ERROR(g_logger) << "pthread_join thread fail,rt=" << rt
                                       <<"name ="<<name;
            throw logic_error("pthread_join error");
        }
        m_thread=0;
    }
}

void * Thread::run(void *arg)
{
    Thread* thread=(Thread*)arg;

    t_thread=thread;
    t_thread_name=thread->m_name;

    thread->m_id=bokket::GetThreadId();

    pthread_setname_np(pthread_self(),thread->m_name.substr(0,15).c_str());


    function<void()> cb;
    cb.swap(thread->m_cb);


    thread->m_semaphore.notify();

    cb();
    return 0;
}

}