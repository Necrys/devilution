#include "str.h"
#include "stormstub.h"

#include <log.h>

#ifdef STORMSTUB_USE_STORM
#include <storm.h>
#endif

#include <cassert>

namespace Storm {
    int SStrCopy(char *dest, const char *src, int max_length) {
#ifdef STORMSTUB_PASSTHROUGH
        int res = ::SStrCopy(dest, src, max_length);
        SS_DBG("dest: 0x%p, src: 0x%p(\"%s\"), max_length: %d -> %d", dest, src, src, max_length, res);
        return res;
#else
        SS_DBG("dest: 0x%p, src: 0x%p(\"%s\"), max_length: %d", dest, src, src, max_length);
        assert(dest && src && max_length > 0);
        const char* p = src;
        char* d = dest;
        int count = 0;

        while (*p != 0) {
            assert(int(d - dest) < max_length);
            assert(int(p - src) < max_length);
            *d = *p;
            ++count;

            if (count >= max_length) {
                assert(int(d - dest) <= max_length);
                *d = 0;
                return (int)(d - dest);
            }

            ++d;
            ++p;
        }

        assert(int(d - dest) < max_length);
        *d = 0;
        return (int)(d - dest);
#endif
    }
}