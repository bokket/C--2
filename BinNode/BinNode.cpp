//
// Created by bokket on 2021/2/14.
//

#include "BinNode.h"


template <typename T>
BinNode<T> * BinNode<T>::insertAsLC(const T & e)
{
    return lc=BinNode<T>(e,this);
}

template<typename T>
BinNode<T> * BinNode<T>::insertAsRC(const T & e)
{
    return rc=BinNode<T>(e,this);
}

template <typename T>
BinNode<T> * BinNode<T>::succ()
{
    BinNodePosi(T) s= this;

    if(rc)
    {
        s=rc;
        while(s->lc)
            s=s->lc;
    }
    else
    {
        while( !!(s->parent)  && (s==s->parent->rc) )
            s=s->parent;
    }
    return s;
}

template <typename T>
int BinNode<T>::size()
{
    int s=1;
    if(lc)
        s+=lc->size();
    if(rc)
        s+=rc->size();

    return s;
}


template <typename T>
template <typename VST>
void BinNode<T>::travLevel(VST & visit)
{
    queue<BinNodePosi(T)> Q;
    Q.push(this);

    while(!Q.empty())
    {
        BinNodePosi(T) x=Q.pop();
        visit(x->data);

        if(x->lc)
            Q.push(x->lc);
        if(x->rc)
            Q.push(x->rc);
    }
}


template <typename T>
template <typename VST>
void BinNode<T>::travIn(VST & visit)
{
    travIn_R(this,visit);
}

template <typename T,typename VST>
void travIn_R(BinNodePosi(T) x,VST & visit)
{
    if(!x)
        return;
    travIn_R(x->lc,visit);
    visit(x->data);
    travIn_R(x->rc,visit);
}


template <typename T,typename VST>
static void goAlongLeftBranch(BinNodePosi(T) x,VST& visit,stack<BinNodePosi(T)>& S)
{
    while(x)
    {
        S.push(x);
        x=x->lc;
    }
}

template <typename T,typename VST>
void travIn_l1(BinNodePosi(T) x,VST & visit)
{
    stack<BinNodePosi(T)> S;
    while(true)
    {
        goAlongLeftBranch(x,visit,S);
        if(S.empty())
            break;
        x=S.pop();

        visit(x->data);
        x=x->rc;
    }
}



template <typename T>
template <typename VST>
void BinNode<T>::travPre(VST & visit)
{
    travPre_R(this,visit);
}

template <typename T,typename VST>
void travPre_R(BinNodePosi(T) x,VST & visit)
{
    if(!x)
        return;
    visit(x->data);
    travPre_R(x->lc,visit);
    travPre_R(x->rc,visit);
}

template <typename T,typename VST>
void travPre_l1(BinNodePosi(T) x,VST & visit)
{
    stack<BinNodePosi(T)> S;

    if(x)
        S.push(x);

    while(!S.empty())
    {
        x=S.pop();
        visit(x->data);
        if(x->rc)
            S.push(x->rc);
        if(x->lc)
            S.push(x->lc);
    }
}

template <typename T,typename VST>
static void visitAlongLeftBranch(BinNodePosi(T) x,VST& visit,stack<BinNodePosi(T)>& S)
{
    while(x)
    {
        visit(x->data);
        S.push(x->rc);
        x=x->lc;
    }
}

template <typename T,typename VST>
void travPre_l2(BinNodePosi(T) x,VST & visit)
{
    stack<BinNodePosi(T)> S;
    while(true)
    {
        visitAlongLeftBranch(x,visit,S);
        if(S.empty())
            break;
        x=S.pop();
    }
}