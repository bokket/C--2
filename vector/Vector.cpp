//
// Created by bokket on 2020/12/14.
//

#include "Vector.h"
using namespace std;

template<typename T>
void Vector<T>::copyFrom(const T *A, Rank lo, Rank hi)
{
    _elem=new T[ _capacity=2*(hi-lo) ];
    _size=0;

    while (lo<hi)
        _elem[_size++]=A[lo++];
}


template <typename T>
void Vector<T>::expand()
{
    if(_size<_capacity)
        return;
    _capacity=max(_capacity,DEFAULT);

    T* oldElem=_elem;
    _elem=new T[_capacity=_capacity<<1];

    for(int i=0;i<_size;i++)
        _elem[i]=oldElem[i];

    delete [] oldElem;
}

template <typename T>
void Vector<T>::shrink()
{
    if(_capacity< DEFAULT<<1)
        return;
    if(_size<<2 >_capacity)
        return;
    T* oldElem=_elem;

    _elem=new T[_capacity>>=1];

    for(int i=0;i<_size;i++)
        _elem[i]=oldElem[i];


    delete [] oldElem;
}

template <typename T>
Rank Vector<T>::insert(Rank r, const T &e)
{
    expand();
    for(int i=_size;i>r;i--)
        _elem[i]=_elem[i-1];

    _elem[r]=e;
    _size++;
    return r;
}

template <typename T>
int Vector<T>::Remove(Rank lo, Rank hi)
{
    if(lo==hi)
        return 0;

    while(hi<_size)
        _elem[lo++]=_elem[hi++];

    _size=lo;
    shrink();

    return hi-lo;
}

template <typename T>
T Vector<T>::Remove(Rank r)
{
    T e=_elem[r];
    Remove(r,r+1);
    return e;
}


template <typename T>
Rank Vector<T>::find(const T &e, Rank lo, Rank hi) const
{
    while( (lo<hi--) && (e!=_elem[hi]) );

    return hi;
}


template <typename T>
int Vector<T>::deduplicate()
{
    int oldSize=_size;
    Rank i=1;

    while(i<_size)
    {
        find(_elem[i],0,i)<0 ? i++ : Remove(i);
    }

    return oldSize-_size;
}

template<typename T>
int Vector<T>::uniquify()
{
    Rank i=0;
    Rank j=0;

    while(++j<_size)
    {
        if(_elem[i]!=_elem[j])
            _elem[++i]=_elem[j];
    }
    _size=++i;
    shrink();

    return j-i;
}

template<typename T>
Rank Vector<T>::binSearch(T *A, const T &e, Rank lo, Rank hi)
{
    while(lo<hi)
    {
        int mid=(lo+hi)>>1;
        if(e<A[mid])
            hi=mid;
        if(A[mid]<e)
            lo=mid+1;
        if(A[mid]==e)
            return mid;
    }
    return -1;
}

template <typename T>
template <typename VST>
void Vector<T>::traverse(VST & visit)
{
    for(int i=0;i<_size;i++)
        visit(_elem[i]);
}

template <typename T>
T & Vector<T>::operator[](Rank r) const
{
    return _elem[r];
}

template<typename T>
Vector<T> & Vector<T>::operator=(const Vector<T> & V)
{
    delete [] _elem;
    copyFrom(V._elem,0,V.size());
    return *this;
}

int main()
{
    Vector<int> t1;
    t1.insert(2);
    t1.insert(1);
    t1.insert(1);
    t1.insert(3);
    t1.insert(4);
    //t1.sort();
    cout <<  t1[2] << endl;
    return 0;
}