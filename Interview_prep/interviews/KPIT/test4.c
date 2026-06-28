/* 
What is advantage of volatile keyword.

Implement strstr().    

What is size of structure : 
struct {
int a;
char b:
char c;
double d;
}

What is size of class with 1 virtual function.

char *ptr = "kanthi" ;    a replace to i
*/

#include <stdio.h>
#include <string.h>

int main(void){
    char *Name = "Sarthak";
    char *SubName = "Sar";
    int flag = 0;

    // for (int i = 0; i < strlen(Name); i++)
    // {
    //     if((*(Name+i)) == (*(SubName+i))){
    //         flag++;
    //     }
    //     else{
    //         flag = 0;
    //     }
    // }
    int count = 0;
    
    while(1){
        if(*(Name) == *(SubName)){
            flag++;
            SubName = SubName++;
        }
        else{
            flag = 0;
        }
        Name = Name++;
        if(count == 7){
            break;
        }
        count++;
     }
    
    if(flag < 1){
        printf("Substring is present : %d\n",flag);
    }
    return 0;
}

 
