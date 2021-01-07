//
// Created by bokket on 2021/1/7.
//

#include "logger.h"


const char* LevelString[5]={"DEBUG","INFO","WARNING","ERROR","FATAL"};



LogBuffer::LogBuffer(int size)
                    :bufsize(size)
                    ,usedlen(0)
                    ,state(BufState::FREE)
{
    logbuffer=new char[bufsize];
    if(logbuffer== nullptr)
        std::cerr<<"memory alloc fail:new char"<<std::endl;
}

LogBuffer::~LogBuffer()
{
    if(logbuffer!= nullptr)
        delete []logbuffer;
}


void LogBuffer::append(const char *logline, int len)
{
    memcpy(logbuffer+usedlen,logline,len);
    usedlen+=len;
}

void LogBuffer::FlushToFile(FILE *fp)
{
    uint32_t wt_len=fwrite(logbuffer,1,usedlen,fp);
    if(wt_len!=usedlen)
        std::cerr<<"fwrite fail"<<std::endl;

    usedlen=0;
    fflush(fp);
}
