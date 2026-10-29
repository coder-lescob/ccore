#ifndef __CCORE_TYPES_UNIVERSAL32_H
#define __CCORE_TYPES_UNIVERSAL32_H

/*************************************************************************************
 *                         STANDARDS COMPATIBLE TYPES                                *
 *************************************************************************************/


// equivalent to ssize_t
typedef long long isize;
// equivalent to size_t
typedef unsigned long long usize;

// pointers as ints               same as:
typedef          long long ptrdiff; // ptrdiff_t
typedef          long long iptr;    // intptr_t
typedef unsigned long long uptr;    // uintptr_t

// precise ints modern version of intX_t and uintX_t
typedef          long long i64;
typedef unsigned long long u64;
typedef          int   i32;
typedef unsigned int   u32;
typedef          short i16;
typedef unsigned short u16;
typedef signed   char  i8;
typedef unsigned char  u8;

#endif /* __CCORE_TYPES_UNIVERSAL32_H */
