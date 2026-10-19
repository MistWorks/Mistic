#pragma once

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef unsigned long long u64;
typedef u64                usize;
typedef char      s8;
typedef short     s16;
typedef int       s32;
typedef long long s64;
typedef s64     ssize;
#define bool _Bool
#define true 1
#define false 0
#define NULL ((void*)0)

#define USIZE_MAX ((usize)-1)
#define SSIZE_MAX ((ssize)(USIZE_MAX >> 1))
#define SSIZE_MIN ((ssize)(-SSIZE_MAX - 1))
