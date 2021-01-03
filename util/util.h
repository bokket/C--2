//
// Created by bokket on 2021/1/3.
//

#ifndef C_2_UTIL_H
#define C_2_UTIL_H

#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <stdint.h>

namespace bokket
{

pid_t GetThreadId();
uint32_t GetcoreadId();
}


#endif //C_2_UTIL_H
