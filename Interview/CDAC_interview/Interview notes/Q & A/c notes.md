## Embedded C Programming:-

## explain compilation flow?

## difference function decleration and defination?

## function calling convention ?
  - STD CALL 
  - CDECL 
  - FAST CALL

## Q}Storage classes in c :

Storage classes in C are used to determine the lifetime, visibility, memory location, and initial value of a variable. There are four types of storage classes in C
>Automatic
>External
>Static
>Register

Classes	       Storage      DefaultValue	   Scope	       Lifetime
auto/local     Stack	     Garbage            Block	       Within function/Block
extern/global  Data section   Zero	           Program	       Till the end of the main program Maybe declared anywhere in the program
static	       Data section   Zero	          Local/Limited   Till the end of the main program, Retains value between multiple functions call
register       CPU Register   Garbage	          Block	       Within the function/Block

>>>Automatic:-
Automatic variables are allocated memory automatically at runtime.
The visibility of the automatic variables is limited to the block in which they are defined.
The scope of the automatic variables is limited to the block in which they are defined.
The automatic variables are initialized to garbage by default.
The memory assigned to automatic variables gets freed upon exiting from the block.
The keyword used for defining automatic variables is auto.
Every local variable is automatic in C by default.

#include <stdio.h>  
int main()  
{  
int a = 10,i;   
printf("%d ",++a);  
{  
int a = 20;   
for (i=0;i<3;i++)  
{  
printf("%d ",a); // 20 will be printed 3 times since it is the local value of a variable 
}  
}  
printf("%d ",a); // 11 will be printed since the scope of a = 20 is ended.   
}  

Output:  11 20 20 20 11


## Static
The variables defined as static specifier can hold their value between the multiple function calls.
static variable preserving their value even after the variable is out of scope ...
Static local variables are visible only to the function or the block in which they are defined.
A same static variable can be declared many times but can be assigned at only one time.
Default initial value of the static integral variable is 0 otherwise null.
The visibility of the static global variable is limited to the file in which it has declared.
The keyword used to define static variable is static.


#include<stdio.h>  
void sum()  
{  
static int a = 10;  
static int b = 24;   
printf("%d %d \n",a,b);  // 10,24
a++;   
b++; 
printf("%d %d \n",a,b); //11 , 25
}  
void main()  
{  
int i;  
for(i = 0; i< 3; i++)  
{  
sum(); // The static variables holds their value between multiple function calls.   
//printf("%d %d \n",a,b); // 12 , 26
}  
}  

Output:
10 24 
11 25 
11 25
12 26
12 26
13 27

## Register
The variables defined as the register is allocated the memory into the CPU registers depending upon the size of the memory remaining in the CPU.
We can not dereference the register variables, i.e., we can not use &operator for the register variable.
The access time of the register variables is faster than the automatic variables.
The initial default value of the register local variables is garbage.
The register keyword is used for the variable which should be stored in the CPU register. However, it is compilers choice whether or not; 
the variables can be stored in the register.
We can store pointers into the register, i.e., a register can store the address of a variable.
Static variables can not be stored into the register since we can not use more than one storage specifier for the same variable. 

#include <stdio.h>  
int main()  
{  
register int a = 0;   
printf("%u",&a); // This will give a compile time error since we can not access the address of a register variable.   
}  
Output:

main.c:5:5: error: address of register variable ?a? requested
printf("%u",&a);
^~~~~~

# External
The external storage class is used to tell the compiler that the variable defined as extern is declared with an external linkage elsewhere in the program.
The variables declared as extern are not allocated any memory.
It is only declaration and intended to specify that the variable is declared elsewhere in the program.
The default initial value of external integral type is 0 otherwise null.
We can only initialize the extern variable globally, i.e., we can not initialize the external variable within any block or method.
An external variable can be declared many times but can be initialized at only once.
If a variable is declared as external then the compiler searches for that variable to be initialized somewhere in the program which may be extern or static. 
If it is not, then the compiler will show an error.

