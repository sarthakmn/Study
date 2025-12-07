#include<stdio.h>

//Q. What is function overloading? Which are the rules of function overloading? 
//Why return type is not considered in function overloading?

void add(int a,int b){  
    printf("Addition : %d\n",a+b);
}

void add(int a,int b,int c){  
    printf("Addition : %d\n",a+b+c);
}

void add(int a,char b){  
    printf("Addition : %d\n",a+b);
}

void add(char a,int b){  
    printf("Addition : %d\n",a+b);
}

int main(){
    
    add(20,70);
    add(20,70,10);
    add('a',10);
    add(10,'b');
    return 0;
}