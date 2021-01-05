//
// Created by bokket on 2021/1/4.
//

#ifndef C_2_TIMER_H
#define C_2_TIMER_H

#include <memory>
#include <vector>
#include <set>
#include "../Thread/thread.h"

using namespace std;



namespace bokket
{
class TimerManager;

class Timer: public enable_shared_from_this<Timer>
{
    friend class TimerManager;

public:
    typedef shared_ptr<Timer> ptr;
    bool cancel();
    bool refresh();
    bool reset(uint64_t ms,bool from_now);

private:
    Timer(uint64_t ms,);
    Timer(uint64_t next);

private:
    bool m_recurring=false;
    uint64_t m_ms=0;
    uint64_t m_next=0;

    function<void()> m_cb;

    TimerManager* m_manager=NULL;

private:
    struct Comparator
    {
        bool operator()(const Timer::ptr & lhs, const Timer::ptr & rhs) const;
    };
};

class TimerManager
{
    friend class Timer;

public:
    typedef RWMutex RWMutexType;
public:
    TimerManager();
    virtual TimerManager();


    Timer::ptr addTimer(uint64_t)
};
}


#endif //C_2_TIMER_H
