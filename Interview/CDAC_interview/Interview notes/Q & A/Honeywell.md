## Q}What is a kernel ?
The kernel is a computer program at the core of a computer’s operating system and has complete control over everything in the system. It manages the operations of the computer and the hardware.

## Q} What is the difference between micro kernel and macro kernel?
# Micro kernel 
It is a kernel which runs services those are minimal for operating system performance. In this kernel all other operations are performed by processor.In microkernel the user services and kernel services are implemented in different address space. The user services are kept in user address space, and kernel services are kept under kernel address space.
Example : Mac OS X.

# Macro Kernel 
It is a combination of micro and monolithic kernel. In monolithic kernel all operating system code is in single executable image.
The user services and kernel services are implemented in same address space.
Example : Microsoft Windows 95.

## Q} What is the different computer architecture?
Computer architecture is the organisation of the components which make up a computer system and the meaning of the operations which guide its function.

# THE THREE CATEGORIES OF COMPUTER ARCHITECTURE
There are three categories of computer architecture, and all work together to make a machine function.
# 1) SYSTEM DESIGN
System design includes all hardware parts of a computer, including data processors, multiprocessors, memory controllers, and direct memory access. It also includes the graphics processing unit (GPU). This part is the physical computer system.
# 2)INSTRUCTION SET ARCHITECTURE (ISA)
This includes the functions and capabilities of the central processing unit (CPU). It is the embedded programming language and defines what programming it can perform or process. This part is the software that makes the computer run, such as operating systems like Windows on a PC or iOS on an Apple iPhone, and includes data formats and the programmed instruction set.
# 3) MICROARCHITECTURE
Microarchitecture is also known as computer organisation and defines the data processing and storage element and how they should be implemented into the ISA. It is the hardware implementation of how an ISA is implemented in a particular processor.

# Q}Explain what is the requirement in MIMD?
MIMD stands for 'Multiple Instruction and Multiple Data Stream'.
In this organization, all processors in a parallel computer can execute different instructions and operate on various data at the same time.In computing, multiple instruction, multiple data (MIMD) is a technique employed to achieve parallelism. Machines using MIMD have a number of processors that function asynchronously and independently. At any time, different processors may be executing different instructions on different pieces of data.
In MIMD, each processor has a separate program and an instruction stream is generated from each program.

# Q}Difference between SIMD and MIMD
SIMD stands for Single Instruction Multiple Data. MIMD stands for Multiple Instruction Multiple Data.
In SIMD design, one instruction is applied to a bunch of information or distinct data at constant time. SIMD is less efficient in terms of performance than MIMD.
On the other hand, MIMD design applies multiple directions over totally different information at the same time. MIMD is more efficient in terms of performance than SIMD.
The main difference between SIMD and MIMD is that, SIMD has single decoder. Whereas MIMD have multiple decoders.

# Q}Difference between array and linked list
An array is a collection of elements of a similar data type.
A linked list is a collection of objects known as a node where node consists of two parts, i.e., data and address.

Array elements store in a contiguous memory location.	
Linked list elements can be stored anywhere in the memory or randomly stored.

Array works with a static memory. Here static memory means that the memory size is fixed and cannot be changed at the run time.	The Linked list works with dynamic memory. Here, dynamic memory means that the memory size can be changed at the run time according to our requirements.

Array elements are independent of each other.	
Linked list elements are dependent on each other. As each node contains the address of the next node so to access the next node, we need to access its previous node.

Array takes more time while performing any operation like insertion, deletion, etc.
Linked list takes less time while performing any operation like insertion, deletion, etc.

Accessing any element in an array is faster as the element in an array can be directly accessed through the index.
Accessing an element in a linked list is slower as it starts traversing from the first element of the linked list.

In the case of an array, memory is allocated at compile-time.	
In the case of a linked list, memory is allocated at run time.

Memory utilization is inefficient in the array. For example, if the size of the array is 6, and array consists of 3 elements only then the rest of the space will be unused.	
Memory utilization is efficient in the case of a linked list as the memory can be allocated or deallocated at the run time according to our requirement.

# Q}  What is  Tree Data Structure?
A tree data structure is a hierarchical data structure that allows you to represent information in a hierarchy. It's most suited for storing information that can be segregated in different levels, and it's derived from the Tree itself.

# Q} Explain the different kinds of tree - Binary tree, Binary search tree, AVL tree?
# 1)Binary tree
A binary tree is a tree where each node can have at most 2 children like they can have zero, one, or two children. If they don't have any children, then they are known as leaf nodes.
Here is an example of a binary tree data structure, in this case, the root is 50, which has two children, 25 and 75. When you go one level down, node 25 again has two children, 10 and 49, which in turn doesn't have any children. They are called leaf nodes. Similarly, node 75 just has one child, 99, which is a leaf node.

