
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

int main(void)
{
    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return 1;
    }

    if (pid > 0)
    {
        /* Parent process exits */
        printf("Parent exiting. Child PID: %d\n", pid);
        return 0;
    }

    /* Child creates a new session */
    if (setsid() == -1)
    {
        perror("setsid");
        _exit(1);
    }

    /* Set working directory and file permissions mask */
    if (chdir("/") == -1)
    {
        perror("chdir");
        _exit(1);
    }

    umask(0);

    /* Redirect standard input, output and error */
    int fd = open("/dev/null", O_RDWR);

    if (fd == -1)
    {
        perror("open /dev/null");
        _exit(1);
    }

    if (dup2(fd, STDIN_FILENO) == -1 ||
        dup2(fd, STDOUT_FILENO) == -1 ||
        dup2(fd, STDERR_FILENO) == -1)
    {
        close(fd);
        _exit(1);
    }

    if (fd > STDERR_FILENO)
        close(fd);

    /* Background work */
    for (;;)
    {
        FILE *log = fopen("/tmp/daemon_demo.log", "a");

        if (log != NULL)
        {
            time_t now = time(NULL);
            fprintf(log, "Daemon running at %s", ctime(&now));
            fclose(log);
        }

        sleep(5);
    }

    return 0;
}




/*



1. What is a Daemon Process? 🤔
A daemon process is a background process in Linux that runs without direct interaction with the user and usually provides a service to the system or other applications.
Daemon processes often continue running after a user logs out, depending on how they are started and managed.
Examples:
- 🌐 sshd — handles SSH connections.
- 🖨️ cupsd — manages printing.
- 📅 cron — schedules commands and jobs.
- 📋 systemd-journald — collects system logs.




2. Why do we use daemon processes? 🎯
Daemons are useful when a task must run in the background without requiring a user to keep a terminal open.
- Run services continuously.
- Monitor system resources.
- Handle incoming network connections.
- Perform scheduled tasks.
- Collect logs and monitor devices.
For example, an SSH server must be ready to accept remote connections even when nobody is logged into its terminal.




3. Normal process vs daemon process
Normal process	Daemon process
Often started by a user	Often started by the system or a service manager
May interact with a terminal	Usually has no controlling terminal
May run in the foreground	Typically performs work in the background
May finish after completing a task	Often continues until stopped or its work ends
Example: ./program	Example: sshd
A daemon is still an ordinary Linux process. The main differences are its execution environment and role.




4. How does a daemon process work? ⚙️
A traditional daemon may be created using this sequence:
1. Start the program
The process begins execution.

2. Call fork()
Create a child process.

3. Call setsid()
Create a new session and detach from the controlling terminal.

4. Configure the environment
Set the working directory, file permissions mask, and file descriptors.

5. Perform background work
Monitor devices, handle requests, or perform scheduled tasks.


Important: This is the traditional daemonization approach. Modern Linux services are commonly launched and supervised by systemd, which often makes manual daemonization unnecessary.



Step 3: Compile the program
gcc -Wall -Wextra -g daemon_demo.c -o daemon_demo


Step 4: Run it
./daemon_demo


The parent process prints its child's PID and exits. The child continues running in the background.
The program is a basic daemonization demonstration, not a production-ready service. A real daemon should also handle signals, errors, logging, resource cleanup, and shutdown properly.




Step 5: Check the log file
Wait around five seconds, then run:
cat /tmp/daemon_demo.log


Example output:
Daemon running at Tue Oct 13 19:40:00 2026
Daemon running at Tue Oct 13 19:40:05 2026


The timestamps will depend on when you run it.




Step 6: Check whether the process is running
ps -ef | grep '[d]aemon_demo'


You should see a process entry containing daemon_demo.




Step 7: Stop the process
Find the process ID (PID) from the output and stop it:
kill -TERM <PID>


Replace <PID> with the actual number. This example does not implement a graceful SIGTERM handler, so it terminates by the default signal action.




6. Important daemon-related system calls
Function	Purpose
fork()	Creates a child process
setsid()	Creates a new session
chdir()	Changes the working directory
umask()	Sets the file-creation permission mask
dup2()	Redirects file descriptors
open()	Opens files such as /dev/null
close()	Closes file descriptors
sleep()	Pauses execution temporarily
sigaction()	Configures signal handling




7. How to manage a daemon using systemd 🛠️
In modern Ubuntu, you can run a program as a managed service instead of implementing traditional daemonization yourself.
For example, a systemd service can start a foreground program, restart it if configured to do so, and collect its output in the system journal.
Useful commands for existing services:
systemctl status ssh
systemctl list-units --type=service --state=running
journalctl -u ssh


The SSH service name may differ on your distribution, and it may not be installed or enabled.




8. Important points to remember 📝
- A daemon typically runs in the background and has no controlling terminal.
- fork() creates a child; it does not, by itself, create a complete daemon.
- setsid() creates a new session and detaches the process from its controlling terminal.
- Daemons should not rely on terminal input or output.
- Production services need appropriate logging, signal handling, and lifecycle management.
- Modern Linux services are often managed by systemd.




🎯 One-line definition
A daemon process is a background Linux process that provides services or performs tasks without direct user interaction.




*/
