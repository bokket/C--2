//
// Created by bokket on 2020/11/22.
//

#ifndef CALCULATOR_NODE_H
#define CALCULATOR_NODE_H
#include <vector>
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
    virtual bool IsLvalue() const
    {
        return false;
    }
    virtual void Assign(double)
    {
        assert(!"Assgin called incorrectly.");
    }
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

/*
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
*/


class UMinusNode: public UnaryNode
{
public:
    UMinusNode(Node* child):UnaryNode(child){}
    double Calu() const;
};

class MultipleNode: public Node
{
public:
    MultipleNode(Node* node)
    {
        AppendChild(node, true);
    }
    void AppendChild(Node* node,bool positive)
    {
        childs_.push_back(node);
        positives_.push_back(positive);
    }
    ~MultipleNode();
protected:
    vector<Node*> childs_;
    vector<bool> positives_;
};
class SumNode: public MultipleNode
{
public:
    SumNode(Node* node)
        :MultipleNode(node){}
    double Calc() const;
};
class ProductNode: public MultipleNode
{
public:
    ProductNode(Node* node)
        :MultipleNode(node){}
    double Calc() const;
};
class VariableNode: public Node
{
public:
    VariableNode(unsigned int id,Stotage & storage)
        :id_(id),storage_(storage){}
    double Calc() const;
    bool IsLvalue() const;
    void Assign(double val);
private:
    const unsigned int id_;
    Storage& storage_;
};

class AssignNode: public BinaryNode
{
public:
    AddNode(Node* left,Node* right):BinaryNode(left,right){}

    double Calc() const;
};
#endif //CALCULATOR_NODE_H
