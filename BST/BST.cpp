//
// Created by bokket on 2021/2/13.
//

#include "BST.h"


template<typename T>
BinNode<T> * BST<T>::insert(const T &e)
{
    BinNodePosi(T) &x=search(e);

    if(x)
        return x;

    x=new BinNode<T>(e,_hot);

    _size++;
    updateHeightAbove(x);
    return x;
}

template <typename T>
BinNode<T> * & BST<T>::search(const T &e)
{
    return searchIn(_root,e,_hot= nullptr);
}

template <typename T>
static BinNode<T> *& BST<T>::searchIn(BinNodePosi(T) & v,const T &e,BinNodePosi(T) &hot)
{
    if(!v || (e==v->data) )
        return v;

    hot=v;
    return searchIn( ((e<v->data) ? v->lc : v->rc) , e,hot );
}