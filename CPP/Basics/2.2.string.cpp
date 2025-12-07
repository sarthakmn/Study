#include<stdio.h>
#include<string.h>
int main(){
    
    char str[] = "Aunbeam";     //  65
    char str1[] = "aunbeam";    //- 97

    int size = strcmp(str,str1);
    printf("output = %d\n",size);

    // strcpy(str,str1);
    // printf("output = %s  %s\n",str,str1);

    strcat(str,str1);
    printf("output = %s   %s\n",str,str1);

    printf("output = %s \n",strchr(str,'e'));
    return 0;
}

