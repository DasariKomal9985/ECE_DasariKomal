
#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>

int main(void)
{
    struct winsize ws;

    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1)
    {
        perror("ioctl");
        return 1;
    }

    printf("Rows: %d\n", ws.ws_row);
    printf("Columns: %d\n", ws.ws_col);

    return 0;
}





/*



🔧 Linux System Programming: ioctl()
1. What is ioctl()? 🤔
ioctl() stands for Input/Output Control.
It is a Linux system call used to perform device-specific operations that cannot be handled easily using normal read() and write() calls.
For example, ioctl() can be used to:
- 🔌 Configure a device.
- 💡 Turn an LED ON or OFF through a device driver.
- 🔊 Set audio volume.
- 📡 Configure network interfaces.
- 🖥️ Get or set device parameters.
- 🔧 Communicate with a Linux device driver.



2. Why do we need ioctl()?
Consider a device driver that controls an LED.
- write() might send data to the driver.
- read() might retrieve data from the driver.
- ioctl() can send a specific command, such as set the LED mode or configure its behavior.
So, ioctl() provides a way to send commands and configuration data to a device driver.




3. Syntax of ioctl()
#include <sys/ioctl.h>

int ioctl(int fd, unsigned long request, ...);


Argument	Meaning
fd	File descriptor of the device or file
request	Command that specifies the operation
...	Optional argument, often a value or pointer to data
Return value:
- 0 or another nonnegative value: success, depending on the command.
- -1: failure; errno indicates the error.


How does it work?
1. STDOUT_FILENO identifies standard output, usually the terminal.
2. TIOCGWINSZ requests the terminal window size.
3. &ws passes the address of the structure where the result is stored.
4. The program prints the number of rows and columns.
Compile and run
gcc ioctl_demo.c -o ioctl_demo
./ioctl_demo


Example output (depends on your terminal):
Rows: 30
Columns: 120


If standard output is redirected to a file or is not a terminal, the call may fail.




5. How ioctl() works with a device driver 🔄
User-space application
Calls ioctl(fd, command, argument)

Linux system call
Passes the request to the kernel

Device driver's unlocked_ioctl()
Checks the command and performs the operation

Hardware or device configuration
Returns a result or an error


For a Linux character driver, a driver may implement an unlocked_ioctl callback in its file_operations structure.
Conceptually:
static long my_ioctl(struct file *file,
                     unsigned int cmd,
                     unsigned long arg)
{
    switch (cmd)
    {
        case MY_DEVICE_RESET:
            /* Reset device 
            break;

        default:
            return -EINVAL;
    }

    return 0;
}


This is only a callback example; a complete driver also needs to define the command and register its file operations.




6. How are ioctl() commands defined?
Linux drivers commonly use macros from <linux/ioctl.h> to define commands.
Macro	Purpose
_IO()	Command without additional data
_IOR()	Read data from the driver
_IOW()	Send data to the driver
_IOWR()	Send data and receive data
For example, a driver might define a command to retrieve device information using _IOR(). The command definition must agree with the data type and the driver's implementation.




7. read() vs write() vs ioctl()
Function	Main purpose
read()	Read data
write()	Write or send data
ioctl()	Control or configure a device using commands




8. Where is ioctl() used in embedded Linux? ⚙️
- GPIO device control
- I²C and SPI device configuration
- Network interface configuration
- Audio device control
- Display and terminal settings
- Custom Linux character drivers
Important: Modern Linux subsystems often provide dedicated interfaces instead of requiring custom ioctl() calls. For example, GPIO is commonly controlled through the GPIO character-device API.
📝 One-line definition
ioctl() is a Linux system call used to send device-specific control commands and configuration requests to a file or device driver.



*/
