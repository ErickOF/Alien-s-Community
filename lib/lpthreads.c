
#ifndef PROJECT2_LIB_LPTHREAD_C
#define PROJECT2_LIB_LPTHREAD_C

#include "lpthreads.h"
#include "lpthreads_tools.c"

#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Functions
/**
 * This function creates a thread
 * 
 * Params:
 *      lpthread_t** lpthread_ptr       -   Variable to return a reference of the created 
 *                                          lpthread structure to caller
 *      
 *      lpthread_attr_t** lpthread_attr -   Used to return the atributes of the created 
 *                                          lpthread to the caller  
 *      
 *      void* (*target_function) (void*)-   Function to execute  
 *      
 *      void* args                      -   Arguments of the function    
 * 
 * Returns
 *     int pid of the created process.
 */
int Lthread_create( lpthread_t** lpthread_ptr,
                    lpthread_attr_t** lpthread_attr, 
                    int (*target_function) (void*), 
                    void* args)
{

    // Allocate stack for child task.
    char* stack = allocate_mem(STACK_SIZE);

    // Launch the thread
    // Set it to stop and start it later when the structure is ready
    int thread_id = clone_call(target_function, stack + STACK_SIZE, clone_flags, args);

    // Allocate memory for the attributes and the structure
    *lpthread_ptr = allocate_mem(sizeof(lpthread_attr_t));
    *lpthread_attr = allocate_mem(sizeof(lpthread_t));

    // Instantiate the lpthread_attr structure
    (*lpthread_attr)->flags = clone_flags;
    (*lpthread_attr)->stackaddr_attr = stack;
    (*lpthread_attr)->stacksize_attr = STACK_SIZE;

    // Instantiate the lpthread structure
    (*lpthread_ptr)->thread_id = thread_id;
    (*lpthread_ptr)->state = RUNNING;
    (*lpthread_ptr)->attributes = *(*lpthread_attr);
    (*lpthread_ptr)->isDettached = FALSE;
    
    return thread_id;

}



/**
 * This function kills a thread
 * 
 * Params:
 *      lpthread_t* lpthread_ptr    -   ptr to the thread to be killed
  
 * 
 * Returns
 *     int pid of the created process.
 */
int Lthread_end(lpthread_t* lpthread_ptr){

    // First try to end the process gracefully
    kill(lpthread_ptr->thread_id, SIGTERM);
    // Wait for the process to finish
    sleep(1);

    // Check if the process is killed
    pid_t killed_pid;
    int status;
    killed_pid = waitpid(lpthread_ptr->thread_id, &status, WNOHANG);

    // On succes we have the pid of the process who changes state (a.k.a died)
    
    // On error we get -1
    if(killed_pid == -1){
        perror("waitpid_term");
        exit(EXIT_FAILURE);
    }
    // If the process hasn't changed state we get 0 (a.k.a is alive)
    else if(killed_pid == 0){
        // So we force the kill
        kill(lpthread_ptr->thread_id, SIGKILL);
        // Deallocate resources for the thread and harvest it, this is to avoid zombie threads
        killed_pid = waitpid(lpthread_ptr->thread_id, &status, 0);
        // Handle in case of errors
        if(killed_pid == -1){
            perror("waitpid_kill");
            exit(EXIT_FAILURE);
        }
    
    }

    return killed_pid;

}




#endif /* PROJECT2_LIB_LPTHREAD_C */


