#pragma once

#include "types.h"

const char* ReasonToString(const DWORD dwReason);
const char* MainMenuResultToString(const int iResult);
void DumpUiHeroInfo(const _uiheroinfo* info);