//
// Created by bokket on 2021/1/4.
//

#ifndef C_2_TIMER_H
#define C_2_TIMER_H

#include <memory>
#include <vector>
#include <set>
#include "./Thread/thread.h"

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

};
}


#endif //C_2_TIMER_H
