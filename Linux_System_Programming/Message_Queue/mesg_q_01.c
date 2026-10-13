
#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct message
{
    long type;
    char text[100];
};

int main(void)
{
    int qid;
    struct message msg;

    qid = msgget(IPC_PRIVATE, IPC_CREAT | 0600);

    if (qid == -1)
    {
        perror("msgget");
        return 1;
    }

    msg.type = 1;
    strcpy(msg.text, "Hello from message queue!");

    if (msgsnd(qid, &msg, strlen(msg.text) + 1, 0) == -1)
    {
        perror("msgsnd");
        msgctl(qid, IPC_RMID, NULL);
        return 1;
    }

    if (msgrcv(qid, &msg, sizeof(msg.text), 1, 0) == -1)
    {
        perror("msgrcv");
        msgctl(qid, IPC_RMID, NULL);
        return 1;
    }

    printf("Received: %s\n", msg.text);

    if (msgctl(qid, IPC_RMID, NULL) == -1)
    {
        perror("msgctl");
        return 1;
    }

    return 0;
}






/*


1. What is a Message Queue?

A message queue is an IPC mechanism that allows processes to exchange data by sending and receiving messages through a queue maintained by the operating system.

Unlike a pipe, a message queue preserves message boundaries: each message is received as a separate message.

Process 1

Sends a message 📤

Message Queue

Message 1
Message 2
Message 3

Process 2

Receives a message 📥




2. Important System V message queue functions

Function

Purpose

msgget()

Creates or accesses a message queue

msgsnd()

Sends a message

msgrcv()	

Receives a message

msgctl()

Controls or removes a message queue

Header files:

#include <sys/ipc.h>
#include <sys/msg.h>


4. Compile and run ⚙️

Save the program as message_queue.c.

gcc message_queue.c -o message_queue
./message_queue

Output:

Received: Hello from message queue!



5. How does it work?

msgget() creates a message queue.

msgsnd() sends a message into the queue.

msgrcv() receives the message with type 1.

msgctl() with IPC_RMID removes the queue.

Important: For System V queues, the message structure must start with a positive long message type. The size passed to msgsnd() and msgrcv() counts the message text bytes, excluding the long type field.

This example demonstrates the functions in one process. In a real IPC application, separate processes can access a shared queue using an agreed queue key or another way of obtaining its identifier.

6. Advantages and disadvantages 💡

✅ Keeps individual messages separate.

✅ Supports message types, allowing selective receiving.

✅ The sender and receiver do not need to run at exactly the same time.

⚠️ Queues have system-defined limits.

⚠️ Processes need appropriate permissions and error handling.

One-line definition: A message queue is an IPC mechanism that allows processes to exchange separate, typed messages through an operating-system-managed queue. 🚀



*/
