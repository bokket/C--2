//
// Created by bokket on 2021/2/13.
//

#ifndef BST_BST_H
#define BST_BST_H

#include "../BinNode/BinTree.h"
template<typename T>
class BST: public BinTree<T>
{
public:
    virtual BinNodePosi(T) & search(const T & e);
    virtual BinNodePosi(T) insert(const T & e);
    virtual bool remove(const T & e);

protected:
    BinNodePosi(T) _hot;
    BinNodePosi(T) connect34 (BinNodePosi(T) ,BinNodePosi(T) ,BinNodePosi(T)
                              ,BinNodePosi(T) ,BinNodePosi(T) ,BinNodePosi(T) ,BinNodePosi(T));
    BinNodePosi(T) rotateAt (BinNodePosi(T) x);
};


#endif //BST_BST_H
