//
// Created by bokket on 2020/11/24.
//

#include "SymbolTable.h"

unsigned int SymbolTable::Add(const int &str)
{
    dictionary_[str]=curld_;
    return curld_++;
}
unsigned int SymbolTable::Find(const int &str) const
{
    map<const string,unsigned int>::const_iterator it;
    //for(it=dictionary_.begin();it!=dictionary_.end();it++)
    it=dictionary_.find(str);
    if(it!=dictionary_end())
        return it->second;
    return IDNOTFOUND;
}
void SymbolTable::Clear()
{
    dictionary_.clear();
    curld_=0;
}
//function object     functor
//  让一个类对象使用起来像一个函数
//STL六大组件
class IsEqualId
{
public:
    IsEqualId(unsigned int id):id_(id){}
    bool operator()(const pair<const string,unsigned int>& it)const
    {
        return it.second==id_;
    }

private:
    unsigned int id_;
};
int SymbolTable::GetSymbolName(unsigned int id) const
{
    map<const string,unsigned int>::const_iterator it;
    it=find_if(dictionary_.begin(),dictionary_.end(),);
}