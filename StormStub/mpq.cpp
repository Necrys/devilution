#include "mpq.h"
#include "stormstub.h"

#include <log.h>

#ifdef STORMSTUB_USE_STORM
#include <storm.h>
#endif

namespace Storm {
    BOOL SFileOpenArchive(LPCSTR szMpqName, DWORD dwPriority, DWORD dwFlags, HANDLE* phMpq) {
#ifdef STORMSTUB_PASSTHROUGH
        BOOL result = ::SFileOpenArchive(szMpqName, dwPriority, dwFlags, phMpq);
        SS_DBG("szMpqName: \"%s\", dwPriority: %lu, dwFlags: %lu, phMpq: 0x%x -> %d", szMpqName, dwPriority, dwFlags, *phMpq, result);
        return result;
#else
        SS_DBG("szMpqName: \"%s\", dwPriority: %lu, dwFlags: %lu", szMpqName, dwPriority, dwFlags);
        return ::SFileOpenArchive(szMpqName, dwPriority, dwFlags, phMpq);
#endif
    }
    
    BOOL SFileCloseArchive(HANDLE hArchive) {
        SS_DBG("hArchive: 0x%x", hArchive);
#ifdef STORMSTUB_PASSTHROUGH
        return ::SFileCloseArchive(hArchive);
#else
        return ::SFileCloseArchive(hArchive);
#endif
    }

    BOOL SFileOpenFile(LPCSTR filename, HANDLE *phFile) {
#ifdef STORMSTUB_PASSTHROUGH
        BOOL result = ::SFileOpenFile(filename, phFile);
        SS_DBG("filename: \"%s\", phFile: 0x%x -> %d", filename, phFile, result);
        return result;
#else
        SS_DBG("filename: \"%s\"", filename);
        BOOL result = ::SFileOpenFile(filename, phFile);
        setLastError(::SErrGetLastError());
        return result;
#endif
    }
    
    BOOL SFileOpenFileEx(HANDLE hMpq, LPCSTR szFileName, DWORD dwSearchScope, HANDLE *phFile) {
#ifdef STORMSTUB_PASSTHROUGH
        BOOL result = ::SFileOpenFileEx(hMpq, szFileName, dwSearchScope, phFile);
        SS_DBG("hMpq: 0x%x, szFileName: \"%s\", dwSearchScope: %lu, phFile: 0x%x -> %d", hMpq, szFileName, dwSearchScope, *phFile, result);
        return result;
#else
        SS_DBG("hMpq: 0x%x, szFileName: \"%s\", dwSearchScope: %lu", hMpq, szFileName, dwSearchScope);
        return ::SFileOpenFileEx(hMpq, szFileName, dwSearchScope, phFile);
#endif
    }
    
    BOOL SFileReadFile(HANDLE hFile, void *buffer, DWORD nNumberOfBytesToRead, DWORD *read, LONG lpDistanceToMoveHigh) {
#ifdef STORMSTUB_PASSTHROUGH
        BOOL result = ::SFileReadFile(hFile, buffer, nNumberOfBytesToRead, read, lpDistanceToMoveHigh);
        SS_DBG("hFile: 0x%x, nNumberOfBytesToRead: %lu, read: %lu, lpDistanceToMoveHigh: %d -> %d", hFile, nNumberOfBytesToRead, *read, lpDistanceToMoveHigh, result);
        return result;
#else
        SS_DBG("hFile: 0x%x, nNumberOfBytesToRead: %lu, read: %lu, lpDistanceToMoveHigh: %d", hFile, nNumberOfBytesToRead, *read, lpDistanceToMoveHigh);
        return ::SFileReadFile(hFile, buffer, nNumberOfBytesToRead, read, lpDistanceToMoveHigh);
#endif
    }
    
    BOOL SFileCloseFile(HANDLE hFile) {
        SS_DBG("hFile: 0x%x", hFile);
#ifdef STORMSTUB_PASSTHROUGH
        return ::SFileCloseFile(hFile);
#else
        return ::SFileCloseFile(hFile);
#endif
    }

    BOOL SFileGetFileArchive(HANDLE hFile, HANDLE archive) {
        SS_DBG("hFile: 0x%x, archive: 0x%x", hFile, archive);
#ifdef STORMSTUB_PASSTHROUGH
        return ::SFileGetFileArchive(hFile, archive);
#else
        return ::SFileGetFileArchive(hFile, archive);
#endif
    }
    
