#include <stdio.h>

int func(int (*n)[1]) {
    printf("%d\n",n[1][1]);
}

int main() {
    int arr[3][3] = {{10,20,30},{10}};
    func(arr);
    return 0;
}