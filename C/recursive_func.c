// C Program to find the fibonacci number using tree
// recursion
#include <stdio.h>

int fibonacci(int n)
{
    // Base case
    // Fibonacci of 0 and 1 is the number itself
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{

    // function call
    for(int n; n<10; n++){
    printf("%d ",fibonacci(n));
    }
    return 0;
}