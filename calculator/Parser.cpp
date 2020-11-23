//
// Created by bokket on 2020/11/22.
//

#include "Parser.h"
#include "Scanner.h"
#include "Node.h"
#include <cassert>
Parser::Parser(Scanner &scanner):scanner_(scanner),tree_(0)
{

}
void Parser::Parse()
{
    Expr();
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
    
}
double Parser::Calculate() const
{
    assert(tree_!=NULL);
    return tree_->Calc();
}
