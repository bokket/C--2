//
// Created by bokket on 2020/11/24.
//

#ifndef CALCULATOR_STORAGE_H
#define CALCULATOR_STORAGE_H

#include <vector>

class SymbolTable

class Storage
{
    Storage(SymbolTable & tbl):
    ~Storage();
    void Clear();
    void AddConstants(SymbolTable & tbl);
    bool IsInit(unsigned int id)const;
    double GetValue(unsigned int id) const;
    void SetValue(unsigned int id,double val);
    void AddValue(unsigned int id,double val);
private:
    vector<double>cells_;
    vector<bool>inits_;
};


#endif //CALCULATOR_STORAGE_H
