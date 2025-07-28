# Q} What is Karnaugh(K) map?
- A Karnaugh map (K-map) is a pictorial method used to minimize Boolean expressions without having to use Boolean algebra theorems and equation manipulations.
- A K-map can be thought of as a special version of a truth table .

# Advantages of K-Maps

- The K-map simplification technique is simpler and less error-prone compared to the method of solving the logical expressions using Boolean laws.
- It prevents the need to remember each and every Boolean algebraic theorem.

### Embedded Operating System:-

# Q}What is an Embedded System?
  - An Embedded system is a computer system that is part of a larger system or machine.
  - It is a system with a dedicated function.
  - Examples are digital watches , electronic calculators , GPS System

  * Use:
   - The purpose of embedded systems is to control a specific function within a device.
  
  * Advantages:-
  - Simple to deliver higher creation.
  - Less costs for per bit of resultant.
  - It has not many interconnections.
  - It has Better steady and Higher speed.
  - Versatile because of little in size.

# Q}What is OS ?
 - An operating system is system software (collection of programs)that manages computer hardware and software resource and provide common service for the computer programs.
 - Interface between end user and computer hardware.
 - Interface between Programs and computer hardware.
 - kernel is a core part of operating system which runs continously into memory and does basic minimal functionality.
 - the main task of operating system is the allocation of resource and service.
 - Bootable CD/DVD = Core OS + Applications + Utilities
 - Core OS = Kernel -- Performs all basic functions of OS.

# functions of operating system?
 # 1. Process management:
    - all the process are kept in ready queue for execution.
    - os decide order of process and how much time for processing the process.
 # 2. Memory Management:
    - os keep track of primary memory.
    - that which byte of memory is used by which user program.the memory address that have been allocated and memory address that are not been used.
 # 3. cpu scheduling:
    - cpu scheduling  is process of determining that which process get cpu first for execution 
    - used to schedule the process that are waiting in ready queue for execution and allocating cpu to it.
    - main task of cpu scheduling is cpu is never ideal ..atleast one process in ready queue.
 # 4.file management:
    - it keep track of where the information is stored...user access and status of every file and more.

# Q] what is system call?
   - function exposed by kernel so that user can access kernel functionality are called as system calls.
   - system call invoke kernel functionality to do specific task.
   - for ex - fork(),open(),read(),write(),close()

# Q] multiprogramming:
   - multiple programs from secondary memory load it into main memory at a time for execution.
# Degree of multiprogramming:
   - no of programs from secondary memory load it into main memory at a time for execution.
# Q] Multitasking:
   - cpu can execute multiple program cocurrently / simultanously
   - cpu time is shared among all the process so also called as time sharing.

# Q] Multithreading:
   - execution of programs that allows for creating multiple threads within process .
   - all this thread executes independently and concurrently sharing resource.
   - ex : web brower(multiple tabs are open at same time).
   - one bike drive by 1 people
# Q] Multiuser:
   - multiple user can execute same process at a time 


# Q] multiprocessing: 
     multiple cpu are utilized for execution of program
   - technical example : fork() --> fork create duplicate process which is exact copy of calling process.
   - real life example:one  bike drive by 5 people
   - the process in which multiple process are connected in close ckt.

# Q} Difference between general purpose os and embedded systems:
                     GP                                                                                            ES
  - It is designed using microcontroller as the main processing unit       - It is mostly designed using a microcontroller as main processing unit.
  - It contains large memory , semiconductor memories like cache and       - It uses semiconductor memories but doesnt require secondary memories 
    RAM.It also contains secondary storage like harddisk , etc.               like harddisk , CD.It sometimes has a spl memory called as flash memory.
  - It is designed such that it can cater to multiple tasks as per         - It is designed such that it can cater to particular predefined tasks.
    requirement.                                                              
  - It is mostly costlier compared to embedded systems.                    - It is cheaper compared to general purpose os.
  - It rrequires huge number of peripheral devices and their controllers   - It is cheaper as it requires less number of peripheral devices and 
                                                                            controllers and microcontroller chip itself.
 
 # what are linux IPC Mechanism                                               
  - process can not access memory of another process directly .so os provide ipc mechanism so  that process can communicate with each other.
 # 1. Signal:
    - A Process can send signal to another process or os can send signal to the process.
    - "kill -i" command is used to send the signal to the another process.
    - signal is exactly similar like interrupt. that it gives notification to the process that some high prority event occur that need immediate attention.
    - when any signal is recieved by process then os can pause the current execution and check entry of signal in signal handler table and then it will execute perticuler signal ...after handling it will resume the current execution.
 # 2. pipe: it is unidirectional communication
   - pipe is an interprocess communication. pipe is the mechanism by which output of one process is directed into the input of another process
   - used to communicate between to process
   - if pipe is empty then reading process will block.
   - and if pipe is full theb writing process will block.
   - two types of pipe :
   # named pipe :
     - also known as fifo
     - fifo is special kind of file location on the local storage. which allows two or more process to communicate with each other.
   # unnamed pipe : 
     - used to communicate between two related process.
 
 # message queue:
   - message queue is used to transfer packets of data to one process to another process.
   - message queue is packet base communication each process have some finite size.
   - in message queue message is not directly send one process to another process ...one process first send message to the kernel and then kernel send this message to the another process.
   - in message queue basically two operation are performed one is send msg and another is recieve msg
   - if P and Q are two prcoess and they want to communicate with each other then they must send and recieve msg to each other,for that communication link must exits betweent them.
   - ex : chat program used in word wide web to communicate one process to another process by exchanging msg.
 # shared memory:
   - in shared memory process can access " same memory " location for communication 
   - process A can send data to memory  location and process B can recieve data from that memory location
    - process A -> Write and Process B read
  # advantage of shared memory:
    - problem with pipe fifo and msg queue is that process can exachage their information and information has go through the kernel...but size of kernel is 8kb.

  # Disadvantages:
    - when two or more process trying to access same memory location at a time ,then get unexpected result may occured.
