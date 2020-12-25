//
// Created by bokket on 2020/12/24.
//

#include "log.h"

#include <map>
#include <iostream>
#include <functional>
#include <time.h>
#include <cstring>

namespace bokket
{
const char * LogLevel::ToString(LogLevel::Level level)
{

}
LogEventWrap::LogEventWrap(LogEvent::ptr p)
{}
LogEventWrap::~LogEventWrap()
{}
stringstream & LogEventWrap::getStringStream()
{}
void LogEvent::fmt(const char *format, ...)
{}
void LogEvent::fmt(const char *format, va_list vaList)
{
}
LogEvent::LogEvent(shared_ptr <Logger> logger, LogLevel::Level level, const char *file, int32_t line, uint32_t msec,
                   uint32_t thread_id, uint32_t coread_id, uint64_t time)
{}
Logger::Logger(const string &name)
{}
void Logger::addPrint(LogPrint::ptr printer)
{}
void Logger::delPrint(LogPrint::ptr printer)
{}
void Logger::log(LogLevel::Level level, LogEvent::ptr event)
{}
void Logger::debug(LogEvent::ptr event)
{}
void Logger::info(LogEvent::ptr event)
{}
void Logger::warn(LogEvent::ptr event)
{}
void Logger::error(LogEvent::ptr event)
{}
void Logger::fatal(LogEvent::ptr event)
{}
LogPrintFile::LogPrintFile(const string &filename)
{}

void LogPrintFile::log(Logger::ptr logger, LogLevel::Level level, LogEvent::ptr event)
{}

bool LogPrintFile::reopen()
{}
void LogPrintStdout::log(Logger::ptr logger, LogLevel::Level level, LogEvent::ptr event)
{}
LogFmtter::LogFmtter(const string &pattern)
{}
}