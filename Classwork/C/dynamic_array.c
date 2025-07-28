#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = NULL;
    int Number;
    printf("Enter Array Elements : ");
    scanf("%d",&Number);
    ptr = malloc(sizeof(int)*Number);
    for(int i=0;i<Number;i++){
        printf("Enter Element : ");
        scanf("%d",ptr+i);
    }
    for(int i=0;i<Number;i++){
        printf("Element %d : %d \n",i,*(ptr+i));
    }
    for(int i=Number;i<0;i--){
        free(ptr-i);
    }
    return 0;
}