# Race condition:
  - when multiple process trying to acces same resource at the same time is known as race codition.
  - when race condition occur resource get corrupted.
  - fork()-- when parent and child process access same memory location race condition occur.
  # resolve race condition: only one process can access resource at a time
# Critical section: 
  - when block of code can executed by only one process at a time is called as critical section.
  - if multiple process trying to access same code concurrently it may produce unexpected result.
  - ex - doubly circular linked list...adding node at specific position
   to avoid this sunchronization is used .

## various synchronization mechanishm is used : (semaphore and mutex)
  # semaphore : 
    - semaphore is syncronization object given by os.
    - internally semaphore is a counter. on semaphore two operation is performed.

   # wait: decrement operation
     - in wait semaphore count is decrement by one.
     - if count < 0  then calling process is blocked.
     - wait operation is performed before accesing the resoure.
   # signal:increment operation
     - semaphore operation is incremented by 1.
     - if one or more are blocked ..one of the process will resume.
     - signal operation is performed after the resource.
  
  # types of semaphore:
   # 1 . counting semaphore:
     - Allow "n" number of processes to access resource at a time.
     - Or allow "n" resources to be allocated to the process.
     - initialization of counting semaphore is n.
     - each process---> p(s); 
                      dec by 1
                          |
                      use resoure 
                          |
                      v(s);incr by 1
  # 2. Mutual exclusion or binary semaphore or mutex:
     - Allow only one  processes to access resource at a time.
     - initially count is 1;
     - each process 
                    p(S);//dec by 1 // i.e wait operation
                        | 
                    use resource;
                        |
                    v(s);increment operation//signal operation
  # Q}. If sema count = -n, how many processes are waiting on that semaphore?
       Answer: "n" processes waiting

  # Q} If sema count = 5 and 3 P & 4 V operations are performed, then what will be final count of semaphore?
       Ans: 5 - 3 + 4 = 6   

# Mutex: 
   - it is insure that only one process can access the resoure at a time is called mutec.
   - mutex is same as binary semaphore.
   - mutex can be unlock /block  by same process which had locked it.

# difference between semaphore and mutex:
semaphore : semaphore is a counter (counting and binary).
mutex     : its function is same as bianry semaphore .
semaphore : having two operation is perfomed wait and signal .
mutex     : having two state locked and unlocked.
semaphore : allow "n" no of process to access resource at at time. 
mutex     : allow only one process to access resource at a time.
semaphore : semaphore count can be increment or decrement by one.
mutex     : only owner can unlock the process .

# What is semaphore?
 when process is holding the resource and wait for to obtained hold by another process.

 # deadlock occur:
   deadlock occur when all 4 condition hold true 
   1 : No preemption: not giving up until task is completed.
   2 : mutual exclusion: resoure is not shareable.
   3 : hold & wait: process hold resource and wait for another resource.
   4 : circular wait : p1 has p2 want p3 p3 has p4 want p1

 # prevention : 
   at least one deadlock condition hold true.
 # deadlock avoidance
   - process declare the require resoure in advance
   # resource allocation graph
   # bankers algorithm
   # safe state algorithm

