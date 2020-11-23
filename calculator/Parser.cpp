//
// Created by bokket on 2020/11/22.
//

#include "Parser.h"
#include "Scanner.h"
#include "Node.h"
#include <cassert>
#include <iostream>
using namespace std;

Parser::Parser(Scanner &scanner):scanner_(scanner),tree_(0)
{

}
void Parser::Parse()
{
    tree_=Expr();
}
Node* Parser::Expr()
{
    Node* node=Term();
    EToken token=scanner_.Token();
    if(token==TOKEN_PLUS)
    {
        scanner_.Accept();
        node* nodeRight=Expr();
        node=new AddNode(node,nodeRight);
    }
    else if(token==TOKEN_MINUS)
    {
        scanner_.Accept();
        node* nodeRight=Expr();
        node=new SubNode(node,nodeRight);
    }
    return node;
}
Node* Parser::Term()
{
    Node* node=Factor();
    EToken token=scanner_.Token();
    if(token==TOKEN_MULTIPLY)
    {
        scanner_.Accept();
        node* nodeRight=Term();
        node=new MultiplyNode(node,nodeRight);
    }
    else if(token==TOKEN_DIVIDE)
    {
        scanner_.Accept();
        node* nodeRight=Term();
        node=new DivideNode(node,nodeRight);
    }
    return node;
}
Node* Parser::Factor()
{
    Node* node;
    EToken token=scanner_.Token();
    if(token==TOKEN_LPARENTHESIS)
    {
        scanner_.Accept();//接受左括号
        node=Expr();
        if(scanner_.Token()==TOKEN_RPARENTHESIS)
        {
            scanner_.Accept();
        }
        else
        {
            status_=STATUS_ERROR;
            //Tode:抛出异常
            cout<<"missing parenthesis"<<endl;
            node=0;//等于空指针
        }
    }
    else if(token==TOKEN_NUMBER)
    {
        node=new NumberNode(scanner_.Number());
        scanner_.Accept();
    }
    else if(token==TOKEN_MINUS)
    {
        scanner_.Accept();//接受符号
        node = new UMinusNode(Factor());
    }
    else 
    {
        status_=STATUS_ERROR;
        cout<<"not a vavild expression"<<endl;
    }
    return node;
}
double Parser::Calculate() const
{
    assert(tree_!=NULL);
    return tree_->Calc();
}
