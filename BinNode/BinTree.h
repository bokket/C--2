//
// Created by bokket on 2021/2/15.
//

#ifndef C_2_BINTREE_H
#define C_2_BINTREE_H

#include "BinNode.h"
using namespace std;


template<typename T>
class BinTree
{
public:
    int size() const { return _size; }
    bool empty() const { return !_root; }
    BinNodePosi(T) root() const { return _root; }

    BinNodePosi(T) insertAsRC(BinNodePosi(T) x,T const &e);
    BinNodePosi(T) insertAsRL(BinNodePosi(T) x,T const &e);

public:
    template<typename VSL>
    void traverLevel(VST & visit)
    {
        if(_root)
            _root->travLevel(visit);
    }

    template<typename VSL>
    void travPre(VST & visit)
    {
        if(_root)
            _root->travPre(visit);
    }
protected:
    virtual int updateHeight(BinNodePosi(T) x);
    void updateHeightAbove(BinNodePosi(T) x);
private:
    int _size;
    BinNodePosi(T) _root;
};


#endif //C_2_BINTREE_H
