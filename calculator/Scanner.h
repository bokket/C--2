//
// Created by bokket on 2020/11/22.
//

#ifndef CALCULATOR_SCANNER_H
#define CALCULATOR_SCANNER_H

#include <string>
class Scanner
{
public:
    Scanner(const string& buf);
    ~Scanner();
    void Accept();
    double Number() const;
    EToken Token()  const;

private:
    void SkipWhite();
    const string buf_;
    unsigned int curPos_;
    EToken token_;
    double number_;
};


#endif //CALCULATOR_SCANNER_H
