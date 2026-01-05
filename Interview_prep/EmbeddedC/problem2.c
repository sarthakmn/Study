/* Print fibonacci series 
   1 , 1 , 2 , 3 , 5 , 8
*/

#include <stdio.h>


int fibonacci(int Number){
    if(Number == 0)
        return 0;
    if(Number == 1)
        return 1;
        
    return fibonacci(Number - 2) + fibonacci(Number - 1);
}
int main(void){
    int Number = 10;
    printf("Fibonacci = %d\n",fibonacci(Number));

    return 0;
}