# difference deadlock and starvation:
deadlock : when one process is hold and wait for to obtained hold by another process.
stravation:starvation occur when process wait indefinite time to obtained required resource.
deadlock : in deadlock all the related process cannot be proceed.
stravation:high priority process get executed where low priority get blocked.
deadlock : resoure are blocked by process.
stravation:resoure are continously utilized by high priority process.
deadlock : deadlock occur when 4 condn hold true.
stravation:starvation occur when priority is assign to the process.
deadlock : prevented when at least one condition not hold true.
stravation:prevented by aging increase priority gradually.

# thread concept :
 - for each process one thread is created bydefault called as main thread 
 - thread are used to execute multiple task concurrently in the same process.
 - thread is light weightes:
       - bcz each thread new control block and stack is created other section(text,data,heap)
       are shared with parant process.
       - interthread communication is more faster than interprocess communiction.
       - context switch between two threads in the same process is faster.
 - thread stack is used to create function activation record

# Q}Concept of multithreading and write one application of multithreading and also write what problems occur in multithreading and its solution.
 - multithreading is the process of executing multiple task concurrently and indepedently within a process .
 ex : web brower (multiple tab opend and work indepently and concurrently)

# Some multithreaded applications would be:
1)Web Browsers - A web browser can download any number of files and web pages (multiple tabs) at the same time and still lets you continue browsing. 
If a particular web page cannot be downloaded, that is not going to stop the web browser from downloading other web pages.
2)Web Servers - A threaded web server handles each request with a new thread. There is a thread pool and every time a new request comes in,
 it is assigned to a thread from the thread pool.
3)Computer Games - You have various objects like cars, humans, birds which are implemented as separate threads. 
Also playing the background music at the same time as playing the game is an example of multithreading.
4)Text Editors - When you are typing in an editor, spell-checking, formatting of text and saving the text are done concurrently by multiple threads. 
The same applies for Word processors also.
5)IDE - IDEs like Android Studio run multiple threads at the same time. You can open multiple programs at the same time. 
It also gives suggestions on the completion of a command which is a separate thread.

# Problems in multithreading:-
> Increased Complexity − Multithreaded processes are quite complicated. Coding for these can only be handled by expert programmers.
> Complications due to Concurrency − It is difficult to handle concurrency in multithreaded processes. This may lead to complications and future problems.
> Difficult to Identify Errors− Identification and correction of errors is much more difficult in multithreaded processes as compared to single threaded processes.
> Testing Complications− Testing is a complicated process i multithreaded programs as compared to single threaded programs.
 This is because defects can be timing related and not easy to identify.
> Unpredictable results− Multithreaded programs can sometimes lead to unpredictable results as they are essentially multiple parts of a program that are running at the same time.
> Complications for Porting Existing Code − A lot of testing is required for porting existing code in multithreading. 
Static variables need to be removed and any code or function calls that are not thread safe need to be replaced.

#Solutions:-
>Avoid Nested Locks: This is the main reason for deadlock. Deadlock mainly happens when we give locks to multiple threads.
>Avoid Unnecessary Locks: You should lock only those members which are required. Having unnecessary locks can lead to a deadlock.


# Q}Solution of shared memory problem using semaphore and mutex:-
  - problem occur in shared memory is race condition.
  race codn : when multiple process trying to acces same resoure at a time is called as race condition.
  - to avoid race condition use synchronization. binary semaphore
  - binary semaphore is all to access only one resoure at a time.
               each process
                  |
                p(s)
             use resource
                  |
                v(s)
                  


# Q}Which is the fastest IPC Mechanism?
- Shared memory is the fastest form of interprocess communication.

# difference between process and thread
process : process is program under execution
thread  : thread is segment of  process means process can have multiple thread
process : create using fork()
thread  : create using pthread_create()
process : heavy weight process
thread  : light weight process 
process : more time for creation
thread  : less time for creation
process : less efficient for communication
thread  : more efficient for communication
process : more time for context switch
thread  : less time for cotext switch


# process creation:
  - fork() create new process which is exact dublicate copy of calling process or parent process
  new process ==> child process.
  calling process  ==>parent process.

  # on succes : 
      - it return pid of child process to parent.
  # on failure :
      - it return -1
  - both process schedule seperate by sheduler.
  - based on cpu time both process get execute concurrently.

# thread creation: using pthread_create()
  - for each thread ,one thread is create by default called as main thread which execute entry point function of process
  - when main thread terminated process get terminate
  - when process get terminated all thread get terminated.
  - thread will terminate when thread function is completed.

# content of process:
 1. text section : instruction given to the cpu or machine level code
 2. data section : static and global data
 3. stack: space to run function in program ,local variable,parameter  and to hold return status
 4. file discripter : table : open file system
 5. pending singal : signal recive but not handled
 6. cpu register : value in cpu register
 7. kernel data
 8. address space:difference betn lowest adrs and highest address is called address space
 9. thread of execution

