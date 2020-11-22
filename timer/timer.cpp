//
// Created by bokket on 2020/11/22.
//

#include <timer.h>
sort_timer_lst::~sort_timer_lst()
{
    util_timer* tmp=head;
    while(tmp)
    {
        head=tmp->next;
        delete tmp;
        tmp=head;
    }
}
void sort_timer_lst::add_timer(util_timer* timer)
{
    if(!timer)
    {
        return ;
    }
    if(!head)
    {
        head=tail=timer;
        return ;
    }

    if(timer->expire < head->expire)
    {
        timer->next=head;
        head->prev=timer;
        head=timer;
        return ;
    }
    add_timer(timer,head);
}
void sort_timer_lst::adjust_timer(util_timer* timer)
{
    if(!timer)
    {
        return ;
    }
    util_timer* tmp=timer->next;

    if(!tmp || (timer->expire < tmp->expire))
    {
        return ;
    }
    if(timer==head)
    {
        head=head->next;
        head->prev=NULL;
        timer->next=NULL;
        add_timer(timer,head);
    }
}
void sort_timer_lst::del_timer(util_timer* timer)
{

}
void sort_timer_lst::tick()
{

}