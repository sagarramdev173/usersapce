#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define SUCCESS  1
#define FAILURE -1

void report_and_exit(const char *msg) {
    perror(msg);    
    exit(FAILURE);
}

// race condition threads
void foo();
void bar();

int global_variable = 0;

int main(){

    pthread_t thread1;
    pthread_t thread2;

    // creating the threads
    pthread_create(&thread1, NULL, (void *)foo, NULL);
    pthread_create(&thread2, NULL, (void *)bar, NULL);

    // joining the threads
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("global variable value: %d in main\n", global_variable);
    return SUCCESS;
}

// race condition functions
void foo(){
    while(global_variable <=100){
        printf("global variable value: %d in foo\n", global_variable);
        global_variable++;      
    }
}

void bar(){
    while(global_variable >= 0){
        printf("global variable value: %d in bar\n", global_variable);
        global_variable--;
        // sleep(1);
    }
}