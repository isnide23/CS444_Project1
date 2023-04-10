#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <pthread.h>

void *run_func(void *arg)
{
    char *myid = (char *)arg;
  
    
    for (int s = 0; s < 5; s++)
        printf("%s : %d\n", myid, s);

    return 0;
}

int main(void)
{
    char *thread_name_1 = "Thread 1";
    char *thread_name_2 = "Thread 2";

    printf("Launch Threads!\n");
    pthread_t thread_1, thread_2;

    pthread_create(&thread_1, NULL, run_func, (void *) thread_name_1);
    pthread_create(&thread_2, NULL, run_func, (void *) thread_name_2);

    pthread_join(thread_1, NULL);
    pthread_join(thread_2, NULL);

    printf("Threads Complete!\n");
    return 0;
}

