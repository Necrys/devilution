#include "stormstub.h"

#include <log.h>

#ifdef STORMSTUB_USE_STORM
#include <storm.h>
#endif

namespace Storm {
    bool StormDestroy() {
#ifdef STORMSTUB_PASSTHROUGH
        bool res = ::StormDestroy();
        SS_DBG("-> %s", res?"true":"false");
        return res;
#else
        SS_DBG("");
        return true;
#endif
    }
}