#include <stdio.h>  
int main()  
{  
extern int a; // Compiler will search here for a variable a defined and initialized somewhere in the pogram or not.   
printf("%d",a);  
}  
int a = 20;  
Output:
20


# Q] what is Memory leakage ?
 - if memory is allocated dynamically but not release this memory is called leakage memory.
 - this memory is not use by os.
 - memory is deallocated using free() function.
# Q] how to deallocate memory without free?
 - by using realloc(ptr,no of bytes);
            realloc(ptr,0);//work like free function.
# what is dangling pointer? 
 - Pointer keeping address of memory that is not valid for the application, is said to be "dangling pointer".

# Examples of dangling pointers
 1. After releasing dynamically allocated memory, pointer still keeping the old address.
 2. Uninitialized (local) pointer
 3. Pointer holding address of local variable returned from the function.

# difference call by value and call by address?
value : formal argu.same type of actual arug.
addresss:formal argument are of same type
value : fomal argument is copy of actual argu.
address: adrs pass by actual argument is catch in formal argu.
value : by change formal argu.doer not affeect on actual argu.
addre : by changing formal argu. actual argu also change.
value : seperated memory is allocated for formal and actual argument.
address : formal argument and actual argument access same memory location.
value :  pre-emitive data type
address : array structure

# strcture padding :
 - for effient access compiler may add hidden bytes into struct called as structure padding or slack bytes.
- main purpose of structrue padding to avoid the wastage of cpu cycle.
- process doesnt read one byte at a time it read one word at a time.
# what is array and its limitation?

# why array index start from zero?
- compiler converts array notation (arr[i]) into pointer notation(*(arr+i)) .
- array name itself represents base address of an array .
- 1st element of an array present at base address i.e 0th array location.
- so if want to access this element then we need to access base address which is at 0th position so array index start with 0.

## What is a macro?Also explain parameterized macro?
-A macro in C is a set of program statements that is replaced by the macro expansion throughout the entire program.
-macros can be replace blindly by the preprosessor with the macro expansion 
## parameterized macro
A parameterized macro is a macro that is able to insert given parameter into its expansion. This gives the macro some of the power of a function.
As a simple example, in the C programming language, this is a typical macro that is not a parameterized macro:
     #define PI   3.14159
This causes PI to always be replaced with 3.14159 wherever it occurs. 
An example of a parameterized macro, on the other hand, is this:
#define sum(x,y)  (x+y)
What this macro expands to depends on what argument x is passed to it. Here are some possible expansions:
 pred(2+2)    →  (2+2)
 pred(y+2)  →  ((y+2) -1)

# difference MACRO AND FUNCTION:
macro    : macros are preprocessed.
function : function are compiled.
macro    : speed of execution is faster using macro.
function : speed of execution is slower in function.
macro    : using macro increase the code of length.
function : using function keep the code length unaffected.
macro    : macros are use when small code is repetadly use.
function : function are use when large code written.
macro    : macro does not check any compile time error.
function : function check compiletime error.


## Q}Structure and union difference:-
structure : collection of logically related similar or disimilar type of data element in contigous memory allocation.
union     : same as structure.
structure : We use the struct statement to define a structure.
union     : We use the union keyword to define a union.
structure : Every member is assigned a unique memory location.
union     : All the data members share a memory location.
structure : Change in the value of one data member does not affect other data members 
union     : Change in the value of one data member affects the value of other data members in the union.
structure : You can initialize multiple members at a time.  
union     : You can initialize only the first member at once.
structure : A structure can store multiple values of the different members. 
union     : A union stores one value at a time for all of its members
structure : A structure’s total size is the sum of the size of every data member.	 
union     : A union’s total size is the size of the largest data member 
structure : Users can access or retrieve any member at a time.
union     : You can access or retrieve only one member at a time.

## Q}What is union and its advantages and limitations ?
Union is user defined data-type.
Like struct it is collection of similar or non-similar data elements.
 All members of union share same memory space i.e. modification of an member can affect others too.
       • Size of union = Size of largest element
 When union is initialized at declaration, the first member is initialized.
