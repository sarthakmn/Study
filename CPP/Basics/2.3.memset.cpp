#include<stdio.h>
#include<string.h>
int main(int argc,char *argv[]){
    
    char str[] = "Aunbeam";     //  65
    char str1[] = "aunbeam";    //- 97

    memcpy(&str,&str1,2);
    printf("output = %s  %s\n",str,str1);
    return 0;
}
