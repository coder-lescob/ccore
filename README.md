# C Core

The C Core library is a modern lightweight alternative to the standard C library. It modernizes the function names and type at the same time of letting you call very useful syscalls.

## The types

Let meet the modern ints, you may recognize them from rust & cie, they are: u8,i8,u16,i16,u32,i32,u64,i64,isize and usize.

The C Core library also provides modern names for pointers as integers like: iptr for intptr_t

## Available syscalls

The most used syscalls are exposed through their modernized signatures. For now it on linux supports linux, but feel free to leave a pull request or an issue to improve the library. (I'm sure I'm gonna add the numworks).

The idiomatic and readable names like **write** or **read** stayed but more difficult to read names are renamed.

## Minimalisme

This library aims for a minimalist interface. 

## Contributing

Contributions are welcome, feel free to read the code, submit issues or leave a pull request.
