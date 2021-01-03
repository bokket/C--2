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
    rr
}
void Thread::SetName(const string &name)
{}
Thread::Thread() {}

Thread::~Thread() {}

void Thread::join()
{}

void * Thread::run(void *arg)
{}

}