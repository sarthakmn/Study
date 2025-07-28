//gcc -E run.c  //show preprocessor output
//gcc -c run.c  //create compiler code
//gcc -S run.c  //create assembly code
//gcc run.c     //linker

#include<stdio.h>
//comment
#define var 10
int main(){
    printf("Hello World\n");
    printf("var : %d\n",var);    //variable
    return 0;
}
