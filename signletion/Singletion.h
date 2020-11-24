//
// Created by bokket on 2020/11/24.
//

#ifndef C_2_SINGLETION_H
#define C_2_SINGLETION_H
#include <iostream>
#include <memory>

using namespace std;
class Singletion
{
public:
    static Singletion* GetInstance()
    {
        if(!instance_.get())
        {
            instance_=shared_ptr<Singletion>(new Singletion);
        }
        return instance_.get();
    }
    ~Singletion()
    {
        cout<<"~Signletion"<<endl;
    }
private:
    Singletion(const Singletion& other);
    Singletion & operator=(const Singletion& other);
    Singletion()
    {
        cout<<"Singletion"<<endl;
    }
    static shared_ptr<Singletion> instance_;
};
shared_ptr<Singletion> Singletion::instance_;

class Noncopyable
{
protected:
    Noncopyable();
    ~Noncopyable();

private:
    Noncopyable(const Noncopyable& other);
    const Noncopyable& operator=(const Noncopyable& other);
};

#endif //C_2_SINGLETION_H
