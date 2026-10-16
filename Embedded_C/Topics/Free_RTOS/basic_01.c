24. Embedded C + RTOS Basics ⚙️
In embedded systems, we often need to perform multiple operations, such as reading sensors, sending UART data, controlling motors, and monitoring faults.
If we write everything inside one infinite loop, the code can become difficult to manage. An RTOS (Real-Time Operating System) helps organize these operations into separate tasks and schedules when each task should run.
For your STM32F401RBT6 and FreeRTOS learning, let's understand each concept with simple explanations and Embedded C examples.









1. Task / Thread 🧵
A task, also called a thread in many RTOS contexts, is an independent sequence of instructions that performs a particular operation.
For example, an embedded application might have:
- Sensor Task — reads temperature.
- UART Task — sends sensor data to a computer.
- Motor Task — controls motor operation.
- Monitoring Task — checks system status.
Each task has its own execution context and usually its own stack.
Example without an RTOS
int main(void)
{
    while (1)
    {
        read_sensor();
        send_uart_data();
        control_motor();
    }
}


Here, the operations run sequentially. If read_sensor() takes a long time, the other operations must wait.
Example with FreeRTOS
void SensorTask(void *argument)
{
    while (1)
    {
        read_sensor();

        vTaskDelay(pdMS_TO_TICKS(100));
    }
}

void UARTTask(void *argument)
{
    while (1)
    {
        send_uart_data();

        vTaskDelay(pdMS_TO_TICKS(200));
    }
}


These functions can be created as separate FreeRTOS tasks. The scheduler decides which ready task executes.
The example assumes that FreeRTOS is configured and the application creates both tasks and starts the scheduler.
Why use tasks? They separate application responsibilities and make it easier to manage timing, priorities, and synchronization.












2. Scheduler 🗓️
The scheduler is the part of the RTOS that decides which ready task should execute.
A task may be in one of several states:
State	Meaning
Running	Currently executing on the CPU
Ready	Can execute but is waiting for CPU time
Blocked	Waiting for an event, delay, queue, or semaphore
Suspended	Explicitly suspended until resumed
On a single-core STM32, only one task executes at a time, although multiple tasks can make progress by sharing CPU time.
Example
Suppose your application has three tasks:
- Motor Task — priority 3.
- Sensor Task — priority 2.
- Logging Task — priority 1.
If all three are ready and FreeRTOS uses preemptive priority-based scheduling, the highest-priority ready task normally runs first.
If the Motor Task blocks while waiting for an event, a lower-priority ready task can run.
Important: Priority values and scheduling behavior depend on the RTOS configuration. In FreeRTOS, a numerically higher task priority means a higher priority.












3. Context Switching 🔄
A context switch occurs when the CPU stops executing one task and switches to another task.
The context includes information needed to resume execution, such as CPU registers and the task's stack pointer.
How it works
1. Task A is executing.
2. A scheduling event occurs.
3. The RTOS saves the necessary context for Task A.
4. The RTOS restores the context of Task B.
5. Task B continues from where it previously stopped.
Common reasons for a context switch include:
- A task blocks or yields.
- A delay expires.
- A higher-priority task becomes ready.
- An interrupt wakes a task, and scheduling selects that task.
Example
Task A is reading a sensor. It waits for 100 ms using vTaskDelay().
While Task A is blocked, the scheduler can run Task B, which processes received UART data.
When Task A's delay expires, it becomes ready again. It executes when selected by the scheduler.
Why is context switching useful? It allows multiple tasks to share one CPU while maintaining separate execution states.












4. Stack 📚
A stack is a memory area used to store temporary execution information, including function-call data, local variables, and saved registers.
In an RTOS, each task typically has its own stack.
Example
void SensorTask(void *argument)
{
    int temperature = 25;
    int humidity = 60;

    while (1)
    {
        read_sensor();

        vTaskDelay(pdMS_TO_TICKS(100));
    }
}


The local variables and function-call information require stack space. The exact placement of objects depends on compiler optimization and their lifetime.
Why does each task need a stack?
Imagine Task A is paused inside a function while Task B executes. When Task A resumes, it must retain its own execution information.
Separate task stacks help preserve this information.
What happens if the stack is too small?
A stack overflow can corrupt memory, damage another task's data, or cause a processor fault.
How to prevent it
- Allocate sufficient stack for each task.
- Avoid unnecessarily large local arrays.
- Avoid uncontrolled recursion.
- Enable FreeRTOS stack overflow checking.
- Monitor task stack usage during testing.
STM32 note: Cortex-M processors use the Main Stack Pointer (MSP) and Process Stack Pointer (PSP). FreeRTOS tasks commonly use PSP in Thread Mode, while exception handling uses MSP in Handler Mode under the standard Cortex-M FreeRTOS port configuration.











