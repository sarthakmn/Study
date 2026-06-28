// allocate mem size 100

#include <stdio.h>
#include <stdlib.h>

int main(void){
    char Size[100];
    
    char *Size1 = malloc(sizeof(char)*100);

    printf("size : %x\n",Size1);

    if(*Size1 | (1<1) || *Size1 | (1<0)){  // 0001 | (1<<0)  // check last and last second address byte is 0
        printf("1");
    }               
    else{
        printf("0");
    }      
    return 0;
}
