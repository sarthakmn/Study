#include<stdio.h>
struct time
{
    private: //private variable cannot modify outside the structure

    int hr;
    int sec;
    int min; 

    //In Cpp we can write function inside the structures which are logically related with data
    public: //public variable ca be modify outside the structure
    
    void takeValue(){
        printf("Enter Time Hr:Min:Sec\n");
        scanf("%d%d%d",&hr,&min,&sec);
    }

    void printTime(){
        printf("Time %d:%d:%d\n",hr,min,sec);
    }
};

int main(){
    struct time t1;
    t1.takeValue();
    t1.printTime();
    return 0;
}
