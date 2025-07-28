#include<iostream>
#include<pthread.h>
#include<condition_variable>

using namespace std;

void *Producer(void *){
    while(1){
        cout << "Producer" << endl;
    }
}
void *Consumer1(void *){
    while(1){
        cout << "Consumer1" << endl;
        
    }
}
void *Consumer2(void *){
    while(1){
        cout << "Consumer2" << endl;
        
    }
}

int main(void){
    pthread_t T1;
    pthread_t T2;
    pthread_t T3;
    
    pthread_create(&T1,NULL,Producer,NULL);
    pthread_create(&T2,NULL,Consumer1,NULL);
    pthread_create(&T3,NULL,Consumer2,NULL);
    
    pthread_join(T1,NULL);
    pthread_join(T2,NULL);
    pthread_join(T3,NULL);

    return 0;
}