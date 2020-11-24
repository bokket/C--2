//
// Created by bokket on 2020/11/24.
//

#ifndef CALCULATOR_SYMBOLTABLE_H
#define CALCULATOR_SYMBOLTABLE_H

#include <map>
#include <string>
class SymbolTable
{
    enum  {IDNOTFOUND = -1};
public:
    SymbolTable();
    unsigned int Add(const string & str);
    unsigned int Find(const string & str) const;
    void Clear();
    string GetSymbolName(unsigned int id) const;

private:
    map<const string,unsigned int>dictionary_;
    unsigned int curld_;
};


#endif //CALCULATOR_SYMBOLTABLE_H
