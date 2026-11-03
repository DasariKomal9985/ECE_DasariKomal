/*






1. Preprocessing
Preprocessing is the first stage of the C compilation process in which the preprocessor processes preprocessor directives, such as header file inclusion, macro expansion, and conditional compilation, before passing the processed source code to the compiler.


2. Preprocessing Stages
Preprocessing stages are the operations performed by the C preprocessor on the source code, including comment removal, header file inclusion, macro expansion, and conditional compilation, to generate the preprocessed source code (.i file).




Directive	Purpose
#include	Includes header files
#define		Defines macros
#undef		Removes a macro definition
#ifdef		Checks whether a macro is defined
#ifndef		Checks whether a macro is not defined
#if		Checks a compile-time condition
#else		Alternative conditional branch
#elif		Checks another condition
#endif		Ends conditional compilation
#pragma		Gives compiler-specific instructions




Why do we need preprocessing?
It is used to:
- Include header files.
- Define macros and constants.
- Expand macros.
- Handle conditional compilation.
- Remove comments.


1. Preprocessing
Processes directives, includes headers and expands macros.
gcc -E


2. Compilation
Converts preprocessed C code into assembly code.
gcc -S


3. Assembly
Converts assembly code into machine-code object file.
gcc -c


4. Linking
Combines object files and required libraries to create an executable.
gcc


Executable Program








*/

#include <stdio.h>

// Object-like macro
#define A 10
#define B 20

// Function-like macro
#define ADD(x, y) ((x) + (y))

// Conditional compilation
#define DEBUG 1

int main()
{
    int a = A;
    int b = B;

    int result = ADD(a, b);

    printf("A = %d\n", a);
    printf("B = %d\n", b);
    printf("Sum = %d\n", result);

#ifdef DEBUG
    printf("Debug mode enabled\n");
#else
    printf("Debug mode disabled\n");
#endif

    return 0;
}








/*



A = 10
B = 20
Sum = 30
Debug mode enabled




*/
























/*

5. Explanation of every preprocessing step
Step 1: Header file inclusion – #include
#include <stdio.h>


- #include is a preprocessor directive.
- stdio.h is a standard input/output header file.
- It provides declarations for functions such as printf() and scanf().
What happens internally?

The preprocessor processes the header file and makes its declarations available to the source code.

Think of it as including the required header-file contents before compilation.
Step 2: Object-like macro – #define
#define A 10
#define B 20


Here, we define two macros.
- A represents 10.
- B represents 20.
Whenever the preprocessor encounters A or B as macro identifiers, it replaces them with their defined values.

For example:

Before preprocessing:
int a = A;
int b = B;


After preprocessing:
int a = 10;
int b = 20;


This is called macro expansion.
Step 3: Function-like macro
#define ADD(x, y) ((x) + (y))


This is a function-like macro.

It accepts two arguments, x and y.

When we write:
int result = ADD(a, b);


The preprocessor expands it to:
int result = ((a) + (b));


Notice that this is not an actual function call. The preprocessor performs textual macro substitution.

The extra parentheses help avoid operator-precedence problems.
Step 4: Conditional compilation
#define DEBUG 1


We define a macro named DEBUG with the value 1.

Now consider:
#ifdef DEBUG
    printf("Debug mode enabled\n");
#else
    printf("Debug mode disabled\n");
#endif


Explanation:
- #ifdef DEBUG checks whether DEBUG has been defined.
- If defined, the first block is retained.
- #else provides the alternative block.
- #endif marks the end of the conditional section.
Since we defined DEBUG, the preprocessor retains:
printf("Debug mode enabled\n");


The other block is removed from the preprocessed output.

Important: Conditional compilation happens before the compiler processes the C code. It is different from a normal runtime if statement.
6. See preprocessing practically in Ubuntu
Open your terminal in the directory containing preprocess.c.

Command 1: Normal compilation and execution
gcc preprocess.c -o preprocess
./preprocess


This compiles the program and executes it.

Command 2: Only preprocessing
gcc -E preprocess.c -o preprocess.i


What happens?
- -E tells GCC to stop after preprocessing.
- preprocess.i contains the preprocessed C source.
- Header inclusion and macro expansion have already happened.
Command 3: View preprocessed output
cat preprocess.i


You will see expanded macros and the contents of included headers. The file can be quite large because stdio.h brings in many declarations.

For a cleaner view, try:
gcc -E -P preprocess.c


-P suppresses the generated line-marker directives.
7. What exactly happens during preprocessing?
For our example, the preprocessor performs these operations:
Operation	What happens
Comment removal	Removes // and * ... */ comments
/*Header inclusion	Processes stdio.h
Macro expansion	Replaces A, B, and ADD(a,b)
Conditional compilation	Selects the DEBUG block
Output generation	Produces preprocessed C source (.i)

The important result from our example is that the relevant part of the preprocessed program becomes:
int main()
{
    int a = 10;
    int b = 20;

    int result = ((a) + (b));

    printf("A = %d\n", a);
    printf("B = %d\n", b);
    printf("Sum = %d\n", result);

    printf("Debug mode enabled\n");

    return 0;
}


This is a simplified view; the actual .i file also contains the processed header declarations.
8. One more important directive – #undef
#undef removes an existing macro definition.

Example:
#include <stdio.h>

#define VALUE 100

int main()
{
    printf("Value = %d\n", VALUE);

    #undef VALUE

    return 0;
}


Here, VALUE is defined before its use and undefined afterward.

If you try to use VALUE again after #undef, it will no longer be replaced with 100.*/


