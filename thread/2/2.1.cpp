#include <iostream>
#include <list>
#include <mutex>
#include <algorithm>


using namespace std;


list<int> v;
mutex m;

void f(int n)
{
    lock_guard<mutex> l(m);
    v.emplace_back(n);
}
bool listContains(int n)
{
    lock_guard<mutex> l(m);
    return find(begin(v),end(v),n) != end(v);
}
