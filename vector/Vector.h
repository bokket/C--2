//
// Created by bokket on 2020/12/14.
//

#ifndef C_2_VECTOR_H
#define C_2_VECTOR_H

typedef int Rank;
#define DEFAULT 3




#include <algorithm>
#include <iostream>
template<typename T>
class Vector
{
public:
    Vector(int c=DEFAULT,int s=0,T v=0)
    {
        _elem=new T[_capacity=c];
        for(_size=0;_size<s;_elem[_size++]=v);
    }
    Vector(T const*A ,Rank lo,Rank hi) { copyFrom(A,lo,hi); }
    Vector(T const*A ,Rank n) { copyFrom(A,0,n); }
    Vector(Vector<T> const& V,Rank lo,Rank hi) { copyFrom(V._elem,lo,hi); }
    Vector(Vector<T> const& V) { copyFrom(V._elem,0,V._size); }
    ~Vector() { delete [] _elem; }

    Rank insert(Rank r,T const& e);
    Rank insert(T const& e) { return insert(_size,e); }

    int Remove(Rank lo,Rank hi);
    T Remove(Rank r);

    Rank find(T const & e,Rank lo,Rank hi) const;

    int deduplicate();
    //int uniquify();

    template<typename VST>
    void traverse(VST&);
public:
    T & operator[] (Rank r) const;
protected:
    void copyFrom(T const * A,Rank lo,Rank hi);

    void expand();
    void shrink();

    Vector<T> & operator=(Vector<T> const &);

    Rank size() const { return _size; }


private:
    Rank _size;
    int _capacity;
    T* _elem;
};


#endif //C_2_VECTOR_H
