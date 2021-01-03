//
// Created by bokket on 2021/1/3.
//

#ifndef C_2_NONCOPYABLE_H
#define C_2_NONCOPYABLE_H

namespace bokket
{
class Noncopyable
{
public:
    Noncopyable()=default;
    ~Noncopyable()=default;
    Noncopyable(const Noncopyable&)=delete;
    Noncopyable& operator=(const Noncopyable&)=delete;
};
}

#endif //C_2_NONCOPYABLE_H
