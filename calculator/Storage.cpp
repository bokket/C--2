//
// Created by bokket on 2020/11/24.
//

#include "Storage.h"
#include "SymbolTable.h"
#include <cmath>
#include <cassert>
Storage::Storage(SymbolTable &tbl)
{
    AddConstants(tbl);
}
void Storage::AddConstants(SymbolTable &tbl)
{
    unsigned int id=tbl.Add("e");
    AddValue(id,exp(1.0));

    id=tbl.Add("pi");
    //
    AddValue(id,2.0*acos(0.0));
}
void Storage::AddValue(unsigned int id, double val)
{
    cells_.resize(id+1);
    inits_.resize(id+1);
    cells_[id]=val;
    inits_[id]=true;
}
void Storage::Clear()
{
    cells_.clear();
    inits_.clear();
}
bool Storage::IsInit(unsigned int id)const
{
    return id<cells_.size() && inits_[id];
}
void Storage::SetValue(unsigned int id, double val)
{
    assert(id<=cells_.size());
    if(id<cells_.size())
    {
        cells_[id]=val;
        inits_[id]=true;
    }
    else if(id==cells_.size())
    {
        AddValue(id,val);
    }
}
double Storage::GetValue(unsigned int id) const
{
    assert(id<cells_.size());
    return cells_[id];
}