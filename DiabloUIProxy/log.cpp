#include "log.h"

#define DIABLOUI_EXPORTS
#include "diabloui.h"

#define WIN32_LEAN_AND_MEAN
#include "Windows.h"
#undef WIN32_LEAN_AND_MEAN

#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cstdint>

Log::Log() {
    m_stream = fopen("diabloui_proxy_log.txt", "wt");
}

Log::~Log() {
    fflush(m_stream);
    fclose(m_stream);
}

Log& Log::instance() {
    static Log log;
    return log;
}

typedef struct timeval {
    long tv_sec;
    long tv_usec;
} timeval;

int gettimeofday(struct timeval * tp, struct timezone * tzp)
{
    // Note: some broken versions only have 8 trailing zero's, the correct epoch has 9 trailing zero's
    // This magic number is the number of 100 nanosecond intervals since January 1, 1601 (UTC)
    // until 00:00:00 January 1, 1970 
    static const uint64_t EPOCH = ((uint64_t)116444736000000000ULL);

    SYSTEMTIME  system_time;
    FILETIME    file_time;
    uint64_t    time;

    GetSystemTime(&system_time);
    SystemTimeToFileTime(&system_time, &file_time);
    time = ((uint64_t)file_time.dwLowDateTime);
    time += ((uint64_t)file_time.dwHighDateTime) << 32;

    tp->tv_sec = (long)((time - EPOCH) / 10000000L);
    tp->tv_usec = (long)(system_time.wMilliseconds * 1000);
    return 0;
}


void Log::printf(const char* format, ...) {
    va_list args;
    va_start(args, format);
    this->vprintf("UI", format, args);
    va_end(args);
}

void Log::vprintf(const char* section, const char* format, va_list args) {
    if (!m_stream)
        return;

    // write timestamp
    char buffer[30];
    timeval tv;
    time_t curtime;
    gettimeofday(&tv, NULL);
    curtime = tv.tv_sec;
    strftime(buffer, 30, "%m-%d-%Y %T.", localtime(&curtime));
    fprintf(m_stream, "%s%03ld |", buffer, tv.tv_usec / 1000);

    // write entry
    fprintf(m_stream, "%4.4s|", section);
    vfprintf(m_stream, format, args);
    fprintf(m_stream, "\n");
    fflush(m_stream);
}

DIABLOUI_API void __stdcall UiLog(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    Log::instance().vprintf("GAME", fmt, args);
    va_end(args);
}