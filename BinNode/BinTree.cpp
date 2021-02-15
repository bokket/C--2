//
// Created by bokket on 2021/2/15.
//

#include "BinTree.h"

template <typename T>
int BinTree<T>::updateHeight(BinNode<T> *x)
{
    return x->height=1+max(stature(x->lc),stature(x->rc));
}

template<typename T>
void BinTree<T>::updateHeightAbove(BinNode<T> *x)
{
    while(x)
    {
        updateHeight(x);
        x=x->parent;
    }
}

template <typename T>
BinNode<T> * BinTree<T>::insertAsRC(BinNode<T> *x, const T &e)
{
    _size++;
    x->insertAsRC(e);
    updateHeightAbove(x);
    return x->rc;
}


template <typename T>
BinNode<T> * BinTree<T>::insertAsLC(BinNode<T> *x, const T &e)
{
    _size++;
    x->insertAsLC(e);
    updateHeightAbove(x);
    return x->lc;
}