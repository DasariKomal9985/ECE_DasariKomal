**File: `with_spinlock.c`**

```c
#define _GNU_SOURCE
#include <stdio.h>
#include <pthread.h>

int counter = 0;
pthread_spinlock_t lock;

void *increment(void *arg)
{
    for (int i = 0; i < 1000000; i++)
    {
        pthread_spin_lock(&lock);

        counter++;

        pthread_spin_unlock(&lock);
    }

    return NULL;
}

int main(void)
{
    pthread_t t1, t2;

    if (pthread_spin_init(&lock, PTHREAD_PROCESS_PRIVATE) != 0)
    {
        perror("pthread_spin_init");
        return 1;
    }

    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, increment, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Counter = %d\n", counter);

    pthread_spin_destroy(&lock);

    return 0;
}

