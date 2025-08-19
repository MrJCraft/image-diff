#ifndef MY_TYPES_H
#define MY_TYPES_H

#include <stdint.h>

// Basic integer types
typedef uint8_t  U8;
typedef int8_t   S8;
typedef uint16_t U16;
typedef int16_t  S16;
typedef uint32_t U32;
typedef int32_t  S32;
typedef uint64_t U64;
typedef int64_t  S64;

// Floating-point and boolean types
typedef float    F32;
typedef double   F64;
typedef S32      B32;

// Common aliases
typedef const char* CStr;

// Module-specific types
typedef U32 GFX_Texture;
typedef U64 FS_FileHandle;

typedef union {
    U32 value;
    struct {
        uint8_t r;
        uint8_t g;
        uint8_t b;
        uint8_t a;
    };
} Color32;


#endif // MY_TYPES_H


