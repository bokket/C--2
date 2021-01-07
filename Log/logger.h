//
// Created by bokket on 2021/1/7.
//

#ifndef C_2_LOGGER_H
#define C_2_LOGGER_H
#include <sys/time.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdarg.h>
#include <memory>


#include <iostream>
#include <queue>
#include <map>
#include <unordered_map>
#include <thread>
#include <mutex>
#include <condition_variable>

#define BUFSIZE 8*1024*1024
#define LOGLINESIZE 4096
#define MEM_LIMIT 512*1024*1024

class Logger;

#define LOG_INIT(logger,level) \
        do{                    \
            Logger::GetInstance()->Init(logger,level);                       \
        }while(0)              \



#define LOG(level,fmt,...)     \
        do{                    \
            if(Logger::GetInstance()->GetLevel()<=level) \
            {                  \
                Logger::GetInstance()->fmt(level,__FILE__,__LINE__,__FUNCTION__,fmt,__VA_ARGS__)\
            }\
        }while(0)               \







enum LoggerLevel
{
    DEBUG=0,
    INFO,
    WARNING,
    ERROR,
    FATAL
};

class LogBuffer
{
public:
    enum BufState
    {
        FREE=0,
        FLUSH=1
    };
public:
    LogBuffer(int size);
    ~LogBuffer();
    int GetusedLen() const { return usedlen; }

    int GetAvailLen() const { return bufsize-usedlen; }

    int GetState() const { return state; }
    void SetState(BufState s) { state=s; }

public:
    void append(const char* logline,int len);
    void FlushToFile(FILE* fp);

private:
    char* logbuffer;
    uint32_t bufsize;
    uint32_t usedlen;

    int state;
};

class Logger
{
private:
    int level;
    FILE* fp;

    map<std::thread::id,LogBuffer *> threadbufMap;

    std::mutex mutex;

    int buftotalNum;

    std::mutex flushMutex;

    std::condition_variable flushCond;

    std::queue<LogBuffer* > flushbufQueue;

    std::mutex freeMutex;

    queue<LogBuffer* > freebufQueue;

    std::thread flushthread;

    bool start;

    char save_ymdhms[64];

public:
    Logger();
    ~Logger();

    static Logger* GetInstance()
    {
        static Logger logger;
        return &logger;
    }
    void Init(const char* logdir,LoggerLevel level);

    int GetLevel() const { return level; }

    void fmt(int level,const char* file,int line,const char* func,const char* fmt,...);

    void Flush();
};


#endif //C_2_LOGGER_H
