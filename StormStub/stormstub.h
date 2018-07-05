#pragma once

#if defined ( STORMSTUB_LOGGER )
#define SS_DBG(fmt, ...) LOG_DBG(fmt, ##__VA_ARGS__)
#define SS_INF(fmt, ...) LOG_INF(fmt, ##__VA_ARGS__)
#define SS_WRN(fmt, ...) LOG_WRN(fmt, ##__VA_ARGS__)
#define SS_ERR(fmt, ...) LOG_ERR(fmt, ##__VA_ARGS__)
#else
#define SS_DBG(fmt, ...)
#define SS_INF(fmt, ...)
#define SS_WRN(fmt, ...)
#define SS_ERR(fmt, ...)
#endif

#include "reg.h"
#include "vid.h"
#include "draw.h"
#include "net.h"
#include "err.h"
#include "mem.h"
#include "mpq.h"
#include "str.h"

namespace Storm {
    bool StormDestroy();
}
