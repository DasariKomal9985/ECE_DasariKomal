
#include <stdio.h>
#include <pthread.h>

#define ITERATIONS 100000

int counter = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *increment(void *arg)
{
    for (int i = 0; i < ITERATIONS; i++)
    {
        pthread_mutex_lock(&lock);

        counter++;

        pthread_mutex_unlock(&lock);
    }

    return NULL;
}

int main(void)
{
    pthread_t t1, t2;

    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, increment, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final counter = %d\n", counter);

    pthread_mutex_destroy(&lock);

    return 0;
}




/*






1. What is Mutual Exclusion? 🤔
Mutual exclusion is a mechanism that ensures only one process or thread at a time accesses a shared resource or executes a particular critical section.
In simple words, it prevents multiple threads from modifying the same shared data simultaneously.
Example Suppose two threads are updating the same bank account balance.
Initial balance = ₹1,000
- Thread 1 deposits ₹500.
- Thread 2 withdraws ₹200.
If both threads read and modify the balance at the same time, one update might overwrite the other. This is called a race condition.
Mutual exclusion helps ensure the operations happen safely.



2. What is a Critical Section? ⚙️
A critical section is the part of a program that accesses shared data or a shared resource.
Entry Section
Request permission to enter

Critical Section 🔒
Access or modify shared data

Exit Section
Release the lock

Remainder Section
Execute other work


For example, when a thread increments a shared variable, the read-modify-write operation should be protected if other threads can access that variable concurrently.





3. What is a Race Condition? 🏁
A race condition occurs when the result depends on the timing or interleaving of concurrent operations.
Suppose counter = 0, and two threads each increment it once.
Step	Thread 1	Thread 2
1	Reads counter = 0	
2		Reads counter = 0
3	Calculates 1	
4		Calculates 1
5	Writes 1	
6		Writes 1
Expected result: 2
Actual result in this interleaving: 1
Mutual exclusion protects the shared update so both increments can be completed correctly.





4. How Do We Implement Mutual Exclusion in C? 🔧
Common mechanisms include:
- Mutex: A lock that allows one thread at a time into a protected section.
- Semaphore: A synchronization mechanism that can control access to resources or coordinate threads.
- Spinlock: A lock where a waiting thread repeatedly checks until the lock becomes available.
- Atomic operations: Operations performed indivisibly, useful for certain shared-data updates.
For beginners learning Linux System Programming, start with a POSIX mutex (pthread_mutex_t).





5. C Program Using a Mutex
This program creates two threads. Each increments the same shared counter 100,000 times. A mutex protects the counter.
Compile and run ▶️
Save the file as mutex_demo.c.
gcc -Wall -Wextra mutex_demo.c -o mutex_demo -pthread
./mutex_demo


Expected output:
Final counter = 200000


The counter reaches 200,000 because each thread performs 100,000 increments, and the mutex protects each increment.
Important functions
Function	Purpose
pthread_mutex_init()	Initializes a mutex
pthread_mutex_lock()	Acquires the mutex
pthread_mutex_unlock()	Releases the mutex
pthread_mutex_destroy()	Destroys an initialized mutex
In the example, PTHREAD_MUTEX_INITIALIZER initializes the mutex, so a separate call to pthread_mutex_init() isn't needed.
Important: Every successful lock must be matched with an unlock. If a thread fails to release a mutex, other threads may remain blocked indefinitely.




6. Mutex vs Semaphore
Feature	Mutex	Semaphore
Main purpose	Mutual exclusion	Resource counting or synchronization
Value	Locked or unlocked	Counter
Ownership	Usually owned by the locking thread	Generally no ownership requirement
Typical use	Protect shared data	Limit concurrent access or signal events




7. Mutual Exclusion in Linux and Embedded Systems 🐧
You may encounter mutual exclusion in:
- Linux multithreaded applications using POSIX mutexes.
- Linux kernel code using kernel mutexes and spinlocks.
- FreeRTOS tasks using mutexes and binary semaphores.
- Embedded systems where multiple tasks access shared peripherals or buffers.
The specific mechanism depends on the environment. For example, kernel code cannot use the POSIX pthread_mutex_t API directly.




One-line definition: Mutual exclusion is a synchronization technique that ensures only one process or thread at a time accesses a protected shared resource or critical section.






*/