• Application:
> System programming: to simulate register sharing in the hardware.
> Application programming: to use single member of union as per requirement.
union test {
int num;
char arr[2];
}u = { 65 };
printf("%d, %c, %s\n", u.num, u.arr[0], 
u.arr);
OUTPUT : 65 A A 

## Major advantages of using unions are: 
(i) Efficient use of memory as it it does not demand memory space for its all members rather it require memory space for its largest member only. 
(ii) Same memory space can be interpreted differently for different members of the union.

## Limitations of union are:
(i) You can use only one union member at a time.
(ii) All the union variables cannot be initialized or used with varying values at a time.
(iii)Union assigns one common storage space for all its members.

## In recursion (which segment is in use : code , data , stack?)
recursive function means function is calling itself within same function
When any function is called from main(), the memory is allocated to it on the stack.
A recursive function calls itself, the memory for a called function is allocated on top of memory allocated to calling function and different copy of local variables is created for each function call
Since function calls are executed in Last In First Out order, stack is the data structure for converting recursive to iterative implementation.

## Why we need a function?
- By using functions, we can avoid rewriting same logic/code again and again in a program(Reusability).
- code lookes readable and easy to understand by programmer.
Function is set of instructions that takes zero or more inputs(arguments) and returns result.
Every C program should have at least one function that is main function i.e entry point function.

We can call C functions any number of times in a program and from any place in a program.(Readability)
We can track a large C program easily when it is divided into multiple functions.(Maintainability)

# Arguments of a function:
>Arguments passed to a function are actual arguments.
>Arguments collected in a function are called formal arguments.



..................................................................................................................
## Q}How do you check whether ptr is null or not?
     #include<stdio.h>
    int main (void)
    {
       int i = 5;
      int *ptr = &i;
     //int *ptr = NULL;
      if(ptr == NULL)
     printf("Pointer is null pointer");
     else
     printf("Pointer is not a null pointer");
     return 0;
    }   
                                                                  	                    
## Q}Write a palindrome program:-
A palindrome number is a number that is same after reverse. 
For example 121, 34543, 343, 131, 48984 are the palindrome numbers.
```````````C
#include<stdio.h>
int main(void)
{
    int n1,rev = 0,rem = 0;
    printf("enter the 5 digit number: ");
    scanf("%d",&n1);
    int m1 = n1;
    for(int i =0;i<5;i++)
    {
        rem = n1%10;
        rev = rev*10+rem;
        n1 = n1/10;
    }
    if(m1 == rev)
    {
        printf("no is palindrome number");
    }
    else
        printf("no is not palindrome number");   
    return 0;
}
```````````
## Q}Write a program to find repeated numbers in an array (repeating more than twice)
#include<stdio.h>
//Calculate array size
#define ARRAY_SIZE(a)  sizeof(a)/sizeof(a[0])
void findDuplicateElement(int arr[], const int size)
{
    int i, j,k;
    int tmpArr[size],tmpArrIndex = 0;
    printf("Repeating elements are ");
    for(i = 0; i < size; i++)
    {
        int flag = 0;
        for(j = i+1; j < size; j++)
        {
            if((i != j) && (arr[i] == arr[j]))
            {
                for(k = 0; k < tmpArrIndex; k++)
                {
                    if(tmpArr[k] == arr[j])
                    {
                        //It is not a newly repeated element
                        flag = 1;
                    }
                }
                if(flag != 1)
                {
                    //newly repeated element
                    tmpArr[tmpArrIndex++] = arr[j];
                }
            }
        }
    }
    //print duplicate element
    for(i = 0; i < tmpArrIndex; i++)
    {
        printf("%d ",tmpArr[i]);
    }
}
int main()
{
    int arr[] = {4, 2, 4, 5, 2, 3, 1,4,4,4,4,1,2,34,4,4,4,4,4,4};
    const int N = ARRAY_SIZE(arr);
    findDuplicateElement(arr, N);
    return 0;
}

