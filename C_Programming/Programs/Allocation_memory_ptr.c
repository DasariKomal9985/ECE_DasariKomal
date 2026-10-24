#include <stdio.h>

int main()
{
    // Assign a specific memory address to a pointer
    int *ptr = (int *)0x2001001;

    // Write a value to that memory address
    *ptr = 42;

    // Read the value from that memory address
    printf("Value = %d\n", *ptr);

    return 0;
}


/*



2. Explanation of the Code

Step 1: Declare a pointer

int *ptr = (int *)0x2001001;

int *ptr declares a pointer that points to an integer.

0x2001001 represents a hexadecimal memory address.

(int *) converts the address value into an integer pointer.

Conceptually, ptr holds the address 0x2001001.

Step 2: Write a value to memory

*ptr = 42;

The * operator dereferences the pointer.

It accesses the memory location to which ptr points.

The value 42 is written to that location, assuming the address is valid and writable.

Step 3: Read the value from memory

printf("Value = %d\n", *ptr);

*ptr reads the value stored at the pointed-to memory location.

%d displays the integer value.

If the memory access is valid and the value remains unchanged, the output is:

Value = 42

3. What Can We Learn from This Code?

Pointers: A pointer stores a memory address.

Dereferencing: The * operator accesses the object at the address held by a pointer.

Memory read and write: Pointers can be used to read and modify values in memory.

Hexadecimal addresses: Memory addresses are commonly represented in hexadecimal.

Embedded C: Fixed-address access is used when working with memory-mapped hardware registers, provided the address and access type are correct.

4. What Is the Problem with the Original Code?

Although the code demonstrates an important concept, it is not safe to run on an ordinary computer without verifying the address.

Problem 1: Invalid memory address

The address 0x2001001 may not belong to the program or may not be writable.

Attempting to access it can cause a segmentation fault or another hardware fault.

Problem 2: Memory alignment

The address ends in 1, so it is not aligned to a typical 4-byte boundary required by an int on many systems.

Some processors permit unaligned accesses, while others may fault or handle them differently.

Problem 3: Hardware-specific addresses

In embedded systems, an address is valid only if it corresponds to an accessible memory region or register on the target microcontroller.

The address must be verified using the microcontroller's memory map or reference manual.

5. A Safe Version to Practise on a Computer

#include <stdio.h>

int main()
{
    int a;
    int *ptr = &a;

    *ptr = 42;

    printf("Value = %d\n", *ptr);
    printf("Address = %p\n", (void *)ptr);

    return 0;
}

Output

Value = 42
Address = <address of a on your system>

This version uses &a to obtain the address of a valid variable instead of assuming that an arbitrary address can be accessed.

6. Embedded C Application

In microcontrollers, pointers can access memory-mapped hardware registers.

For example:

#define REGISTER_ADDR  0x40020000U

volatile unsigned int *reg =
    (volatile unsigned int *)REGISTER_ADDR;

Here, volatile tells the compiler that accesses to the pointed-to object must respect volatile semantics, which is important for hardware registers.

Note: The address above is illustrative only. The actual register address, access width, alignment, and permissions must be verified for the target microcontroller.

Conclusion

This example introduces pointers, dereferencing, memory addresses, and direct memory access. It also shows why arbitrary memory addresses must not be accessed without checking whether they are valid.

In embedded systems, these concepts are essential for understanding memory-mapped registers and low-level hardware programming.





*/