# Note : 
  - kernel never schedule process it always schedule thread bcz thread is running entity.
  ex  : rat inside the box
  - loader create main thread by calling exec exec function ...and exec function is called by
    fork.
#   Q] how process and thread analogus:
  - process can be create by using two method.
  1. create process with exec ==>heavy weighted process
  2. create process without exec  ==> light weighted process

  - when exec is used then kernel use more resource 
  - without exec less resource is used

  # system alwaus favour light weight process 
    - i.e fork and vfork() without exec.
    -bcz less resoure are use.

- embedded system favours multithreading rather than multiprocessing
   - ex : multithreading : bike drive one person
   - ex : multiprocessing : bike drive 5 person

# Q] why exec process are heavy weighted
  - bcz more resouce is used so more memory, more register
  and so they are heavy weighted so cost is high.

# Q] when to call fork and vfork?
  - when more memory available then use fork() with or without exec.
  - when we dont have large amount of memory vfork() use exec or without exec
  - when we have to run process asynchronously or they are independent of each other then go for fork()  syscall
  - when we have to run process synchronously parent process execute after completion of child process then vfork is used

# Q] why to call fork and vfork
  fork : fork does not have any wait 
  vfork : vfork have inbuilt wait parent wait for child till child is not terminated.
  fork : while calling fork new process is created which exact dublicate of calling process 
         in that seperate address space created for child and parent
  vfork : when child process created parent process save execution context and get this 
         address space for child for execution.
  fork : seperate address space so more memory is require
  vfork: no seperate address space so less memory is require
 
# Q}What are the structures in eos?
The structure of the OS depends mainly on how the various common components of the operating system are interconnected and melded into the kernel.
1)Simple OS structure:-
Such operating systems do not have well defined structure and are small, simple and limited systems. 
The interfaces and levels of functionality are not well separated. 
Small Operating systems like MS-DOS or few embedded OS follow a very simple structure.
DOS operating system is made up of three files only.
COMMAND.COM <- command interpreter
MSDOS.SYS <- kernel
IO.SYS <- device drivers

2)Layered structure (architecture):-
An OS can be broken into pieces and retain much more control on system. 
In this structure the OS is broken into number of layers (levels). 
The bottom layer (layer 0) is the hardware and the topmost layer (layer N) is the user interface.
OS is divided into multiple layers, so that each layer depends on the lower layer and provide functionality to the upper layer.
Example: Windows, UNIX, Linux, etc.
Windows OS have following layers
applications
system call APIs
system call implmenetation
Kernel Executive : File Mgr, Memory Mgr, Process Mgr, Scheduler, Thread Mgr, etc.
IO Subsystem
Device Drivers
Hardware Abstraction Layer

# Q} What is a zombie process??
- A zombie process is a process whose execution is completed but it still has an entry in the process table.
- Zombie processes usually occur for child processes, as the parent process still needs to read its child’s exit status. 
- Once this is done using the wait system call, the zombie process is eliminated from the process table. This is known as reaping the zombie process.

# Q}What is spinlock in os with example??
- Spinlock is a locking system mechanism. 
-It allows a thread to acquire it to simply wait in loop until the lock is available i.e. a thread waits in a loop or spin until the lock is available. 
- Spinlock is held for a short period of time. 
- Spinlock are useful in multiprocessor system.

# Q}Difference between spinlock and semaphore 
Spinlock	                                                                              Semaphore
- It may be used for mutual exclusion.                                         -It may be used either for mutual exclusion or a counting semaphore.
- Spinlock is a low-level synchronization technique.	                          -It is a signaling mechanism.
- If a spinlock is held for a long time, it may be wasteful.	                  -There is no resource wastage of resources and process time.
- Spinlocks are very effective because they are blocked only for a               -It is held for a longer time, and it uses spinlock to get access to   short period of time.	                                                           its control structure.
- It permits only a single thread at a time to acquire the lock and              -It permits multiple threads to access the critical section.
 proceed it with a critical section.
- It is a busy-wait process.	                                                   -It is a sleep wait process.
- Spinlocks are ineffective in uniprocessor systems because they keep            -Semaphore is helpful in uniprocessor systems since they
the processor busy each time it polls the lock and prevents any other             do not keep the processor busy while waiting for the lock.
process from functioning.                                         
- It may have only two values which are Locked and Unlocked.	                  -The mutex will have a value 1 or 0, but it may have different values
                                                                                if used as a counting semaphore
                                                                            
- It permits only a single process at a time to access in the                  -	It permits several processes at any particular time to access the 
 critical section.                                                                               critical section.
- While holding a spinlock, it is recommended to disable the interrupts.	      -It may be locked with interrupt enabled.
- It is valid for only a single process.	                                      -It may be used to synchronize between many processes.
