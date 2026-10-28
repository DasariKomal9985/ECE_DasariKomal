#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define ITERATIONS 100000

int counter = 0;
sem_t sem;

void *increment(void *arg)
{
    (void)arg;

    for (int i = 0; i < ITERATIONS; i++)
    {
        sem_wait(&sem);   // Acquire the semaphore

        counter++;        // Critical section

        sem_post(&sem);   // Release the semaphore
    }

    return NULL;
}

int main(void)
{
    pthread_t t1, t2;

    sem_init(&sem, 0, 1);  // Shared between threads, initial value = 1

    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, increment, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final counter = %d\n", counter);

    sem_destroy(&sem);

    return 0;
}