    LONG SFileGetFileSize(HANDLE hFile, LPDWORD lpFileSizeHigh) {
#ifdef STORMSTUB_PASSTHROUGH
        LONG result = ::SFileGetFileSize(hFile, lpFileSizeHigh);
        if (lpFileSizeHigh)
            SS_DBG("hFile: 0x%p, lpFileSizeHigh: %lu -> %l", hFile, *lpFileSizeHigh, result);
        else
            SS_DBG("hFile: 0x%p -> %l", hFile, result);
        return result;
#else
        if (lpFileSizeHigh)
            SS_DBG("hFile: 0x%p, lpFileSizeHigh: %lu", hFile, *lpFileSizeHigh);
        else
            SS_DBG("hFile: 0x%p", hFile);
        return ::SFileGetFileSize(hFile, lpFileSizeHigh);
#endif
    }
    
    BOOL SFileSetBasePath(LPCSTR path) {
        SS_DBG("path: %s", path);
#ifdef STORMSTUB_PASSTHROUGH
        return ::SFileSetBasePath(path);
#else
        return ::SFileSetBasePath(path);
#endif
    }
    
    LONG SFileSetFilePointer(HANDLE hFile, LONG lDistanceToMove, PLONG lplDistanceToMoveHigh, DWORD dwMoveMethod) {
#ifdef STORMSTUB_PASSTHROUGH
        LONG result = ::SFileSetFilePointer(hFile, lDistanceToMove, lplDistanceToMoveHigh, dwMoveMethod);
        SS_DBG("hFile: 0x%x, lDistanceToMove: %d, lplDistanceToMoveHigh: %d, dwMoveMethod: %lu -> %d", hFile, lDistanceToMove, lplDistanceToMoveHigh, dwMoveMethod, result);
        return result;
#else
        SS_DBG("hFile: 0x%x, lDistanceToMove: %d, lplDistanceToMoveHigh: %d, dwMoveMethod: %lu", hFile, lDistanceToMove, lplDistanceToMoveHigh, dwMoveMethod);
        return ::SFileSetFilePointer(hFile, lDistanceToMove, lplDistanceToMoveHigh, dwMoveMethod);
#endif
    }

    BOOL SFileDdaBeginEx(HANDLE directsound, DWORD flags, DWORD mask, uint32_t lDistanceToMove, int32_t volume, int a6, int a7) {
        SS_DBG("directsound: 0x%x, flags: %lu, mask: %lu, lDistanceToMove: %u, volume: %d, a6: %d, a7: %d", directsound, flags, mask, lDistanceToMove, volume, a6, a7);
#ifdef STORMSTUB_PASSTHROUGH
        return ::SFileDdaBeginEx(directsound, flags, mask, lDistanceToMove, volume, a6, a7);
#else
        return ::SFileDdaBeginEx(directsound, flags, mask, lDistanceToMove, volume, a6, a7);
#endif
    }
    
    BOOL SFileDdaDestroy() {
        SS_DBG("");
#ifdef STORMSTUB_PASSTHROUGH
        return ::SFileDdaDestroy();
#else
        return ::SFileDdaDestroy();
#endif
    }
    
    BOOL SFileDdaEnd(HANDLE directsound) {
        SS_DBG("directsound: 0x%x", directsound);
#ifdef STORMSTUB_PASSTHROUGH
        return ::SFileDdaEnd(directsound);
#else
        return ::SFileDdaEnd(directsound);
#endif
    }
    
    BOOL SFileDdaGetPos(HANDLE directsound, int a2, int a3) {
        SS_DBG("directsound: 0x%x, a2: %d, a3: %d", directsound, a2, a3);
#ifdef STORMSTUB_PASSTHROUGH
        return ::SFileDdaGetPos(directsound, a2, a3);
#else
        return ::SFileDdaGetPos(directsound, a2, a3);
#endif
    }
    
    BOOL SFileDdaInitialize(HANDLE directsound) {
        SS_DBG("directsound: 0x%x", directsound);
#ifdef STORMSTUB_PASSTHROUGH
        return ::SFileDdaInitialize(directsound);
#else
        return ::SFileDdaInitialize(directsound);
#endif
    }
    
    BOOL SFileDdaSetVolume(HANDLE directsound, int bigvolume, int volume) {
        SS_DBG("directsound: 0x%x, bigvolume: %d, a3: %d", directsound, bigvolume, volume);
#ifdef STORMSTUB_PASSTHROUGH
        return ::SFileDdaSetVolume(directsound, bigvolume, volume);
#else
        return ::SFileDdaSetVolume(directsound, bigvolume, volume);
#endif
    }
}
