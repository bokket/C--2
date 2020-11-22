//
// Created by bokket on 2020/11/22.
//

#ifndef CALCULATOR_NODE_H
#define CALCULATOR_NODE_H

class Noncopyable
{
protected:
    Noncopyable(){}
    ~Noncopyable(){}

private:
    Noncopyable(const Noncopyable&);
    const Noncopyable& operator=(const Noncopyable&);
};

class Node: private Noncopyable
{
public:
    virtual double Calc() const =0;
    virtual ~Node();
};
class NumberNode : public Node
{
public:
    NumberNode(double number):number_(number){}
    double Calu() const;

private:
    const double number_;
};
class UnaryNode: public Node
{
public:
    UnaryNode(Node* child):child_(child){}
    ~UnaryNode();
protected:
    Node* const child_;
};
class BinaryNode: public Node
{
public:
    BinaryNode(Node* left,Node* right):left_(left),right_(right){}
    ~BinaryNode();
protected:
    Node* const left_;
    Node* const right_;
};
class AddNode: public BinaryNode
{
public:
    AddNode(Node* left,Node* right):BinaryNode(left,right){}

    double Calc() const;
};
class SubNode: public BinaryNode
{
public:
    SubNode(Node* left,Node* right):BinaryNode(left,right){}

    double Calc() const;
};
class MultiplyNode: public BinaryNode
{
public:
    MultiplyNode(Node* left,Node* right):BinaryNode(left,right){}

    double Calc() const;
};
class DivideNode: public BinaryNode
{
public:
    DivideNode(Node* left,Node* right):BinaryNode(left,right){}

    double Calc() const;
};

class UMinusNode: public UnaryNode
{
public:
    UMinusNode(Node* child):UnaryNode(child){}
    double Calu() const;
};
#endif //CALCULATOR_NODE_H
