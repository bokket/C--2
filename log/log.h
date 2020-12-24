//
// Created by bokket on 2020/12/24.
//

#ifndef C_2_LOG_H
#define C_2_LOG_H

#include <string>
#include <memory>
#include <list>
#include <iostream>
#include <vector>
#include <stdarg.h>
#include <map>
#include <fstream>
#include <sstream>
using namespace std;

#define BOKKET_LOG_LEVEL(logger,level) \
if()





namespace bokket
{
class Logger;


class LogLevel
{
public:
    enum Level
    {
        UNKNOW=0,
        DEBUG=1,
        INFO=2,
        WARN=3,
        ERROR=4,
        FATAL=5
    };

    static const char* ToString(LogLevel::Level level);
};


typedef shared_ptr<LogEvent> ptr;

class LogEvent
{
public:
    LogEvent(shared_ptr<Logger> logger,LogLevel::Level level
             ,const char* file,int32_t line,uint32_t msec
             ,uint32_t thread_id,uint32_t coread_id,uint64_t time);

    const char* getFile() const { return m_file; }
    int32_t getLine() const { return m_line; }
    uint32_t getMsec() const { return m_msec; }
    uint32_t getThreadId() const { return m_threadId; }
    uint32_t getCoreadId() const { return m_coreadId; }
    uint64_t getTime() const { return m_time; }
    string getContent() const { return m_stream.str(); }
    shared_ptr<Logger> getLogger() const { return m_logger; }
    LogLevel::Level getLevel() const { return m_level; }

    stringstream & getStringStream() { return m_stream; }

    void fmt(const char* format,...);
    void fmt(const char* format,va_list vaList);

private:
    const char* m_file=NULL;
    int32_t m_line=0;
    uint32_t m_msec=0;
    uint32_t m_threadId=0;
    uint32_t m_coreadId=0;
    uint64_t m_time=0;

    stringstream m_stream;
    shared_ptr<Logger> m_logger;
    LogLevel::Level m_level;
};


}



#endif //C_2_LOG_H
