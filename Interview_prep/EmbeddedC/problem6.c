// Remove duplicates in string

#include <stdio.h>
#include <string.h>

int main(void){
    char Name[] = "Sarthak";
    char Tmp[strlen(Name)];
    int array[strlen(Name)];
    int count = 0;
    for (size_t i = 0; i <= strlen(Name)-1; i++)
    {
        for (size_t j = i+1; j <= strlen(Name)-1; j++)
        {
            printf("i = %c j = %c\n",Name[i],Name[j]);
            if(Name[i] != Name[j]){

            }
            else{
                break;
            }
            Tmp[i] = Name[i];

        }
    }
    
    printf("Duplicate String : %s\n",Tmp);

    return 0;
}