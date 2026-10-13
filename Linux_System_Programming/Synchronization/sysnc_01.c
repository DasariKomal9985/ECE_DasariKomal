
#include <stdio.h>
#include <pthread.h>

int counter = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *increment(void *arg)
{
    for (int i = 0; i < 100000; i++)
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


1. What is Synchronization? 🤔
Synchronization is the coordination of multiple processes or threads to ensure they execute in the correct order and access shared resources safely.
In simple words, synchronization helps threads or processes work together without creating conflicts.
💡 Real-life example
Imagine two people using the same printer.
- 🧑 Person 1 sends a document to print.
- 🧑 Person 2 also sends a document.
- 🖨️ Synchronization helps coordinate access so their print jobs are handled correctly.
Synchronization can protect shared resources and coordinate when one task must wait for another.





2. Why Do We Need Synchronization?
Synchronization is important for several reasons:
- 🔒 To protect shared data.
- ⚠️ To prevent race conditions.
- 🔄 To coordinate multiple threads or processes.
- ⏱️ To control the order of operations.
- ✅ To maintain data consistency.
For example, if two threads increment a shared counter simultaneously without protection, one update may be lost.





3. Important Synchronization Concepts

1. Mutual Exclusion
Only one thread or process at a time can enter a protected critical section.
Example: A mutex protects a shared counter.




2. Coordination
Tasks coordinate their actions so one task can wait until another has completed a required operation.
Example: A consumer waits until a producer has placed data in a buffer.




3. Ordering
Synchronization establishes an order between operations.
Example: A program waits for a thread to finish before printing the final result.



4. Synchronization Mechanisms 🔧
Mechanism	Purpose
Mutex	Protects a critical section
Semaphore	Controls access to resources or signals events
Spinlock	Waits actively until a lock becomes available
Condition variable	Allows a thread to wait for a condition
Atomic operations	Perform supported operations indivisibly
Barrier	Makes participating threads wait until all reach a point
Remember: Mutual exclusion is one part of synchronization. Synchronization also includes coordinating task execution and ordering operations.




Compile and run ▶️
Save the file as sync_demo.c.
gcc -Wall -Wextra sync_demo.c -o sync_demo -pthread
./sync_demo


Expected output:
Final counter = 200000


How does it work?
1. pthread_create() creates two threads.
2. Both threads call increment().
3. pthread_mutex_lock() acquires the lock before accessing the counter.
4. counter++ updates the shared variable safely.
5. pthread_mutex_unlock() releases the lock.
6. pthread_join() waits for both threads to finish.
7. The main thread prints the final counter.
Here, the mutex provides mutual exclusion, while thread creation and joining also participate in coordinating execution.





6. Synchronization vs Mutual Exclusion
Mutual Exclusion 🔒	Synchronization 🔄
Prevents simultaneous access to protected resources	Coordinates access, execution, and ordering
Focuses on protecting critical sections	Covers a broader set of coordination problems
Often implemented with a mutex	Uses mutexes, semaphores, condition variables, barriers, and other mechanisms
One part of synchronization	The overall concept




7. Synchronization in Linux and FreeRTOS 🐧
Since you're learning Linux System Programming and embedded systems, these are important:
- Linux user space: POSIX mutexes, semaphores, condition variables, and atomic operations.
- Linux kernel: Mutexes, spinlocks, wait queues, completions, and atomic APIs.
- FreeRTOS: Mutexes, binary semaphores, counting semaphores, queues, and task notifications.
The APIs differ between these environments, but the underlying goal is similar: coordinate concurrent execution safely.
One-line definition: Synchronization is the coordination of concurrent processes or threads to ensure safe resource access and correct execution order.




🎯 Recommended next topic
Learn Race Conditions and Critical Sections next, then move to semaphores, mutexes, deadlocks, and producer-consumer synchronization.






*/
