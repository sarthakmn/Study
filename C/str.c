#include <stdio.h>
#include <string.h>

void main(void){
    char name[] = "Sarthak";
    char surname[] = "Nanivadekar";
    printf("Name surname : %s %s\n",name,surname);
    strcpy(surname,name);
    printf("Name surname : %s %s\n",name, surname);

}