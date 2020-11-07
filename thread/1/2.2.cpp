#include <iostream>
#include <thread>

using namespace std;

thread::id masterThread;
void f()
{
    if(this_thread::get_id()==masterThread)
    {
        doMasterThreadWork();
    }
    doCommonWork();
}