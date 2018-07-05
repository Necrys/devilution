#include "mem.h"
#include "stormstub.h"

#include <log.h>

#ifdef STORMSTUB_USE_STORM
#include <storm.h>
#endif

#include <cassert>

namespace Storm {
    using Byte = unsigned char;

    void* SMemAlloc(size_t amount, char* logfilename, int logline, char defaultValue) {
        LOG_DBG("amount: %u, logfilename: \"%s\", logline: %d, defaultValue: 0x%X", amount, logfilename, logline, defaultValue);
#ifdef STORMSTUB_PASSTHROUGH
        return ::SMemAlloc(amount, logfilename, logline, defaultValue);
#else
        assert(amount > 0);
        // TODO: use some memory allocator, like tlsf
        Byte* mem = new Byte[amount];
        memset(mem, defaultValue, amount);
        return reinterpret_cast<void*>(mem);
#endif
    }

    BOOL SMemFree(void* location, char* logfilename, int logline, char defaultValue) {
        //LOG_DBG("location: 0x%p, logfilename: \"%s\", logline: %d, defaultValue: 0x%X", location, logfilename, logline, defaultValue);
#ifdef STORMSTUB_PASSTHROUGH
        return ::SMemFree(location, logfilename, logline, defaultValue);
#else
        assert(location);
        Byte* mem = reinterpret_cast<Byte*>(location);
        delete[] location;
        return TRUE;
#endif
    }
}
