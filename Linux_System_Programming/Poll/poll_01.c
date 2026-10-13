**File: `poll_demo.c`**

```c
#include <stdio.h>
#include <unistd.h>
#include <poll.h>

int main(void)
{
    struct pollfd fd;

    fd.fd = STDIN_FILENO;
    fd.events = POLLIN;
    fd.revents = 0;

    printf("Enter something within 5 seconds:\n");

    int ret = poll(&fd, 1, 5000);

    if (ret > 0)
    {
        if (fd.revents & POLLIN)
        {
            char buffer[100];

            ssize_t n = read(STDIN_FILENO, buffer,
                             sizeof(buffer) - 1);

            if (n > 0)
            {
                buffer[n] = '\0';
                printf("You entered: %s", buffer);
            }
        }
    }
    else if (ret == 0)
    {
        printf("Timeout! No input received.\n");
    }
    else
    {
        perror("poll");
        return 1;
    }

    return 0;
}







/*

📡 poll() in Linux System Programming (C)
1. What is poll()?
poll() is a Linux/POSIX I/O multiplexing system call that allows a program to monitor multiple file descriptors and check whether they are ready for operations such as reading or writing.
Instead of checking each file descriptor separately, poll() lets the program wait for activity on several descriptors at once.
Example: A server monitoring multiple client connections can use poll() to know which clients have sent data.




2. Why do we use poll()?
Suppose a server has three client connections:
- Client 1 sends data.
- Client 2 sends nothing.
- Client 3 sends data.
Without poll(), the program might wait on one client and fail to respond promptly to another.
With poll(), the server can monitor all three and process whichever is ready.
Common uses:
- Network servers and TCP sockets.
- Monitoring multiple file descriptors.
- Serial ports and terminal input.
- Pipes and other supported I/O descriptors.
- Event-driven applications.




3. Syntax of poll()
Include these headers:
#include <poll.h>
#include <unistd.h>


Function prototype:
int poll(struct pollfd fds[], nfds_t nfds, int timeout);


Parameter	Meaning
fds	Array of file descriptors and requested events
nfds	Number of entries in the array
timeout	Maximum wait time in milliseconds
Return values:
- Positive number: number of entries with reported events.
- 0: timeout expired without reported events.
- -1: error; check errno.
Important event flags:
Flag	Meaning
POLLIN	Data is available to read
POLLOUT	Writing is possible
POLLERR	Error condition
POLLHUP	Hangup condition
POLLNVAL	Invalid file descriptor




Compile and run
gcc poll_demo.c -o poll_demo
./poll_demo


Example output if you type Hello within five seconds:
Enter something within 5 seconds:
Hello
You entered: Hello


If you do not enter anything before the timeout:
Enter something within 5 seconds:
Timeout! No input received.


The exact timing can vary slightly because of scheduling and terminal behavior.




5. How does this program work?
1. Configure pollfd
Monitor STDIN_FILENO for POLLIN

2. Call poll()
Wait up to 5000 milliseconds

Ready
Read input


Timeout
Return 0


Error
Return -1




The pollfd structure contains:
struct pollfd {
    int   fd;       // File descriptor to monitor
    short events;   // Events requested
    short revents;  // Events reported by poll()
};


- fd specifies which descriptor to monitor.
- events specifies what you want to detect.
- revents contains the events reported by poll().



6. What if we don't use poll()?
Imagine a server has multiple clients.
Without poll():
- A blocking read() on one client may wait while another client already has data.
- You may need separate threads or another event-handling method.
- Inefficient designs can waste resources or respond slowly.
With poll():
- One thread can monitor multiple file descriptors.
- It can process descriptors reported as ready.
- It can wait for activity or use a timeout instead of repeatedly checking in a busy loop.
Note that poll() itself can block until an event or timeout occurs. It does not automatically make every subsequent read() or write() nonblocking; nonblocking descriptors and correct handling of partial I/O are still important.



7. poll() vs select() vs epoll()
Feature	select()	poll()	epoll()
Purpose	Monitor multiple descriptors	Monitor multiple descriptors	Efficient event monitoring, especially for many descriptors
Interface	fd_set	Array of pollfd	Create an instance and manage registrations
Descriptor limit	Subject to FD_SETSIZE in common implementations	No fixed FD_SETSIZE limit in the interface	Designed for large sets of descriptors
Typical use	Small/simple applications	Small or moderate descriptor sets	High-concurrency Linux servers



🎯 One-line definition


poll() is an I/O multiplexing system call that waits for events on multiple file descriptors, allowing a program to handle ready I/O without blocking on just one descriptor.










*/