5. Priority 🎯
A task's priority indicates its scheduling importance.
In a priority-based RTOS, a ready task with a higher priority can preempt a lower-priority running task when preemption is enabled.
Example
Task	Priority	Purpose
Emergency Task	5	Respond to critical events
Motor Task	4	Control motor operation
Sensor Task	2	Read sensors
Logging Task	1	Print diagnostic information
Suppose the Logging Task is running and the Emergency Task becomes ready. With preemptive priority scheduling, the Emergency Task can take over the CPU.
Priority inversion
Priority inversion happens when a high-priority task is blocked waiting for a resource held by a lower-priority task.
A medium-priority task can make the situation worse by preventing the lower-priority task from running and releasing the resource.
FreeRTOS mutexes support priority inheritance, which can help mitigate this problem.
Good practice: Assign priorities according to timing requirements, not simply according to which task seems more important.












6. Semaphore 🚦
A semaphore is a synchronization mechanism used to coordinate tasks and events.
In FreeRTOS, the two common types are binary and counting semaphores.
Binary semaphore
A binary semaphore has two logical states: available and unavailable.
It is often used to signal that an event has occurred.
Example: A sensor interrupt indicates that new data is ready. The ISR gives a semaphore, and a task wakes up to process the data.
SemaphoreHandle_t sensorSemaphore;

void SensorTask(void *argument)
{
    while (1)
    {
        if (xSemaphoreTake(
                sensorSemaphore,
                portMAX_DELAY) == pdTRUE)
        {
            process_sensor_data();
        }
    }
}


This assumes the semaphore has been created and the ISR gives it appropriately.
Counting semaphore
A counting semaphore maintains a count rather than just two states.
It can represent multiple available resources or count repeated events, within its configured limit.
Why use a semaphore?
- Synchronize tasks with events.
- Notify a task that work is ready.
- Coordinate task execution with an ISR.
- Track a limited number of available resources.
Important: A semaphore is not automatically a mutual-exclusion lock. When exclusive ownership of a shared resource is needed, a mutex is often more appropriate.












7. Mutex 🔐
A mutex (mutual exclusion) is used to protect a shared resource so that only one task at a time owns it.
For example, two tasks may both need to write to the same UART interface. Without coordination, their messages could become interleaved.
Example
SemaphoreHandle_t uartMutex;

void TaskA(void *argument)
{
    while (1)
    {
        if (xSemaphoreTake(
                uartMutex,
                portMAX_DELAY) == pdTRUE)
        {
            send_message_A();

            xSemaphoreGive(uartMutex);
        }

        vTaskDelay(pdMS_TO_TICKS(100));
    }
}


Task B would use the same mutex around its UART operation.
The mutex must be created before use, and every successful take must have a corresponding give.
Semaphore vs Mutex
Feature	Semaphore	Mutex
Main purpose	Signaling or resource counting	Mutual exclusion
Ownership	No mutex-style ownership	Has an owning task
Typical ISR use	Some semaphore APIs support ISR use	Do not use a mutex from an ISR
Priority inheritance	Not generally provided by binary/counting semaphores	Supported by FreeRTOS mutexes
Critical rule: Never use a blocking mutex operation inside an ISR. Interrupt handlers should be short and use APIs specifically designed for interrupt context.














8. Queue 📬
A queue transfers data between tasks or between an ISR and a task using a controlled communication mechanism.
Unlike a simple flag, a queue can hold actual data items.
Example
One task reads a sensor and sends the reading to another task.
QueueHandle_t sensorQueue;

void SensorTask(void *argument)
{
    int temperature;

    while (1)
    {
        temperature = read_temperature();

        xQueueSend(
            sensorQueue,
            &temperature,
            portMAX_DELAY
        );

        vTaskDelay(pdMS_TO_TICKS(100));
    }
}


Another task receives the value:
void DisplayTask(void *argument)
{
    int receivedTemperature;

    while (1)
    {
        if (xQueueReceive(
                sensorQueue,
                &receivedTemperature,
                portMAX_DELAY) == pdTRUE)
        {
            update_display(receivedTemperature);
        }
    }
}


Here, sensorQueue must have been created with a suitable item size, such as sizeof(int), and sufficient queue length.
Why use a queue?
- Pass sensor readings between tasks.
- Send commands to a motor-control task.
- Buffer UART messages.
- Transfer work requests to a background task.
FreeRTOS queues copy queue items. If an item contains a pointer, the pointer is copied, not the memory it points to, so lifetime and ownership must be handled carefully.















9. Task Notification 🔔
A task notification is a lightweight mechanism that sends a signal or value directly to a particular task.
FreeRTOS task notifications can be used to:
- Wake a task.
- Signal an event.
- Increment a notification count.
- Pass a small value or bit flags.
Example
A task waits for a notification:
void WorkerTask(void *argument)
{
    uint32_t notificationValue;

    while (1)
    {
        if (xTaskNotifyWait(
                0,
                UINT32_MAX,
                &notificationValue,
                portMAX_DELAY) == pdTRUE)
        {
            process_event(notificationValue);
        }
    }
}