#Write a program to find repeated array elements ( repeated only twice)
#include<stdio.h>
#include<stdlib.h>
void elements(int arr[], int size)
{
  int i, j;
  printf(" Repeating elements are ");
  for(i = 0; i < size-1; i++)
    for(j = i+1; j < size; j++)
      if(arr[i] == arr[j])
        printf(" %d ", arr[i]);
}    
 
int main()
{
  int arr[] = {4, 2, 4, 5, 2, 3, 4};
  int arr_size = sizeof(arr)/sizeof(arr[0]); 
  elements(arr, arr_size);
  getchar();
  return 0;
}
## Q}What are static functions?
A static function in C is a function that has a scope that is limited to its object file. 
This means that the static function is only visible in its object file. 
A function can be declared as static function by placing the static keyword before the function name.

#include <stdio.h>
static void staticFunc(void){
   printf("Inside the static function staticFunc() ");
}

int main()
{
   staticFunc();
   return 0;
}


OUTPUT:
Inside the static function staticFunc()
In the above program, the function staticFunc() is a static function that prints ”Inside the static function staticFunc()”. 
The main() function calls staticFunc(). 
This program works correctly as the static function is called only from its own object file.

## Q}What are void pointers and their applications ?
Void pointers are those pointers that point to a variable of any type
As the name suggests, the void pointer indicates that the pointer is basically empty- and thus, it is capable of holding any data type address in the program. 
Then, these void pointers that have addresses, can be further typecast into other data types very easily.

   ## example
````C
         int num1 = 20;    //variable of int datatype 
         void *ptr;        //Void Pointer
         *ptr = &num1;    //Point the pointer to int data
        print("%d",(*(int*)ptr));    //Dereferencing requires specific data type 

        char c = 'a';
*ptr = &c; //Same void pointer can be used to point to data of different type -> reusability
print("%c",(*(char*)ptr));
```` 

# Application of void pointer:
The void pointer in C is a pointer which is not associated with any data types.
 It points to some data location in the storage means points to the address of variables. 
It is also called general purpose pointer.
 In C, malloc() and calloc() functions return void * or generic pointers.

## Q] What is ISR?
    interrupt service routine:
    - when an interrupt occur in the process ...means there is an high priority event occur which can requires immediate attention...then processor  pause the normal execution and execute the instruction in ISR(find perticular ISR call interrupt handler  ) ...after complition normal execution resumed.

## Q] Why do we use the volatile keyword?
   -the main reason behind using volatile keyword is that it is used to prevent optimization on variable  in our source code.
   -volatile keyword is used to inform the compiler that value of the varible may get changed unexpectedly.
   -for faster execution of program compiler may  put variable in cache register and that variable get modified outside its current execution context ,so volatile keyword inform compiler that always access variable from the its memory location .

        ## example:
          1. interrupt
          2. external input
          3. DMA
          4. shared resource  
## What is use of  const keyword?
    - constant variable get space into "ro-data "section.
    - constant means read only data.
    - if we dont want to modify any variable in our program so we can declare as a const .
    - const keyword inform compiler that this variable in not intended to be modify , so compiler do not allow to use such operators which can try to modify that variable
    like ++,--,+=,-=,*= etc.
     
  ## example:
     ````C
         const int num = 10;
        num++;//not allowed
        num = 20;//not allowed
        num +=20;//not allowed

        int *ptr = NULL;
        ptr = &num;
        *ptr++;
        printf("num = %d *ptr = %d ",num,*ptr); 
````
## Q] What do you understand by Interrupt Latency?
  - Interrupt latency refers to the time taken by ISR to respond to the interrupt. 
  - it is time for arrival of interrupt till the execution of the ISR.
  - The lesser the latency faster is the response to the interrupt event.
# Q] pointer:
   pointer is a special type of variable which is used to store the adrress of memory location.
  # types of pointer:
    1. const int *p; ==>p is pointer to integer constant.
    2. int *const p; ==>p is constant pointer to interger.
    3. 


# reentrant function:
  - A function is said to be reentrant if there is interrupt occur during the execution of the function ,  then service the ISR and then resume the earlier going on function, without hampering its earlier course of action. Reentrant functions are used in applications like hardware interrupt handling, recursion, etc.

