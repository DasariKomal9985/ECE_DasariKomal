Structure in C
1. Definition
A structure is a user-defined data type in C that allows storing different data types such as int, char, and float at the same time, where each member has its own separate memory location.

Syntax
struct StructureName
{
    data_type member1;
    data_type member2;
    data_type member3;
};

Example
struct Student
{
    int roll;
    char name[20];
    float marks;
};




Arrays in C
1. Definition
An array is a derived data type in C that allows storing multiple elements of the same data type under a single variable name, where all elements are stored in contiguous memory locations and accessed using index numbers starting from 0.

Syntax
data_type array_name[size];

Example:
int arr[5];




Pointers in C
1. Definition
A pointer is a variable in C that stores the memory address of another variable and allows accessing or modifying the value stored at that memory location using the dereference operator (*).

2. Syntax
data_type *pointer_name;

3. Example
int a = 10;
int *ptr = &a;






Bit Fields in C
1. Definition
Bit fields are a feature in C structures that allow specifying the number of bits allocated to individual structure members instead of allocating the normal size of their data types. 

2. Syntax
struct StructureName
{
    data_type member_name : number_of_bits;
};

3. Example
struct Status
{
    unsigned int power : 1;
    unsigned int mode  : 2;
    unsigned int error : 1;
};







File Operations in C
1. Definition
File operations in C are used to create, open, read, write, append, and close files to store and retrieve data permanently in secondary storage.






Function Pointer in C
1. Definition
A function pointer is a pointer variable that stores the address of a function and allows calling that function through the pointer.

2. Syntax
return_type (*pointer_name)(parameter_list);

3. Example
int add(int a, int b)
{
    return a + b;
}

int (*ptr)(int, int) = add;

Difference Between Normal Function and Function Pointer in C
1. Normal Function
A normal function is a block of code that performs a specific task and is called directly using its function name.
2. Function Pointer
A function pointer is a pointer variable that stores the address of a function and allows calling that function indirectly through the pointer.







Callback Function in C
1. Definition
A callback function is a function that is passed as an argument to another function using a function pointer and is executed by that function when a specific condition or event occurs.

2. Syntax
void callback(void)
{
    // Callback code
}

void main_function(void (*ptr)(void))
{
    ptr();
}
3. Example
#include <stdio.h>

void callback(void)
{
    printf("Callback function executed\n");
}

void process(void (*ptr)(void))
{
    printf("Processing...\n");

    ptr();
}

int main(void)
{
    process(callback);

    return 0;
}









Type Casting in C
1. Definition
Type casting is the process of converting a variable or expression from one data type to another data type.

2. Types of Type Casting
There are two types:
Implicit Type Casting (Automatic Conversion)
Explicit Type Casting (Manual Conversion)






Preprocessing Stages in C
1. Definition
Preprocessing is the first stage of C program compilation in which the preprocessor processes preprocessor directives, removes comments, expands macros, includes header files, and handles conditional compilation before passing the expanded source code to the compiler.
2. Preprocessing Directives
Preprocessor directives are instructions that begin with the # symbol and are processed before actual compilation.

Examples:
Directive Purpose
#include Includes header files.
#define Defines macros.
#undef Undefines a macro.
#ifdef Checks whether a macro is defined.
#ifndef Checks whether a macro is not defined.
#if Checks a compile-time condition.
#else Alternative conditional section.
#endif Ends a conditional section.


 Flow of Preprocessing
Original C Source Code
program.c
Comment Removal
Header File Inclusion
Macro Expansion
Conditional Compilation
Preprocessed Output
program.i




