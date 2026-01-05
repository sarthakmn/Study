#include <stdio.h>
#include <string.h>

#pragma pack(1)         // remove slag bytes added by compiler for faster mem access.

struct list{
    char Name[7];
    int roll_No;
    short nm;
    unsigned int a : 2;  // bit fields
};

typedef union{
    int subject;
    long Roll_No;
}marks;

enum color{Red,Blue,White};

int main(void){
    char Name[] = "Sarthak";
    struct list ls;
    strcpy(ls.Name,Name);
    ls.roll_No = 10;
    
    printf("Roll : %d Name : %s \nSize of struct : %ld\n",ls.roll_No,ls.Name,sizeof(ls));

    marks mk;
    mk.Roll_No = 10;
    mk.subject = 20;
    printf("size of union : %ld Addition : %d\n",sizeof(mk),mk.subject + mk.Roll_No);
    return 0;
}