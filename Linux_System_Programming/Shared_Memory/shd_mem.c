
#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(void)
{
    int shmid;
    char *ptr;

    shmid = shmget(IPC_PRIVATE, 1024,
                   IPC_CREAT | 0600);

    if (shmid == -1)
    {
        perror("shmget");
        return 1;
    }

    ptr = (char *)shmat(shmid, NULL, 0);

    if (ptr == (char *)-1)
    {
        perror("shmat");
        shmctl(shmid, IPC_RMID, NULL);
        return 1;
    }

    strcpy(ptr, "Hello from shared memory!");

    printf("Message: %s\n", ptr);

    if (shmdt(ptr) == -1)
    {
        perror("shmdt");
        shmctl(shmid, IPC_RMID, NULL);
        return 1;
    }

    if (shmctl(shmid, IPC_RMID, NULL) == -1)
    {
        perror("shmctl");
        return 1;
    }

    return 0;
}





/*



🧠 IPC in Linux — Shared Memory

1. What is Shared Memory?

Shared memory is an IPC mechanism that allows two or more processes to access the same region of memory to exchange data.

Instead of sending data through a pipe, processes read and write directly to a shared memory region.

Process 1

Writes data ✍️

Process 2

Reads data 📖

Shared Memory

Same memory region accessible to both processes






2. Common shared memory functions

Linux provides POSIX shared memory APIs and System V shared memory APIs. We'll use the System V API in this example.

Function	

Purpose

shmget()

Creates or obtains a shared memory segment

shmat()	

Attaches the segment to a process's address space


shmdt()

Detaches the segment

shmctl()

Controls the segment, including removing it



Header files:

#include <sys/ipc.h>
#include <sys/shm.h>





4. Compile and run ⚙️
gcc shared_memory.c -o shared_memory
./shared_memory

Output:

Message: Hello from shared memory!




5. How does it work?

shmget() creates a shared memory segment.

shmat() attaches it to the process.

strcpy() writes a message into the memory.

printf() reads and displays the message.

shmdt() detaches the memory.

shmctl(..., IPC_RMID, ...) marks the segment for removal.




Note: This basic program demonstrates the API but does not yet exchange data between two independent processes. Shared memory alone also does not synchronize concurrent access; use semaphores or another synchronization mechanism when processes access shared data concurrently.

6. Advantages and disadvantages

✅ Fast data exchange because processes access the same memory region.

✅ Suitable for large amounts of data.

⚠️ Requires synchronization to prevent conflicting access.

⚠️ Processes must agree on how the shared data is structured.

One-line definition: Shared memory is an IPC mechanism in which multiple processes access the same memory region to exchange data efficiently. 🚀








*/
