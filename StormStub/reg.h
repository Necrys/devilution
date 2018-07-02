#pragma once

#include "types.h"

namespace Storm {
    BOOL SRegLoadValue(const char *keyname, const char *valuename, BYTE flags, int *value);
    BOOL SRegSaveValue(const char *keyname, const char *valuename, BYTE flags, DWORD result);
    BOOL SRegLoadString(const char *keyname, const char *valuename, BYTE flags, char *buffer, size_t buffersize);
    BOOL SRegSaveString(const char *keyname, const char *valuename, BYTE flags, char *string);
    BOOL SRegLoadData(const char *keyname, const char *valuename, int size, LPBYTE lpData, BYTE flags, LPDWORD lpcbData);
    BOOL SRegSaveData(const char *keyname, const char *valuename, int size, LPBYTE lpData, DWORD cbData);
}
