**File: `with_sem.c`**

```c id="7vrgqp"
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t sem;

void *use_resource(void *arg)
{
    int id = *(int *)arg;

    sem_wait(&sem);

    printf("Thread %d is using resource\n", id);
    sleep(2);
    printf("Thread %d finished\n", id);

    sem_post(&sem);

    return NULL;
}

int main(void)
{
    pthread_t t1, t2;
    int a = 1, b = 2;

    sem_init(&sem, 0, 1);

    pthread_create(&t1, NULL, use_resource, &a);
    pthread_create(&t2, NULL, use_resource, &b);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    sem_destroy(&sem);

    return 0;
}
```
