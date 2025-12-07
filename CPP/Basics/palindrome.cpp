#include<stdio.h>
#include<string.h>
void palin(char *str1){
    int j = 0;
    int error = 0;
    for (int i = strlen(str1)-1; i >= 0; i--)
    {   
        if(str1[j] != str1[i]){
            error = 1;
        }
        j++;

    }
    printf("String Reversed : %s\n",str1);
    if(error == 1){
        printf("string is not palindrome\n");
    }
    else{
        printf("string is palindrome\n");
    } 
}

int main(){
    char str1[]="ssuuss";
    palin(str1);

    return 0;
}
