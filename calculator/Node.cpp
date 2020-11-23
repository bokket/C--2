//
// Created by bokket on 2020/11/22.
//

#include "Node.h"
#include <cmath>
#include <iostream>
#include <vector>
#include <std>
double NumberNode::Calu() const
{
    return number_;
}

BinaryNode::~BinaryNode()
{
    delete right_;
    delete left_;
}
UnaryNode::~UnaryNode()
{
    delete child_;
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

MultipleNode::~MultipleNode()
{
    vector<Node*>::const_iterator it;
    for(it=childs_.begin();it!=childs_.end();it++)
        delete *it;
}
double SumNode::Calc() const
{
    double result=0.0;
    vector<Node*>::const_iterator childIt=child_begin();
    vector<bool >::const_iterator positivesIt=positives_.begin();

    for(;childIt!=childs_end();childIt++,positivesIt++)
    {
        assert(positivesIt!=positives_.end());
        double val=(*childIt)->Calc();
        if(*positivesIt)
            result+=val;
        else
            result-=val;
    }
    assert(positivesIt==positives_.end());
    return result;
}
double ProductNode::Calc() const
{
    double result=1.0;
    vector<Node*>::const_iterator childIt=child_begin();
    vector<bool >::const_iterator positivesIt=positives_.begin();

    for(;childIt!=childs_end();childIt++,positivesIt++)
    {
        assert(positivesIt!=positives_.end());
        double val=(*childIt)->Calc();
        if(*positivesIt)
            result*=val;
        else if(val!=0.0)
            result/=val;
        else {
            cout<<"Division by zero"<<endl;
            return HUGE_VAL;
        }
    }
    assert(positivesIt==positives_.end());
    return result;
}


