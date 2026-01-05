// Write a function to simulate string reverse and check whether string is palindrome or not?

#include <stdio.h>
#include <string.h>

int main(void){
    char *Name = "SkS";
    char *Surname = "SkS";
    short isEqual = 1;
    if(strlen(Name) == strlen(Surname)){
        for (size_t i = 0; i < strlen(Surname); i++)
        {
            printf("Name : %c  Surname : %c\n",Name[i],Surname[strlen(Surname)-1 - i]);
            if(Name[i] != Surname[strlen(Surname)-1 - i]){
                isEqual--;
                break;
            }
        }
    }
    else{
        isEqual--;
    }
    if(isEqual){
        printf("Strings are palindrome\n");
    }
    else{
        printf("Strings are not palindrome\n");
    }
    return 0;
}