//
// Created by bokket on 2020/12/14.
//

#include "Vector.h"


template<typename T>
void Vector<T>::copyFrom(const T *A, Rank lo, Rank hi)
{
    _elem=new T[ _capacity=2*(hi-lo) ];
    _size=0;

    while (lo<hi)
        _elem[_size++]=A[lo++];
}

