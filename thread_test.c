#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

#include "lib/lpthreads.h"


void hey(){

    while(1){
        printf("Hey its me child pid %i, am alive\n", getpid());
        sleep(1);
    }

}



int main(){

    printf("\nIts on bitch\n");
    //lpthread_t* thread;
    /*int child_pid = Lthread_create(&thread, NULL, hey, NULL);

    printf( "Hey its me parent, the returned pid was %i and the thread pid is %i\nNow am wonna sleep for a while\n", 
            child_pid, thread->thread_id);
    sleep(10);

    printf("Now am gonna do what is called a pro-gamer move and kill my child and then sleep\n");
    if(Lthread_end(thread) == child_pid){
        printf("Looks like it worked\n");
    }

    sleep(5);

    printf("My time has come my friend, its been a good ride, see ya\n");*/
}