Another task can send a notification:
xTaskNotify(
    workerTaskHandle,
    1,
    eSetValueWithOverwrite
);


The handle must refer to an existing task, and the notification action must match the intended use.
Queue vs Notification
- Queue: Best when transferring multiple data items or buffering messages.
- Task notification: Often simpler and more memory-efficient when signaling one task or passing a small value directly to it.













10. ISR vs Task ⚡
An ISR (Interrupt Service Routine) executes in response to a hardware or software interrupt. A task is scheduled by the RTOS and executes in normal task context.
Example
Suppose a UART receives a byte.
1. The UART hardware generates an interrupt.
2. The UART ISR handles the immediate event.
3. The ISR stores or signals the received data.
4. A task processes the complete message later.
This keeps the interrupt handler short and allows the RTOS to schedule the more time-consuming work.
ISR vs Task
Feature	ISR	Task
Trigger	Interrupt event	Scheduler
Execution context	Handler Mode on Cortex-M	Usually Thread Mode
Can block?	No	Yes, when permitted
Own stack?	Uses exception stack behavior, not a separate RTOS task stack	Has its own task stack
Priority	Interrupt priority	RTOS task priority
Typical work	Acknowledge interrupt, capture data, signal task	Process data, communicate, perform longer operations
Important FreeRTOS rule
Inside an ISR, use APIs specifically designed for ISR use, such as xSemaphoreGiveFromISR() or xQueueSendFromISR() where appropriate.
Do not call blocking APIs from an ISR.














11. Critical Section 🛡️
A critical section is a region of code that must not be interrupted or accessed concurrently in a way that would corrupt shared state.
For example, the main task and an interrupt handler may both access a shared counter.
volatile uint32_t sharedCounter = 0;


If both contexts modify it without suitable protection, updates can be lost.
FreeRTOS critical-section example
taskENTER_CRITICAL();

sharedCounter++;

taskEXIT_CRITICAL();


This is a simplified task-context example. Use the appropriate critical-section API for the context and port.
What does it protect against?
A correctly implemented critical section can prevent certain interrupt preemptions or concurrent operations for a short period.
Important precautions
- Keep critical sections very short.
- Do not perform long calculations inside them.
- Do not block or delay inside them.
- Understand which interrupts the critical-section mechanism masks.
- Remember that disabling interrupts is not a universal solution for every concurrency problem, especially with DMA or multiple processors.
For shared resources between tasks, a mutex is often preferable because it allows other ready tasks to execute while a task waits for the resource.












12. Especially Important: Thread Mode vs Handler Mode 🧠
This is a fundamental ARM Cortex-M concept, including for your STM32F401RBT6.
The Cortex-M processor has two execution modes:
- Thread Mode: Runs normal application code.
- Handler Mode: Runs exception and interrupt handlers.
These are processor execution modes, not RTOS task states.
Thread Mode
Thread Mode is where normal application code runs.
Examples:
- main()
- FreeRTOS tasks.
- Ordinary C functions called by tasks.
- Background application processing.
When the processor starts after reset, it begins executing the reset handler in Thread Mode. The reset handler then performs startup initialization and eventually calls main().
In a typical FreeRTOS application, the scheduler runs tasks in Thread Mode.
Handler Mode
Handler Mode is entered when the processor handles an exception or interrupt.
Examples:
- SysTick_Handler()
- USART2_IRQHandler()
- EXTI0_IRQHandler()
- HardFault_Handler()
The processor automatically saves part of the interrupted context on exception entry, and the handler executes to deal with the event.
Handler Mode is left when the processor returns from the exception.
Thread Mode vs Handler Mode
Feature	Thread Mode	Handler Mode
Purpose	Normal application execution	Exception and interrupt handling
Runs tasks?	Yes	No; executes handlers
Runs main()?	Yes	No
Can block using RTOS APIs?	Yes, when the API and task state permit it	No
Priority	Uses task context and scheduling	Uses exception/interrupt priority
Stack	MSP or PSP, depending on configuration	Uses MSP on Cortex-M
Typical example	SensorTask()	USART2_IRQHandler()
MSP and PSP — how do they relate?
The Cortex-M processor has two stack pointers:
- MSP (Main Stack Pointer): Used for reset and by Handler Mode.
- PSP (Process Stack Pointer): Often used for RTOS tasks in Thread Mode.
In a typical FreeRTOS Cortex-M4 setup:
- SensorTask() executes in Thread Mode using PSP.
- USART2_IRQHandler() executes in Handler Mode using MSP.
- The RTOS scheduler and exception-handling code coordinate switching between task contexts.
The exact setup depends on the startup configuration and RTOS port.
Practical example: UART interrupt and task
UART receives a byte
Hardware event

UART ISR — Handler Mode
Capture data and notify a task using an ISR-safe API

RTOS schedules a task
The notified task becomes ready

UART processing task — Thread Mode
Parse the message and update the application
