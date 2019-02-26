//simple code to create a thread, print thread id and terminate thread

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
 
void * threadFunc(void * arg)
{
    printf("Thread Function :: Start \n");
    sleep(1);
    printf("Thread Function :: End \n");
    return NULL;
}
int main()
{
 
    pthread_t threadId;

    long id=(long)threadId;
    int err = pthread_create(&threadId, NULL, &threadFunc, NULL);

    if (err)
    {
        printf("Thread creation failed : \n");
        return err;
    }
    else{
        printf("Thread Created with ID :%ld\n ",id);
    }    

    err = pthread_join(threadId, NULL);
    return 0;
}
