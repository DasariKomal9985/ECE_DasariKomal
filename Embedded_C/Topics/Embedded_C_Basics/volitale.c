#include <stdio.h>

volatile int interrupt_flag = 0;

void ISR(void)
{
    interrupt_flag = 1;
}

int main(void)
{
    printf("Waiting for interrupt...\n");

    while (interrupt_flag == 0)
    {
        // Wait for interrupt
    }

    printf("Interrupt received!\n");

    return 0;
}





/*


1. What is volatile? 🤔
In C, volatile is a keyword that tells the compiler that a variable's value may change unexpectedly, outside the normal program flow.
Because of this, the compiler must respect volatile accesses and cannot simply assume the value remains unchanged between accesses.
Syntax
volatile int value;


Here:
- volatile — tells the compiler to treat accesses to value as volatile.
- int — specifies the data type.
- value — is the variable name.
One-line definition: volatile tells the compiler that a variable may change unexpectedly, so its accesses must not be optimized away or reused as if its value cannot change.

2. Why do we need volatile? 🎯
Consider this example:
int flag = 0;

while (flag == 0)
{
    // Wait for flag to change
}


Suppose an interrupt service routine (ISR) changes flag to 1.
flag = 1;


The compiler may optimize the loop based on its assumption that nothing in the visible loop changes flag. Depending on the program and compiler, this can cause the loop to keep waiting even after the flag changes.
To tell the compiler that the variable can change unexpectedly, write:
volatile int flag = 0;

while (flag == 0)
{
    // Wait for flag to change
}


Now the compiler must perform the required volatile access to flag each time the loop checks it.
Important: volatile does not make an operation atomic, synchronize multiple threads, or guarantee that the program will eventually exit the loop.

3. Where do we use volatile in Embedded C? 🔧

1. Hardware registers
Registers used to control GPIO, timers, ADC, UART, and other peripherals can change because of hardware activity.
volatile unsigned int *status_reg;






2. Interrupt Service Routines (ISRs)
An ISR may update a variable that the main program reads.
volatile int interrupt_flag = 0;






3. Timers and counters
A timer interrupt may update a counter while the main program reads it.
volatile unsigned int milliseconds = 0;






4. Memory-mapped peripheral status
Hardware can update a status register independently of the instructions executed by the CPU.
volatile unsigned int *status;






4. Example 1: Normal variable vs volatile variable
Let's understand how the compiler treats the two declarations.
WITHOUT volatile
int flag = 0;

while (flag == 0)
{
    // Wait
}


The compiler may optimize accesses based on the assumption that flag is not modified through the program's visible execution flow.

WITH volatile
volatile int flag = 0;

while (flag == 0)
{
    // Wait
}


Each evaluation of flag requires a volatile read, so the compiler cannot simply reuse a previously read value.

Remember: In a real C program, an interrupt modifying the flag must be handled according to the target compiler's and platform's ISR conventions. volatile alone does not solve every concurrency issue.




How does this program work?
1. interrupt_flag starts at 0.
2. The main program waits inside the while loop.
3. When the interrupt occurs, ISR() sets the flag to 1.
4. The main loop reads the updated flag and exits.
5. The program prints Interrupt received!.
Note: This is an illustrative example for learning. A real MCU requires the appropriate interrupt declaration, vector configuration, and interrupt setup for its toolchain.

6. Example 3: volatile with a hardware register
Suppose an MCU has a memory-mapped status register at a documented address.
#include <stdint.h>

#define STATUS_REG (*(volatile uint32_t *)0x40000000U)

int main(void)
{
    while ((STATUS_REG & 1U) == 0U)
    {
        // Wait until bit 0 becomes 1
    }

    // Status bit is set

    while (1)
    {
    }
}


Explanation
- uint32_t — a 32-bit unsigned integer type.
- 0x40000000U — an illustrative address; it is not a universal register address.
- volatile — ensures each evaluation accesses the register instead of treating its value as an ordinary, unchanged variable.
- & 1U — checks bit 0.
- The loop waits until bit 0 becomes 1.
⚠️ Use the actual register address and access width from your microcontroller's reference manual. Hardware registers may have special read/write behavior.

7. Different ways to use volatile
A. Volatile variable
volatile int sensor_value;


The variable itself is volatile.
B. Pointer to volatile data
volatile int *ptr;


The data accessed through ptr is volatile. The pointer itself can be changed.
C. Constant pointer to volatile data
volatile int *const ptr = (volatile int *)0x40000000U;


The pointer cannot be reassigned, but the volatile data it points to can change.
D. Constant pointer to volatile data, using the alternate order
int volatile *ptr;


This means the same thing as volatile int *ptr.
E. Volatile pointer
int * volatile ptr;


The pointer itself is volatile, but the pointed-to int is not automatically volatile.
F. Constant volatile pointer
int * volatile const ptr = some_address;


The pointer is both constant and volatile; the pointed-to int is not automatically volatile.

8. What volatile does and does not do
Property	Does volatile provide it?
Prevents eliminating required volatile accesses	Yes
Requires a fresh volatile read when the expression is evaluated	Yes
Makes a variable atomic	No
Makes a program thread-safe	No
Protects shared data with a mutex	No
Guarantees the latest physical hardware state in every possible situation	No
Replaces memory barriers or synchronization primitives	No
For example:
volatile int count = 0;

count++;


count++ is a read-modify-write operation. It is not necessarily atomic. If an interrupt or another execution context updates count at the same time, updates can be lost.


*/