# callback funtion:
 - A callback function is a function passed into another function as an argument to call it.
 ```C
void A()
{
    printf("I am function A\n");
}
  
// callback function
void B(void (*ptr)())
{
    (*ptr) (); // callback to A
}
  
int main()
{
void (*ptr)() = &A;
      
// calling function B and passing
// address of the function A as argument
    B(ptr);
  
    return 0;
}
 ```

# bitfield:
 -bitfield is an data structure that allows the programmer to allocate memory for structure and union in bits in order to utlized computer memory in efficient manner.

# Endianness:
 - it is a way to store data bytes into the memory
 - basically endianess comes with two varities little endian and big endian and in which data is stored  in order depends upon this endianness.
 # little endian : 
  - if the machine is the little-endian then LSB byte store first (means at lower address).
 # big endian : 
  - if the machine is the big-endian then MSB byte store first (means at lower address).

  # example : 0x 11 22 33 44
  - little endian : 44 33 44 11
  - big endian    : 11 22 33 44
  

# how to check endianess of our system
````C
#include<stdio.h>
int main(void)
{
    int i;
    int j = 0x11223344;
    char *c = (char*)&j;
    int n = sizeof(j);
    if(*c)
    {
        printf("little endian\n");
         for (i = 0; i < n; i++)
            printf(" %.2x", c[i]);
    }
    else
    {
        printf("big endian\n");
        for (i = n; n < i; i--)
          printf(" %.2x", c[i]);
    }
    return 0;
}
````

# set nth bit:

```C
#include<stdio.h>
int main(void)
{
    int n1,n;
    printf("enter any no:");
    scanf("%d",&n1);
    printf("enter nth bit to set:");
    scanf("%d",&n);
    int newno = (1<<n) | n1;
    printf("num : %d\n",n1);
    printf("newno : %d\n",newno);
    return 0;
}
```

# reset nth bit:
```C
#include<stdio.h>
int main(void)
{
    int num,nth;
    printf("enter no:");
    scanf("%d",&num);
    printf("enter nth bit:");
    scanf("%d",&nth);
    int newno = (~(1<<nth)) & num;
    printf("num : %d\n",num);
    printf("newno: %d\n",newno);
    return 0;
}
```
# Q}Write a c program to access data elements of 3d array.
```C
#include<stdio.h>
int i,j,k;                         //variables for nested for loops
int main()
{
	int arr[2][3][3];              //array declaration
	printf("enter the values in the array: \n");
	for(i=0;i<2;i++)              //represents block
	{
		for(j=0;j<3;j++)          //represents rows
		{
			for(k=0;k<3;k++)      //represents columns
			{
				printf("the value at arr[%d][%d][%d]: ",i,j,k);
				scanf("%d",&arr[i][j][k]);
			}
		}
	}
	printf("printing the values in array: \n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
		{
			for(k=0;k<3;k++)
			{
				printf("%d ",arr[i][j][k]);
				if(k==3)
				{
					printf("\n");
				}
			}
		}
		printf("\n");
	}
	return 0;
}
```
# Q}How to find the middle element in an array?
```C
#include <stdio.h>
int main ()
{
int arr []={1,2,3,4,5};
int size= sizeof arr/sizeof arr[0];
printf ("%d", arr[size/2];
return 0;
}
```

# Q} Define register variables. What are the advantages of using register variables?
- variable of reqister type inform the compiler for storing the variables in a register of the CPU.
- These variables are stored in the registers, so the speed of processing is become more than the normal variables.

# Program to find length of string in C :
 a) without using strlen :
    #include<stdio.h>

    int main(void)
    {
    char s[] = "I am Rutuja Bharat Yadav";
    int i;

    for(i = 0 ; s[i] != '\0' ; i++);
    
    printf("Length of string : %d" , i);

    return 0;
    }

 b) using strlen:
    #include<stdio.h>
    #include<string.h>

    int main(void)
    {
    char s[] = "I am Rutuja Bharat Yadav";
    int length;

    length = strlen (s);
    
    printf("Length of %s : %d" , s ,length);

    return 0;
    }