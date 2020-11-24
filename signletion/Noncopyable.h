//
// Created by bokket on 2020/11/24.
//

#ifndef C_2_NONCOPYABLE_H
#define C_2_NONCOPYABLE_H
#include <iostream>
using namespace std;
class Noncopyable
{
protected:
    Noncopyable();
    ~Noncopyable();

private:
    Noncopyable(const Noncopyable& other);
    const Noncopyable& operator=(const Noncopyable& other);
};

class Parent: private Noncopyable
{
public:
    Parent()
    {
        cout<<"Parent()"<<endl;
    }
    Parent(const Parent& other)
    {

    }
   
};
class Child: public Parent
{
    /*
public:
    Child(const Child& other)
    {
    }*/
};
#endif //C_2_NONCOPYABLE_H
