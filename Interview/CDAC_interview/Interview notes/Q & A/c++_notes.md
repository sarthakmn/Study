### OOPS - Object Oriented Programming Structure/System (C++)

* OOPS is not a language/syntax.
* C language - Procedure Oriented programming language
* C++ is a "programming methodology" that is used to solve the real world problems using "class" & "object"
* Dr.Alan kay inveted OOPS in 1960.

### 4 major pillars/parts/elements of OOPS : 

## 1) Abstraction : (to achieve simplicity) ---> like function call 
    * Getting only essential things and hiding unnecessary details is called as Abstraction.
    * focuses on outer behaviour of the object.
    * programatically --> "create object" & "call member function" on it.
    * (Ex. program inside main() , printf()--> How part is unknown??)

## 2) Encapsulation : (to hide object / system implementation) --> like function definition
    * Binding of data (data member) and code (member function) together is called as Encapsulation.
    * process of implementing abstraction is called as Encapsulation.
    * Encapsulation always describes "inner behaviour" of the object.
    * By defining "class" --> we can achieve Encapsulation.

## 3) Modularity : (to minimize module dependancy)
    * dividing programs into small modules for the purpose of simplicity is called as Modularity.
    * diving a code into smaller parts.
    * Ex. creating muitiple files for single program.

## 4) Hierarchy / Inheritance : (to achieve reusability)
    * several classes are derived from a common base class.
    * In object-oriented programming, "inheritance" is the mechanism of basing an object or class upon another object or class, retaining similar implementation

### 3 minor pillars/parts/elements of OOPS : (not essential for OOPS)

## 1) Polymorphism : (to reduce maintenance of system)
    * Ability of an object to take multiple forms is called as Polymorphism.

# Function Overloading : 
    * same function name with different no of arguments.
    For Ex:
````C
        void sum(int a , int b);
        void sum(int a , int b, int c);
        void sum(int a , float b);
        void sum(float a , float b);
```` 
# Function Overriding : 
    * same function name with same no of arguments but in different scopes.
    For Ex:
````C
        scope A 
        {
            ....
            ....
            void display{....}
        }

        scope B
        {
            ....
            ....
            void display{....}
        }
```` 

## 2) Concurrency : (to utilize hardware resources efficiently)
    * Process of executing "multiple tasks" simulteneously is called as Concurrency.
    * In C++ , we can achieve Concurrency using "multi-threading".

## 3) Percistence : (to maintain state of the object)
    * Process of maintaining state of the object on secondary stoage is called Percistence.
    * For Ex. Maintaining Accoun t balance by deposit & withdraw amount from account.


## Difference between Structure in C and C++ :

C   : we can include only variables.
C++ : we can include variable as well as functions.
C   : we need to pass struct var by value or by address to the functions.
C++ : the functions inside the structure are called with variable and DOT (.) operator
C   : By default all struct var are accessible outside the structure.
C++ : By default all members are accessible outside structure,But wecan restrict using public/protected/private.

## Access Specifiers: (public/private/protected)
    * In C++ , By default structure members are "public"
    * In C++ , By default class members are "private"

## use of namespace
    * to avoid naming clashing / collision.
    * to group functionally related / equivalent types together.
    **** to access members of the namespace in function ---> use SCOPE RESOLUTION (::)

    ```C++
    namespace na{
        int num1 = 10;
        int num3 = 30;
    }
    namespace nb{  // if name of the namespace are not same -> members of namespace can/cannot be same.
        int num2 = 20;
        int num4 = 40;
    }
    namespace na{   // if name of the namespace is same -> members of namespace cannot be same.
        int num1 = 10;  // NOT allowed 
        int num3 = 30;  // NOT allowed 
        int num2 = 10;   //allowed
        int num4 = 50;    // allowed
    }
    int main(void){
        printf("%d", na::num1);
        printf("%d", na::num3);
        printf("%d", nb::num2);
        printf("%d", nb::num4);
        return 0;
    }

    ```

## Q. what if global and local variables having same name ????
    * preference is always given to the local variable.
    * In C++, using SCOPE RESOLUTION (::) --> we can access global variable.

## "using" directives : 
    * if we have to use members of the namespace "frequently"   ---> use "using" keyword. (for single function)
    * if we want to use members of the namespace in multiple functions ---> define "using" global


## cout (<<) with insertion operator : 
    * cout stands for character output.
    * use to print string on the console/screen.
## cin (>>) with extraction operator : 
    * cin stands for character input.
    * use to read data from console/keyboard.

## EMPTY CLASS : 
    * it is class which do not contain any member into the class.
    * size of object of empty class = 1 byte.
````C++
        class{

        }e;

        int main(void)
        {
            printf("%d", sizeof(e)); // 1 byte
            return 0;
        }
````

