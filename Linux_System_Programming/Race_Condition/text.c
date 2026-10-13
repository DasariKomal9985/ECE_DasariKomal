1. What is a Race Condition?
A race condition occurs when two or more threads or processes access shared data concurrently, and the final result depends on the order in which their operations execute.

For example, two threads increment the same variable at the same time. One increment can be lost if both threads read the same old value before either writes the new value.



2. Code without protection — Race Condition ❌

We'll use two threads, each incrementing a shared variable one million times.




Compile and run
gcc no_race.c -o no_race -pthread
./no_race

Output:

Counter = 2000000

The mutex protects the increment operation, so both threads can safely update the shared counter.




4. Difference

Without protection ❌					With mutex ✅

Threads access the counter concurrently			Only one thread updates it at a time

Updates can be lost					Updates are protected

Result may be incorrect					Result is consistently 2000000

No synchronization					Uses pthread_mutex_lock() and pthread_mutex_unlock()





5. Important functions

pthread_create() — creates a thread.

pthread_join() — waits for a thread to finish.

pthread_mutex_lock() — locks the mutex.

pthread_mutex_unlock() — unlocks the mutex.




One-line definition: A race condition occurs when concurrent access to shared data makes the result depend on execution timing; a mutex can prevent it by protecting the critical section. 🔐
