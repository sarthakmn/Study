#include<stdio.h>
#include"stack.h"
#include<string.h>

int main(){
    char infix[]="a*b/c*d+e-f*h+i";
    stack_t st;
    init(&st);

    for(int i=0;i < sizeof(infix);i++){
        if(symbol(infix[i]) == 1)
            printf("%c ",infix[i]);
        else{
            if(is_empty(&st))
                push(infix[i],&st);
            else{
                if(peek(&st) == '*' ||  '/' && infix[i] == '*' || '/'){
                    pop(&st);
                    push(infix[i],&st);
                }
                else if(peek(&st) == '-' || '+' && infix[i] == '*' || '/'){
                    push(infix[i],&st);
                }
                else if(peek(&st) == '*' || '/' && infix[i] == '+' || '-'){
                    pop(&st);
                    push(infix[i],&st);
                }
                else if(peek(&st) == '-' ||  '+' && infix[i] == '-' || '+'){
                    pop(&st);
                    push(infix[i],&st);    
                }
            }
        }
    }
    printf("\n");
    return 0;
}
