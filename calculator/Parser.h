//
// Created by bokket on 2020/11/22.
//

#ifndef CALCULATOR_PARSER_H
#define CALCULATOR_PARSER_H

class Scanner;
class Node;

enum STATUS
{
    STATUS_OK,
    STATUS_ERROR,
    STATUS_QUIT
};

class Parser
{
public:
    Parser(Scanner& scanner);
    void Parse();
    Node* Expr();
    Node* Term();
    Node* Factor();
    double Calculate() const;
private:
    Scanner& scanner_;
    Node* tree_;
    STATUS status_;

};


#endif //CALCULATOR_PARSER_H
