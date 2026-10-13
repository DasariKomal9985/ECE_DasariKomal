#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *use_resource(void *arg)
{
    int id = *(int *)arg;

    printf("Thread %d is using resource\n", id);
    sleep(2);
    printf("Thread %d finished\n", id);

    return NULL;
}

int main(void)
{
    pthread_t t1, t2;
    int a = 1, b = 2;

    pthread_create(&t1, NULL, use_resource, &a);
    pthread_create(&t2, NULL, use_resource, &b);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
