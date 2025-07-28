#include<stdio.h>

class time{   //same as CPP struct only all members are private default
    //Data Members
    int hr;
    int min;
    int sec;

    public: // Default is private

    //constructor :
    //use to init the class with no return type and name same as of class name 
    //if we cannot call constructor then default constructor will get called

    time(){      //Parameter less Constructor 
        this->hr = 0;
        this->min = 0;
        this->sec =0;
        printf("Parameter less Constructor called\n"); 
    }
    time(int hr){ //Parameterized Constructor 
        printf("Parameterized Constructor hr : %d\n",hr); 
    }



    void set_min(int min){ //mutator / setter
        this->min = min;
    }
    int get_min(){  //inspector / getter
        return this->min ;
    }
    void facilitator()  //facilitator
    {
        if(this->sec > 60 || this->sec < 0)
            printf("Invalid Value\n");
    }



    // member function
    void takeData(){  
        printf("Enter Time  Hr:Min:Sec  : ");
        scanf("%d%d%d",&hr,&min,&sec);
    }
    void PrintData(){
        //this pointer is used to access the data members
        printf("Time  %d:%d:%d \n",this->hr,this->min,this->sec); 
    }



    //destructor
    ~time(){
        printf("Destructor Called\n");
    }
    
};


int main(){
    time t1(12); //class dont have memory and object have space in memory
    t1.takeData();
    t1.PrintData();

    time t2(14);
    t2.takeData();
    
    t2.set_min(20);
    int get = t2.get_min();
    printf("getter : %d\n",get);
    t2.facilitator();

    t2.PrintData();

    return 0;
}