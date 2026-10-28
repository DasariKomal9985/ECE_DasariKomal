#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define THREAD_COUNT 5
#define PRINTER_COUNT 3

sem_t printers;

void *use_printer(void *arg)
{
    int id = *(int *)arg;

    printf("Thread %d is waiting for a printer\n", id);

    sem_wait(&printers);  // Acquire one printer permit

    printf("Thread %d is using a printer\n", id);

    sleep(2);             // Simulate printing

    printf("Thread %d finished printing\n", id);

    sem_post(&printers);  // Release the printer permit

    return NULL;
}

int main(void)
{
    pthread_t threads[THREAD_COUNT];
    int ids[THREAD_COUNT];

    sem_init(&printers, 0, PRINTER_COUNT);

    for (int i = 0; i < THREAD_COUNT; i++)
    {
        ids[i] = i + 1;
        pthread_create(&threads[i], NULL, use_printer, &ids[i]);
    }

    for (int i = 0; i < THREAD_COUNT; i++)
    {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&printers);

    return 0;
}