# 2)Binary search tree
On the other hand, a binary search tree is a binary tree in which node values are assigned by the following rules:
i) The left subtree of nodes can only have values less than the node itself, I mean all nodes in the left subtree will be less than the root.
ii) The right subtree of nodes can only have values greater than the nodes themselves, I mean all nodes in the right subtree will be higher than the root.
iii) No duplicate values are allowed
iv) The left subtree should also be a binary search tree
v) The right subtree should also be a binary search tree

These special properties of the binary search trees make it ideal for searching like you just need to compare the value you want to search with the node, and you almost rule out half of the node from the tree.

This algorithm is known as a binary search, and because of that, the tree is known as a binary search tree. The search only takes log2(N) time which means you can find a node by just comparing 4 values in a binary tree of 16 nodes (log2(16) = 4)

# 3)Balanced Tree (AVL)
 A regular Binary Search tree is not self-balancing, which means, depending on the order of insertions, you will get different time complexities. For example;
if you inserted nodes in the order {2, 3, 1}, the BST would be O( log(N) ) for searching a node, but if you inserted {1,2,3}, then the BST will be O( N ), like a linked list because all the nodes will be on the right subtree and left subtree will be empty.
A completely un-balanced binary tree is actually a linked list, just like in the above case, and then searching will be O(n) instead of O(logN).
On the other hand, A balanced tree-like AVL or Red-Black tree will reorganize itself so that you will always get O( log(N) ) complexity.

# Q}Which data structure is used in expression evaluation?
The stack data structure is very effective in evaluating arithmetic expressions. Expressions are usually represented in what is known as Infix notation, in which each operator is written between two operands (i.e., A + B).

# Q}Can you explain why paging is used?
Paging is a memory management technique in which the memory is divided into fixed size pages. Paging is used for faster access to data. When a program needs a page, it is available in the main memory as the OS copies a certain number of pages from your storage device to main memory. Paging allows the physical address space of a process to be noncontiguous.
Paging is to deal with external fragmentation problem. This is to allow the logical address space of a process to be noncontiguous, which makes the process to be allocated physical memory.

# Q}What is meant by polymorphism?

# Q}Can you write a program to implement polymorphism?

# Q}Explain what are the differences between Pascal and C?
C language was found by Dennis Ritchie in 1972.	
Pascal language was found by Niklaus Wirth in 1969. Name of this language is kept Pascal in the honor of ‘one of the great french mathematician & philosopher named “Blaise Pascal“‘.

C language is influenced by ALGOL 68, BCPL, Assembly , Fortran, PL/I. etc.	
This Language was influenced by ALGOL 60.

In C language, semicolon (;) is used as statement terminator.	
In Pascal language, semicolon (;) is used as statement separator.

/* comment */, // comment, are used for comments.	
{comment} – curly braces and (* comment *) are used for  comments.

return, break and continue can be used in C.	
return, break and continue is not used in Pascal.

C language is case-sensitive.	
Pascal language is not case sensitive.

C does not have Boolean data type but have relational operators.	
Pascal have Boolean data type.

To define constant in C, #define is used.For ex : #define PI=3.14 ;
To define constant in Pascal, constant is used.For ex : constant PI = 3.14

Variable declaration in c :For ex : int x;
int x , y ;	Variable declaration in PascalFor ex : var x : integer ;
var x, y : integer;

Pointer variable declaration in C :For ex :    int *x;	
Pointer variable declaration in Pascal :For ex :     x:^integer

In C language, no such specific keyword is used in beginning or ending but “{“ and  “}” are used for block of statements.	
In Pascal, program starts with the keyword ‘program’ and then follows begin and end keywords.

In C pointer there is no such specific references. C Pointer allows references to all variables, object and functions.
In Pascal, Pointers does not reference static or local variable. It only allows reference to the anonymous and dynamically created variables i.e. Pointers are type safe in pascal.

C uses && , || and % .	
Pascal uses and , or and mod keyword.

# Q} In linux what command is used to sort the lines of data in a file in reverse order?
 sort - r


# Q} A system program that combines the separately compiled modules of a program into a form suitable for execution
 linking loader


# Q}  From the following which of them is a block device
Block devices are nonvolatile mass storage devices whose information can be accessed in any order. Hard disks, floppy disks, and CD-ROMs are examples of block devices.
A. mouse
B. printer
C. disk
D. terminal

ANS :- disk

