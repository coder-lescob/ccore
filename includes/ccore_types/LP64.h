#ifndef __CCORE_TYPES_LP64_H
#define __CCORE_TYPES_LP64_H

/*************************************************************************************
 *                         STANDARDS COMPATIBLE TYPES                                *
 *************************************************************************************/


// equivalent to the POSIX ssize_t
typedef long isize;
// equivalent to the POSIX size_t
typedef unsigned long usize;

// pointers as ints               same as:
typedef          long ptrdiff; // ptrdiff_t
typedef          long iptr;    // intptr_t
typedef unsigned long uptr;    // uintptr_t

// precise ints modern version of intX_t and uintX_t
typedef          long  i64;
typedef unsigned long  u64;
typedef          int   i32;
typedef unsigned int   u32;
typedef          short i16;
typedef unsigned short u16;
typedef signed   char  i8;
typedef unsigned char  u8;

#endif /* __CCORE_TYPES_LP64_H */
