//
// Created by bokket on 2020/11/22.
//

#ifndef CALCULATOR_PARSER_H
#define CALCULATOR_PARSER_H

class Scanner;

class Parser
{
public:
    Parser(Scanner& scanner);
    void Parse();
    double Calculate() const;
private:
    Scanner& scanner_;

};


#endif //CALCULATOR_PARSER_H
