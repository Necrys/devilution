#pragma once

#include "types.h"

#include <cstdint>

namespace Storm {
    BOOL SFileOpenArchive(LPCSTR szMpqName, DWORD dwPriority, DWORD dwFlags, HANDLE* phMpq);
    BOOL SFileCloseArchive(HANDLE hArchive);

    BOOL SFileOpenFile(LPCSTR filename, HANDLE* phFile);
    BOOL SFileOpenFileEx(HANDLE hMpq, LPCSTR szFileName, DWORD dwSearchScope, HANDLE* phFile);
    BOOL SFileReadFile(HANDLE hFile, void* buffer, DWORD nNumberOfBytesToRead, DWORD* read, LONG lpDistanceToMoveHigh);
    BOOL SFileCloseFile(HANDLE hFile);

    BOOL SFileGetFileArchive(HANDLE hFile, HANDLE archive);
    LONG SFileGetFileSize(HANDLE hFile, LPDWORD lpFileSizeHigh);
    BOOL SFileSetBasePath(LPCSTR path);
    LONG SFileSetFilePointer(HANDLE hFile, LONG lDistanceToMove, PLONG lplDistanceToMoveHigh, DWORD dwMoveMethod);

    BOOL SFileDdaBeginEx(HANDLE directsound, DWORD flags, DWORD mask, uint32_t lDistanceToMove, int32_t volume, int a6, int a7);
    BOOL SFileDdaDestroy();
    BOOL SFileDdaEnd(HANDLE directsound);
    BOOL SFileDdaGetPos(HANDLE directsound, int a2, int a3);
    BOOL SFileDdaInitialize(HANDLE directsound);
    BOOL SFileDdaSetVolume(HANDLE directsound, int bigvolume, int volume);
}
