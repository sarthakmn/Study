/*
| Keyword    | Scope         | Lifetime       | Notes                         |
| ---------- | ------------- | -------------- | ----------------------------- |
| `auto`     | Block (local) | Block ends     | Default for local variables   |
| `register` | Block (local) | Block ends     | Hint to store in CPU register |
| `static`   | Local or file | Entire program | Retains value / internal-only |
| `extern`   | Program-wide  | Entire program | Shares globals across files   |
*/

#include <stdio.h>
#include "storageClasses.h"

extern int Number;
static int count;

void increase(void){
    count++;
}
void decrease(void){
    count--;
}

int main(void){
    Number = 10;
    
    increase();
    decrease();
    increase();
    increase();

    printf("Count : %d\n",count);
    return 0;
}