# Q}  What are the advantages of using assembly language rather than machine language?
Assembly language is a low-level programming language . It equates to machine code but is more readable. It can be directly translated into machine code, but it uses mnemonics to represent the instructions to make it easier to understand.

# Q} Can you convert the expression ((A + B) * C - (D - E) ^ (F + G)) to equivalent Prefix and Postfix notations.

# Q} What is hashing ??
Hashing is the process of generating a value from a text or a list of numbers using a mathematical function known as a hash function.
A Hash Function is a function that converts a given numeric or alphanumeric key to a small practical integer value. The mapped integer value is used as an index in the hash table. In simple terms, a hash function maps a significant number or string to a small integer that can be used as the index in the hash table.
The pair is of the form (key, value), where for a given key, one can find a value using some kind of a “function” that maps keys to values. The key for a given object can be calculated using a function called a hash function. For example, given an array A, if i is the key, then we can find the value by simply looking up A[i].

# Q} Classify the Hashing Functions based on the various methods by which the key value is found.
# 1)Division Method.
This is the most simple and easiest method to generate a hash value. The hash function divides the value k by M and then uses the remainder obtained.
Formula:

h(K) = k mod M

Here,
k is the key value, and 
M is the size of the hash table.

# 2)Mid Square Method.
The mid square method is a very good hashing method. It involves two steps to compute the hash value-
Square the value of the key k i.e. k2
Extract the middle r digits as the hash value.
Formula:

h(K) = h(k x k)
Here,
k is the key value. 

The value of r can be decided based on the size of the table.

# 3)Folding Method.
This method involves two steps:

Divide the key-value k into a number of parts i.e. k1, k2, k3,….,kn, where each part has the same number of digits except for the last part that can have lesser digits than the other parts.
Add the individual parts. The hash value is obtained by ignoring the last carry if any.
Formula:

k = k1, k2, k3, k4, ….., kn
s = k1+ k2 + k3 + k4 +….+ kn
h(K)= s

Here,
s is obtained by adding the parts of the key k

Example:

k = 12345
k1 = 12, k2 = 34, k3 = 5
s = k1 + k2 + k3
  = 12 + 34 + 5
  = 51 
h(K) = 51

# 4)Multiplication Method.
This method involves the following steps:

Choose a constant value A such that 0 < A < 1.
Multiply the key value with A.
Extract the fractional part of kA.
Multiply the result of the above step by the size of the hash table i.e. M.
The resulting hash value is obtained by taking the floor of the result obtained in step 4.
Formula:

h(K) = floor (M (kA mod 1))

Here,
M is the size of the hash table.
k is the key value.
A is a constant value.

Example:

k = 12345
A = 0.357840
M = 100

h(12345) = floor[ 100 (12345*0.357840 mod 1)]
               = floor[ 100 (4417.5348 mod 1) ]
               = floor[ 100 (0.5348) ]
               = floor[ 53.48 ]
               = 53

# Q} Explain what is a spanning Tree?
A spanning tree is a subset of Graph G, which has all the vertices covered with minimum possible number of edges. Hence, a spanning tree does not have cycles and it cannot be disconnected..
By this definition, we can draw a conclusion that every connected and undirected Graph G has at least one spanning tree. A disconnected graph does not have any spanning tree, as it cannot be spanned to all its vertices.
We now understand that one graph can have more than one spanning tree. Following are a few properties of the spanning tree connected to graph G −

i)A connected graph G can have more than one spanning tree.

ii)All possible spanning trees of graph G, have the same number of edges and vertices.

iii)The spanning tree does not have any cycle (loops).

iv)Removing one edge from the spanning tree will make the graph disconnected, i.e. the spanning tree is minimally connected.

v)Adding one edge to the spanning tree will create a circuit or loop, i.e. the spanning tree is maximally acyclic.

# Q} What is meant by sequential search?
Linear search is a very simple search algorithm. In this type of search, a sequential search is made over all items one by one. Every item is checked and if a match is found then that particular item is returned, otherwise the search continues till the end of the data collection.

Linear Search 
Algorithm
Linear Search ( Array A, Value x)

Step 1: Set i to 1
Step 2: if i > n then go to step 7
Step 3: if A[i] = x then go to step 6
Step 4: Set i to i + 1
Step 5: Go to Step 2
Step 6: Print Element x Found at index i and go to step 8
Step 7: Print element not found
Step 8: Exit

# Q} Explain what is a priority queue?
A priority queue is a special type of queue in which each element is associated with a priority value. And, elements are served on the basis of their priority. That is, higher priority elements are served first.

