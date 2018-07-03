/*
 *  log.cpp
 *  Text log writer
 */

#include "log.h"

#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cstdint>
#include <thread>
#include <sstream>

#if defined ( UNIX )
#include <sys/time.h>
#elif defined ( _MSC_VER )
typedef struct timeval {
    long tv_sec;
    long tv_usec;
} timeval;
#endif

#if defined ( _WIN32 )

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#undef WIN32_LEAN_AND_MEAN

int gettimeofday(struct timeval * tp, struct timezone * tzp) {
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
#endif

Log::Log():
    m_stream(nullptr) {
}

Log::~Log() {
    deinit();
}

Log& Log::instance() {
    static Log log;
    return log;
}

void Log::init(const char* name) {
    deinit();
    m_stream = fopen(name, "wt");
}

void Log::deinit() {
    if (m_stream) {
        fflush(m_stream);
        fclose(m_stream);
    }
}

void Log::debug(const char* section, const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    this->vprintf(section, "DEBUG", fmt, args);
    va_end(args);
}

void Log::warn(const char* section, const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    this->vprintf(section, "WARN", fmt, args);
    va_end(args);
}

void Log::error(const char* section, const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    this->vprintf(section, "ERROR", fmt, args);
    va_end(args);
}

void Log::info(const char* section, const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    this->vprintf(section, "INFO", fmt, args);
    va_end(args);
}

void Log::vprintf(const char* section, const char* level, const char* fmt, va_list args) {
    if (!m_stream)
        return;

    std::stringstream ss;
    ss << std::this_thread::get_id();

    // write timestamp, section and level
    char buffer[30];
    timeval tv;
    time_t curtime;
    gettimeofday(&tv, NULL);
    curtime = tv.tv_sec;
    strftime(buffer, 30, "%m-%d-%Y %T.", localtime(&curtime));
    fprintf(m_stream, "%s%03ld | %8.8s | %16.16s | %5.5s | ", buffer, tv.tv_usec / 1000, ss.str().c_str(), section, level);

    // write entry
    vfprintf(m_stream, fmt, args);
    fprintf(m_stream, "\n");
    fflush(m_stream);
}
