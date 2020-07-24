
#ifndef PROJECT2_LIB_LPTHREADS_TESTS_HPP
#define PROJECT2_LIB_LPTHREADS_TESTS_HPP

#include "lpthreads.c"

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>


void hey(){

    sleep(1);

    while(1){
        printf("Hey its me child pid %i, am alive\n", getpid());
        sleep(1);
    }

}


void no_mutex_count(){

    sleep(1);

    int pid = getpid();

    printf("Hey its me child pid %i, im gonna print 5 times my pid\n", pid);

    // Lock the mutex
    for (size_t i = 0; i < 5; ++i)
    {
        printf("%i\n", pid);
        sleep(1);
    }
    printf("Doneee \n\n");

}

void mutex_count(lpthread_mutex_t* mutex){

    sleep(1);

    int pid = getpid();

    // Lock the mutex
    Lmutex_trylock(mutex);

    printf("Hey its me child pid %i, im gonna print 5 times my pid\n", pid);

    for (size_t i = 0; i < 5; ++i)
    {
        printf("%i\n", pid);
        sleep(1);
    }
    printf("Doneee \n\n");
    Lmutex_unlock(mutex);

}



void creation_kill_test(){
    
    printf("\n\n ------- Now testing creation and killing ------ \n\n");
    lpthread_t* thread;
    int child_pid = Lthread_create(&thread, NULL, hey, NULL);

    printf( "Hey its me parent, the returned pid was %i and my pid is %i, gonna sleep for a while\n", 
            child_pid, getpid());
    sleep(5);

    printf("Now am gonna do what is called a pro-gamer move, kill my child and then sleep\n");
    if(Lthread_end(thread) == child_pid){
        printf("Looks like it worked\n");
    }

    sleep(1);

    printf("My time has come my friend, its been a good ride, see ya\n");

}

void mutex_test(){


    printf("\n\n ------- Now testing non mutex vs mutex printing ------ \n\n");
    lpthread_t* thread1, thread2;
    lpthread_mutex_t* mutex;

    // Create mutex
    Lmutex_init(&mutex, NULL);

    // Launch non mutex threads
    printf("Thread 1 created with pid %i\n", Lthread_create(&thread1, NULL, no_mutex_count, NULL));
    printf("Thread 2 created with pid %i\n", Lthread_create(&thread2, NULL, no_mutex_count, NULL));

    sleep(6);
    // Launch mutex threads
    printf("Thread 1 created with pid %i\n", Lthread_create(&thread1, NULL, mutex_count, mutex));
    printf("Thread 2 created with pid %i\n", Lthread_create(&thread2, NULL, mutex_count, mutex));

    sleep(12);
}



#endif /* PROJECT2_LIB_LPTHREADS_TESTS_HPP */