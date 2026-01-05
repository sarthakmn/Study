#include<stdio.h>
#include<mosquitto.h>

int main(void){
    int rc;
    struct mosquitto *mosq;

    mosquitto_lib_init();
    
    //Create a new mosquitto client instance.
    mosq = mosquitto_new("publisher-test",true,NULL);
    rc = mosquitto_connect(mosq,"localhost",1883,60);
    if(rc != 0 ){
        printf("Connection Failed\n");
        mosquitto_destroy(mosq);
        return -1;
    }
    printf("Connected to broker\n");
    mosquitto_publish(mosq,NULL,"test/t1",6,"Forvia",0,false);
    mosquitto_disconnect(mosq);
    mosquitto_destroy(mosq);
    mosquitto_lib_cleanup();
    return 0;
}