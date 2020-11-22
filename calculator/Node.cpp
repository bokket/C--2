//
// Created by bokket on 2020/11/22.
//

#include "Node.h"
#include <cmath>
#include <iostream>

double NumberNode::Calu() const
{
    return number_;
}

BinaryNode::~BinaryNode()
{
    delete right_;
    delete left_;
}


double AddNode::Calc() const
{
    return left_->Calc()+right_->Calc();
}
double SubNode::Calc() const
{
    return left_->Calc()-right_->Calc();
}
double MultiplyNode::Calc() const
{
    return left_->Calc()*right_->Calc();
}
double DivideNode::Calc() const
{
    double divsion=right_->Calc();
    if(divsion!=0.0)
            return left_->Calc()/divsion;
    else
    {
        cout<<"Error Divison by zero"<<endl;
        return HUGE_VAL;
    }
}


double UMinusNode::Calu() const
{
    return - ( child_->Calc() );
}