However, if elements with the same priority occur, they are served according to their order in the queue.
Priority queue can be implemented using an array, a linked list, a heap data structure, or a binary search tree. Among these data structures, heap data structure provides an efficient implementation of priority queues.

# Q} If you are using C language to implement the heterogeneous linked list, what pointer type will you use?
The heterogeneous linked list contains different data types in its nodes and we need a link, pointer to connect them. It is not possible to use ordinary pointers for this. So we go for void pointer. Void pointer is capable of storing pointer to any type as it is a generic pointer type.

# Q} Can you tell whether Linked List is linear or Non-linear data structure?
linked list is basically a linear data Structure because it stores data in a linear fashion. A linear data Structure is what which stores data in a linear format and the traversing is in sequential manner and not in zigzag way.

# Q} Explain what does abstract Data Type Mean?
Abstract Data type (ADT) is a type (or class) for objects whose behaviour is defined by a set of value and a set of operations.

The definition of ADT only mentions what operations are to be performed but not how these operations will be implemented. It does not specify how data will be organized in memory and what algorithms will be used for implementing the operations. It is called “abstract” because it gives an implementation-independent view. The process of providing only the essentials and hiding the details is known as abstraction.

# Q} Explain what is a node class?
A node class is simply a class representing a node in a data structure. Data structures like lists, trees, maps, etc. consist of so-called nodes. And a representation of such a node in form of a C++ class is called a node class


# Q}Q}Explain what is a Real-Time System?
RTOS is OS in which accuracy of result is not only dependent on "correctness of the calculation", but also depeneds on "time duration" in which results 
are produced.
Three types of RTOS are 1) Hard time 2) Soft time ,and 3) Firm time.

## hard real time operating system
A hard real-time system (also known as an immediate real-time system) is hardware or software that must operate within the confines of a stringent deadline.
 The application may be considered to have failed if it does not complete its function within the allotted time span.
If interrupt/tasks deadline miss -- catastrophic effect.
Usually doesn't have secondary storage.
Timing: 10 to 100 "usec"
E.g. uC-OS, FreeRTOS, Xenomai, RTAI, ...

## What is soft real time system in OS?
Soft real time system is a system whose operation is degrade if results are not produce according to the specified timing requirement.
Less time critical - If deadline miss, affect product quality (not catastrophic).
May have secondary storaage
Timing: 1 ms to 10 ms
E.g. Linux (PREEMP_RT)etc.

## what is firm rtos
A firm real-time system is one in which a few missed deadlines will not lead to total failure, but missing more than a few may lead to complete or catastroph
ic system failure. Every firm real-time task is associated with some predefined deadline before which it is required to produce its results.
Like hard realtime.
Rare miss of deadline is acceptable (not catastrophic)

# Q}Can you tell what the difference between Hard is and Soft real-time systems

In hard real time system, the size of data file is small or medium.	                      
In soft real time system, the size of data file is large.

In this system response time is in millisecond.	                                             
In this system response time are higher.

Peak load performance should be predictable.	                                              
In soft real time system, peak load can be tolerated.

In this system safety is critical.	                                                     
 In this system safety is not critical.

A hard real time system is very restrictive.	                                            
  A Soft real time system is less restrictive.

In case of an error in a hard real time system, the computation is rolled back.        	
In case of an soft real time system, computation is rolled back to previously established a checkpoint.

Satellite launch, Railway signaling system etc.	                                            
 DVD player, telephone switches, electronic games etc.

# Q}Explain what is the important aspect of a real-time system?
Real-time system is responsible for the completion of all tasks within their time intervals.
Correctness: Correctness is one of the prominent part of real-time systems. Real-time systems produce correct result within the given time interval. 
1. Quick response to real-world events
2. Small memory foot print
3. Real time handling of interrupts
4. Preemptive scheduling
5. Rapid context switches etc

# Q} Explain what is segmentation?
Instead of allocating contiguous memory for the whole process, contiguous memory for each segment
can be allocated. This scheme is known as "segmentation".
Since process does not need contiguous memory for entire process, external fragmentation will be
reduced.
In this scheme, PCB is associated with a segment table which contains base and limit (size) of each
segment of the process.
During context switch these values will be loaded into MMU segment table.
CPU request virtual address in form of segment address and offset address.
Based on segment address appripriate base-limit pair from MMU is used to calculate physical address
as shown in diag.
MMU also contains STBR register which contains address of process's segment table in the RAM

# Advantages of Segmentation
No internal fragmentation
Average Segment Size is larger than the actual page size.
Less overhead
It is easier to relocate segments than entire address space.
The segment table is of lesser size as compared to the page table in paging.

