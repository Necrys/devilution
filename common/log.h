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

    void init(const char* name);
    void deinit();

    void debug(const char* section, const char* fmt, ...);
    void warn(const char* section, const char* fmt, ...);
    void error(const char* section, const char* fmt, ...);
    void info(const char* section, const char* fmt, ...);

private:
    Log();

    void vprintf(const char* section, const char* level, const char* format, va_list args);

    FILE* m_stream;
};

#if defined (WIN32) || defined (_WIN32)
#define __FILE_PATH_DELIM_CHAR__ '\\'
#else
#define __FILE_PATH_DELIM_CHAR__ '/'
#endif

#define __FILENAME__ (strrchr(__FILE__, __FILE_PATH_DELIM_CHAR__) ? strrchr(__FILE__, __FILE_PATH_DELIM_CHAR__) + 1 : __FILE__)

#define LOG_ERR(fmt, ...) Log::instance().error(__FILENAME__, __FUNCTION__ "() " fmt, ##__VA_ARGS__)
#define LOG_WRN(fmt, ...) Log::instance().warn(__FILENAME__, __FUNCTION__ "() " fmt, ##__VA_ARGS__)
#define LOG_INF(fmt, ...) Log::instance().info(__FILENAME__, __FUNCTION__ "() " fmt, ##__VA_ARGS__)
#if !defined( NDEBUG )
#define LOG_DBG(fmt, ...) Log::instance().debug(__FILENAME__, __FUNCTION__ "() " fmt, ##__VA_ARGS__)
#else
#define LOG_DBG(fmt, ...)
#endif

#define PLOG_ERR(fmt, ...) if (g_pLog) g_pLog->error(__FILENAME__, fmt, ##__VA_ARGS__)
#define PLOG_WRN(fmt, ...) if (g_pLog) g_pLog->warn(__FILENAME__, fmt, ##__VA_ARGS__)
#define PLOG_INF(fmt, ...) if (g_pLog) g_pLog->info(__FILENAME__, fmt, ##__VA_ARGS__)
#if !defined( NDEBUG )
#define PLOG_DBG(fmt, ...) if (g_pLog) g_pLog->debug(__FILENAME__, fmt, ##__VA_ARGS__)
#else
#define LOG_DBG(fmt, ...)
#endif