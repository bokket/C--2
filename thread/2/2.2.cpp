//
// Created by bokket on 2020/11/12.
//
#include <iostream>
#include <mutex>

using namespace std;

class A
{
private:
    int i;
public:
    void doSomething();
};

class B
{
private:
    A data;
    mutex m;
public:
    template<typename F>
    void processDate(F f)
    {
        std::scoped_loack l(m);
        f(data);
    }
};
