# cstr

A simple light-weight C string API

## Installation

Clone repository: 

```bash
git clone https://github.com/DeTosis/cstr
```

To use API you need to add `str.c` and `str.h` in to your project.

Add `str.c` to your build;

## Features

* allocation, assignment, deallocation 
* concatenation
* clearing
* to lowercase and uppercase
* slicing

## Usage

Project has `examples.c` file, that shows all the features of an API and how to use them. 

Core features: 

```c
//Allocates a new `str` on the heap and returns pointer to the `str` object; 
str* str_set(const char* value);
```
```c
//Frees allocated `str` object
void str_free(str* st);
```
```c
//Returns a ptr to a deep copy of `str` 
str* str_copy(const str* st);
```

## Examples

Example compilation:
```bash
git clone https://github.com/DeTosis/cstr
cd cstr
make
```

`make` to compile prject

Optional:

`make run` to compile and run

`make runc` to compile and clear `.obj` files from the build directory

---
_Compiled .exe would be in `./build` directory_

_Makefile provided required MSVC compiler build only for windows_

_In case of other platforms you need to compile project by yourself_
