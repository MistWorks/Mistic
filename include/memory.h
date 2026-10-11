#pragma once
#include "types.h"

void copy(void* dst, const void* src, usize n);
void copyfb(void* dst, const void* src, usize n);
void fill(void* dst, int val, usize n);
bool iseq(const void* a, const void* b, usize n);
