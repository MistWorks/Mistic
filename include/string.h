#pragma once
#include "types.h"
#include "herr.h"

usize strlen(const char* str);
bool striseq(const char* a, const char* b);
void strcopy(char* dst, const char* src);