# Disadvantages
It can have external fragmentation.
it is difficult to allocate contiguous memory to variable sized partition.
Costly memory management algorithms.

Q} Explain what is internal and external fragmentation?

# external fragmentation
If amount of memory required for a process is available but not contiguous, then it is called as "external
fragmentation".
To resolve this problem, processes in memory can be shifted/moved so that max contiguous free space
will be available. This is called as "compaction
# internel fragmentation
If process is not utilizing entire partition allocated to it, the remaining memory is wasted. This is called
as "internal fragmentation".

# Q} Explain what is meant by scheduler?
A scheduler is a type of system software that allows you to handle process scheduling. 
Three types of the scheduler are 1) Long term 2) Short term 3) Medium-term

# Q}  Explain what is a long term scheduler and short term schedulers??

###   Types of Schedulers
# Job scheduler - Long term scheduler
Multi-programming system: multiple programs loaded in main memory.
Better CPU utilization
Should be "mixture" of CPU bound and IO bound processes
CPU bound: CPU burst > IO burst
IO bound: CPU burst < IO burst
Job scheduler load the programs into main memory.
Used in older mainframe systems.

# CPU scheduler - Short term scheduler
Multi-programming system: multiple programs loaded in main memory.
If multiple programs are CPU bound, they need to wait for current program completion
(default implementation).
For better execution, we want to execute these programs concurrently.
Multi-tasking system: sharing CPU time among multiple tasks present in main memory and ready
for execution.
CPU scheduler pick the process to be executed on CPU from ready processes.
Algorithm used by CPU scheduler to pick a process is called as CPU scheduling algorithm


# Q}  Explain the benefits of multithreaded programming?
1. Resource Sharing
All the threads of a process share its resources such as memory, data, files etc. A single application can have different threads within the same address space using resource sharing.

2. Responsiveness
Program responsiveness allows a program to run even if part of it is blocked using multithreading. This can also be done if the process is performing a lengthy operation. For example - A web browser with multithreading can use one thread for user contact and another for image loading at the same time.

3. Utilization of Multiprocessor Architecture
In a multiprocessor architecture, each thread can run on a different processor in parallel using multithreading. This increases concurrency of the system. This is in direct contrast to a single processor system, where only one process or thread can run on a processor at a time.

4. Economy
It is more economical to use threads as they share the process resources. Comparatively, it is more expensive and time-consuming to create processes as they require more memory and resources. The overhead for process creation and management is much higher than thread creation and management

# Q} Bare-metal development
The program is burned into flash memory and execute without any OS on the chip.
Only Main SP is used (Program SP is never used).

# Q}Embedded OS based development
The program + Embedded OS is burned into flash memory and program execute with OS support.
Main SP is used for exception handler and embedded OS. Program SP is used for user program

# Q}  Explain what are operating system services?
An Operating System provides services to both the users and to the programs.
It provides programs an environment to execute.
It provides users the services to execute the programs in a convenient manner.
Following are a few common services provided by an operating system −

Program execution
I/O operations
File System manipulation
Communication
Error Detection
Resource Allocation
Protection

# Q} Explain what are deadlock prevention techniques?
Refer link of deadlock 

# Hardware vs Software vs Firmware
Hardware: Electronic circuit
Software: Program that can be easily installed/uninstalled on OS.
Firmware: Program that is fixed/burned into the ROM.

# Q} Explain the storage classes in C++?
C++ uses 5 storage classes, namely: 
auto
register
extern
static
mutable:-• In constant member function, if we want to modify state of non constant data member then we should 
use mutable keyword
using namespace std;
#include<iostream>

//Constant member functions
class Demo
{
    private:
    int val; // non constant 
    const int c; // constant 
    mutable int m; // mutable variables can be modified inside constant member functions

    public:
    Demo():val(5),c(99),m(10)
    { }
    //if we write keyword const in front of member function
    //then member function becomes constant 

    void disp() const
    {
        cout<<"\n Value = "<<val<<" Constant Var = "<<c<<" M value = "<<m;
        //val++; // val becomes read only over here
        //c++; //read only 
        m++; // ALLOWED 
     cout<<"\n Value = "<<val<<" Constant Var = "<<c<<" M value = "<<m;
    }

    void fn()
    {
        val++; // yes it is allowed
        //c++; // no it is not allowed 
    }
};

int main(void)
{
    Demo d;
    d.disp();
    return 0;


# Q}Explain what is a mission critical system?
A mission critical system is a computer, electronic or electromechanical system that is fundamentally necessary to the success of a specific operation.
 When a mission critical system fails or is interrupted, the damage is often quick and substantial.

