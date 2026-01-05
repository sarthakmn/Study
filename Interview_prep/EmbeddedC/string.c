#include <stdio.h>
#include <string.h>

int main(void){
    char *Name  = "Sarthak";
    char *Surname[strlen(Name)];

    memcpy(Surname, Name, strlen(Name));   // copies all 7 bytes
    //strcpy(Surname,Name);                  // stops at '\0'

    printf("String copy : %s\n",Surname);
    printf("String Compare : %s\n",strcmp(Surname,Name));
    
    return 0;
}