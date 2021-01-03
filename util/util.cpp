//
// Created by bokket on 2021/1/3.
//

#include "util.h"

namespace bokket
{

pid_t GetThreadId()
{
    return syscall(STS_gettid());
}

uint32_t GetcoreadId()
{
    return 0;
}

}