## CLASS :  (data member + member function)
    * it is collection of data member and member function.
    * class is a "logical or imaginary" entity. 
           (Ex. Car , Book , Mobile etc....).
    * Object is a "Physical or real time" Entity.
           (Ex. Nano , SECRET , Nokia 1100 etc....).

## Object : (variable / instance of class)
    * Any entity which is having physical existence is called Object.
    * entity which gets space inside memory.
    * Object is a "Physical or real time" Entity. (Ex. Nano , Galvin , Nokia 1100 etc....)
    * object is used to access data members & member function of class using DOT (.) Operator

## Data member : variable declared inside class  
    * Only data members get space once per object.

## Member function : function defined/implimented inside class
    * Member function do not get space inside object.
    * All objects of same class share single copy of member function.

## Q. What is "this" pointer ? (we can not declare this ptr explicitly)
    * If we "call member function on object" then "compiler implicitly pass address of that object" as          argument to the function implicitly.
    * To store address of object "compiler implicitely declare one pointer" as a parameter inside member 
      function. Such parameter is called "this pointer".
    * Every member function receives this pointer except : 
        1.(global function) 2.(static member function)  3.(friend function) 

## Q. What is inline functions????
    * If a function is inline, the compiler places a copy of the code of that function at each point where the 
        function is called at compile time
    * Inline functions get replaced by compiler at its call statement. It ensures faster execution of function 
        just like macros.
    * Advantage of inline functions over macros: "inline functions are type-safe".

#### Constructor : (object initializer)
    * It is a member function of a class which is used to "initialize object".
    * Constructor has same name as that of class and don’t have any return type.
    * Constructor get automatically called when object is created i.e. memory is allocated to object.
    * If we don’t write any constructor, compiler provides a default constructor.

   ## Constructor is considered as special member function :
    1. its name is same as class name.
    2. it does not have any return type.
    3. We can not call constructor on object, pointer / reference explicitly. It is designed to call implicitly.
    4. called once per object.

   ## If we want to initialize data members according to "users requirement" then we should use constructor     body :
```C++
                class Test
                {
                    private:
                        int num1;
                        int num2;
                        int num3;
                    public:
                        Test( void )     // parameterless / default / zero argu constructor
                        {
                            this->num1 = 10;
                            this->num2 = 20;
                            this->num3 = num2;
                        }
                        Test(int a , int b) // parameterized constructor ---> class_name object_name (10 , 20);
                        {                                                    // Test t1 (10 , 20);
                            this->num1 = a;
                            this->num2 = b;
                        }
                };
```

#### Destructor : always preceds with tild operator( ~ ) 
    * For Ex :   ~Test(void)
                {
                    ...  
                }

    * It is a member function of a class which is "used to release the resources".

    * Destructor calling sequence is "exactly opposite of constructor" calling sequence.

    * "Default destructor" do not de-allocate resources allocated by the programmer. 
        If we want to de-allocate it then we should "define destructor inside class".

   ## Destructor is considered as special member function :
    1. its name is same as class name.
    2. it does not have any return type.
    3. We can not call Destructor on object, pointer / reference explicitly. It is designed to call implicitly.

## Q. How to handle exception in C++ ???
    
    * try block : before catch block (require at least 1 catch block)
    * catch bock : after throw block (for single try block ---> multiple catch blocks)
    * throw block : exception can be raised implicitely (or explicitely)

## Q. What is FRIEND function ????
---> 
    * A "non-member function" of the class , which is designed to access "private" & "protected" members of the class is called as Friend () of class.
    * If we want to access "private" members outside class.
    * We can declare as a friend inside class only --> that function "not considered" as member of the class.

## Dynamic memory allocation in C++ :
---> using "new" & "delete" keywords.

```C++
        // int arr[n];    ---> static array 
        // suppose n = 4

        int *ptr = new int[n];

        // Requirement
        // int 4 elements array 10 20 30 40
        // char 3 elements  A B C

        template <class T>

        //Assume T as int , size = 4 
         this->arr=new T[this->size];
         this->arr=new int[4];

        //Assume T as char , size = 3
         this->arr=new T[this->size];
         this->arr=new char[3];
```

#### Inheritance (is-a) : (syntax ---> class derived-class: access-specifier base-class):

    for Ex: Employee is-a Person.  ---->  class Employee  : public Person { .... };
                            read as ---> class Person is inherited into class Employee.
                            read as ---> class Employee is derived from class Person.
                            
    for Ex: Book is-a Product.     ---->    class Book  : public Product { .... };
                            read as ---> class product is inherited into class book.
                            read as ---> class book is derived from class book.

    * While creating a class, instead of writing completely "new data members and member functions", the programmer can designate that the "new class should inherit" the "members of an existing class". 
    * This existing class is called the "Base class", and the new class is referred to as the "Derived class".

    * If "is-a" relationship exist between two types then we should use inheritance.

    * During inheritance, all the members of the base class(parent class) gets inherit into the derived class (child class).