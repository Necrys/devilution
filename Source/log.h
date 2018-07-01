/*
 *  log.cpp
 *  Text log writer
 */

#pragma once

#include <cstdio>
#include <cstdarg>

class Log {
public:
    static Log& instance();

    Log(const Log&) = delete;
    Log(Log&&) = delete;
    Log& operator=(const Log&) = delete;
    ~Log();

    void debug(const char* section, const char* fmt, ...);
    void warn(const char* section, const char* fmt, ...);
    void error(const char* section, const char* fmt, ...);
    void info(const char* section, const char* fmt, ...);

private:
    Log();

    void vprintf(const char* section, const char* level, const char* format, va_list args);

    FILE* m_stream;
};

#define LOG_ERR(section, fmt, ...) Log::instance().error(section, fmt, ##__VA_ARGS__)
#define LOG_WRN(section, fmt, ...) Log::instance().warn(section, fmt, ##__VA_ARGS__)
#define LOG_INF(section, fmt, ...) Log::instance().info(section, fmt, ##__VA_ARGS__)
#if !defined( NDEBUG )
#define LOG_DBG(section, fmt, ...) Log::instance().debug(section, fmt, ##__VA_ARGS__)
#else
#define LOG_DBG(section, fmt, ...)
#endif