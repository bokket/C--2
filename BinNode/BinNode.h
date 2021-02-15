//
// Created by bokket on 2021/2/14.
//

#ifndef C_2_BINNODE_H
#define C_2_BINNODE_H


#include <memory>
#include <stack>
#include <queue>
#define BinNodePosi(T) BinNode<T>*
#define stature(p) ((p) ? p->height : -1 )
typedef enum
{ RB_RED
  ,RB_BLACK
}RBColor;

using namespace std;


template <typename T>
struct BinNode
{
public:
    BinNode():
            parent(nullptr),lc(nullptr),rc(nullptr)
           ,height(0),npl(1),color(RB_RED)
    {}

    BinNode(T e,BinNodePosi(T) p= nullptr,BinNodePosi(T) lc= nullptr,BinNodePosi(T) rc= nullptr,
            int h=0,int l=1,RBColor c=RB_RED):
            data(e),parent(p),lc(lc),rc(rc)
            ,height(h),npl(l),color(c)
    {}

public:
    int size();
    BinNodePosi(T) insertAsLC(T const&);
    BinNodePosi(T) insertAsRC(T const&);
    BinNodePosi(T) succ();

public:
    template<typename VST>
    void travLevel(VST& );

    template <typename VST>
    void travPre ( VST& visit); //子树先序遍历

    template <typename VST>
    void travIn ( VST& ); //子树中序遍历

    //template <typename VST>
    //void travPost ( VST& ); //子树后序遍历

public:
    bool operator<(BinNode const & bn)
    {
        return data<bn.data;
    }
    bool operator==(BinNode const & bn)
    {
        return data==bn.data;
    }
private:
    T data;
    int height;
    int npl; // Null Path Length
    RBColor color;
    BinNodePosi(T) parent;
    BinNodePosi(T) lc;
    BinNodePosi(T) rc;
};



#endif //C_2_BINNODE_H
