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

    void printf(const char* format, ...);
    void vprintf(const char* section, const char* format, va_list args);

private:
    Log();

    FILE* m_stream;
};

#define LOG(fmt, ...) Log::instance().printf(fmt, ##__VA_ARGS__)
