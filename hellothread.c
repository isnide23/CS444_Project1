#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <pthread.h>

void *run_func(void *arg)
{
    char *myid = (char *)arg;
  
    static int s = 0;
    for (s = 0; s < 5; s++)
        printf("%s : %d\n", myid, s);

    return 0;
}

int main(void)
{
    char *message1 = "Thread 1";
    char *message2 = "Thread 2";

    printf("Launch Threads!\n");
    pthread_t thread_1, thread_2;

    pthread_create(&thread_1, NULL, run_func, (void *) message1);
    pthread_create(&thread_2, NULL, run_func, (void *) message2);

    pthread_join(thread_1, NULL);
    pthread_join(thread_2, NULL);
    return 0;
}

