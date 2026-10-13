
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t A = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t B = PTHREAD_MUTEX_INITIALIZER;

void *thread1(void *arg)
{
    pthread_mutex_lock(&A);
    printf("Thread 1 locked A\n");
    fflush(stdout);

    sleep(1);

    printf("Thread 1 waiting for B\n");
    fflush(stdout);
    pthread_mutex_lock(&B);

    printf("Thread 1 acquired B\n");

    pthread_mutex_unlock(&B);
    pthread_mutex_unlock(&A);

    return NULL;
}

void *thread2(void *arg)
{
    pthread_mutex_lock(&B);
    printf("Thread 2 locked B\n");
    fflush(stdout);

    sleep(1);

    printf("Thread 2 waiting for A\n");
    fflush(stdout);
    pthread_mutex_lock(&A);

    printf("Thread 2 acquired A\n");

    pthread_mutex_unlock(&A);
    pthread_mutex_unlock(&B);

    return NULL;
}

int main(void)
{
    pthread_t t1, t2;

    pthread_create(&t1, NULL, thread1, NULL);
    pthread_create(&t2, NULL, thread2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&A);
    pthread_mutex_destroy(&B);

    return 0;
}
