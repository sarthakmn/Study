// Reverse the string

#include <stdio.h>
#include <string.h>

int main(void){
    char Name[] = "Sarthak";
    char Tmp[strlen(Name)];

    for (size_t i = strlen(Name) - 1; i > 0; i--)
    {
        Tmp[strlen(Name) - 1 - i] = Name[i];
    }
    Tmp[strlen(Name) - 1 - 0] = Name[0];
    printf("%s\n",Tmp);
    return 0;
}