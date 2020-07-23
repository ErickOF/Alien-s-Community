
#ifndef PROJECT2_LIB_LPTHREAD_C
#define PROJECT2_LIB_LPTHREAD_C

#include "lpthreads.h"
#include "lpthreads_tools.c"

#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

// Functions

/**
 *  This function makes sure that the process list is instantiated and
 *  checks if therea are processes that finished and need to be removed from 
 *  the threads list.
 *
 *  Returns
 *     int 0 if there are free spaces in the threads array, -1 if it's full
 */
int sannity_check(){

    // Initialize the thread array in case this is the first time called
    if(!isInitialized){

        // Initialize sandom seed generator
        srand(time(NULL));

        // Set all the pid's to -1
        for (size_t i = 0; i < MAX_THREADS; ++i)
        {
            threads[i] = -1;
        }
        // Set the array as initialized
        isInitialized = 1;
        // There are free spaces so return 0
        return 0;
    }
    // If the list has been initialized then check if there are processes that 
    // finished naturally and need to be removed from the list
    else{
        int ret = -1;
        // Check if the other processes are valid
        for (size_t i = 0; i < MAX_THREADS; ++i)
        {
            int status;
            // Check this is a valid pid
            if(threads[i] != -1){
                
                // If we get error its because the thread does no exist
                if(waitpid(threads[i], &status, WNOHANG) == -1){
                    // Set the process as invalid
                    threads[i] = -1;
                    // Set the return value
                    ret = 0;
                }

            }
            else{
                // Set the return value
                ret = 0;
            }
        }

        return ret;

    }
}




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
 *     pid_t pid of the created process.
 */
pid_t Lthread_create( lpthread_t** lpthread_ptr,
                    lpthread_attr_t** lpthread_attr, 
                    int (*target_function) (void*), 
                    void* args)
{

    // Sannity check allways before doing anything
    sannity_check();

    // Allocate stack for child task.
    char* stack = allocate_mem(STACK_SIZE);

    // Launch the thread
    // Set it to stop and start it later when the structure is ready
    pid_t thread_id = clone_call(target_function, stack + STACK_SIZE, clone_flags, args);

    // Allocate memory for the attributes and the structure
    lpthread_t* ptr = allocate_mem(sizeof(lpthread_t));
    lpthread_attr_t* attr = allocate_mem(sizeof(lpthread_attr_t));

    // Instantiate the lpthread_attr structure
    attr->flags = clone_flags;
    attr->stackaddr_attr = stack;
    attr->stacksize_attr = STACK_SIZE;

    // Instantiate the lpthread structure
    ptr->thread_id = thread_id;
    ptr->state = RUNNING;
    ptr->attributes = attr;
    ptr->isDettached = FALSE;

    // If we have a structure to reference then
    // update the ptr
    if(lpthread_ptr != NULL){
        *lpthread_ptr = ptr;
    }
    // Same for attr
    if(lpthread_attr != NULL){
        *lpthread_attr = attr;
    }

    // Add it to thre array of threads
    add_thread(thread_id);
    
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
pid_t Lthread_end(lpthread_t* lpthread_ptr)
{

    // First try to end the process gracefully
    kill(lpthread_ptr->thread_id, SIGTERM);
    // Wait for the process to finish
    sleep(1);

    // Check if the process is killed
    pid_t killed_pid;
    int status;
    killed_pid = waitpid(lpthread_ptr->thread_id, &status, WNOHANG);

    // On succes we have the pid of the process who changes state (a.k.a died)
    // On error we get -1, this means the process doesnt exist
    // If the process hasn't changed state we get 0 (a.k.a is alive)
    if(killed_pid == 0){
        // So we force the kill
        kill(lpthread_ptr->thread_id, SIGKILL);
        // Deallocate resources for the thread and harvest it, this is to avoid zombie threads
        killed_pid = waitpid(lpthread_ptr->thread_id, &status, 0);
        // Handle in case of errors
        if(killed_pid != -1){
            perror("waitpid_kill_proccess_alive");
            exit(EXIT_FAILURE);
        }
    
    }

    // Store the pid
    killed_pid = lpthread_ptr->thread_id;

    /* Free heap resources */
    // Free the thread stack
    free(lpthread_ptr->attributes->stackaddr_attr);
    // Free the atributes
    free(lpthread_ptr->attributes);
    // Free the thread structure
    free(lpthread_ptr);

    // Remove process from array
    remove_thread(killed_pid);

    // Sannity check allways 
    sannity_check();

    return killed_pid;

}






// USE SYSTEM V SEMAPHORES INSTEAD OF POSIX






/**
 *  This function creates a mutex
 * 
 *  Params:
 *      lpthread_mutex_t** mutex            -   Reference to the ptr of the created mutex
 *      lpthread_mutex_attr_t** attributes  -   Reference to the ptr of the created mutex attributes
  
 * 
 *  Returns
 *      int succes on the operation
 */
int Lmutex_init(lpthread_mutex_t** mutex, lpthread_mutex_attr_t** attributes){

    // As always sanity check 
    sannity_check();

    // Allocate memory for the attributes and the MUTEX
    lpthread_mutex_t* ptr = allocate_mem(sizeof(lpthread_mutex_t));
    lpthread_mutex_attr_t* attr = allocate_mem(sizeof(lpthread_mutex_attr_t));


    // Set mutex type
    attr->type = DEFAULT;

    // Create the mutex structure
    ptr->attributes = attr;
    ptr->sem_id = create_sem(sem_counter++, 1);

    // If we have a structure to reference then
    // update the ptr
    if(mutex != NULL){
        *mutex = ptr;
    }
    // Same for attr
    if(attributes != NULL){
        *attributes = attr;
    }


    return 0;



}

/**
 *  This function destroys a mutex
 * 
 *  Params:
 *      lpthread_mutex_t* mutex     -       Reference to the mutex to be deleted  
 * 
 *  Returns
 *      int success of the operation
 */
int Lmutex_destroy(lpthread_mutex_t* mutex){

    // As always sanity check 
    sannity_check();

    // Close the semaphore
    union semun sem_state;
    if (semctl(mutex->sem_id, 0, IPC_RMID, sem_state) == -1) 
    {
        perror("semctl");
        exit(1); 
    }

    // Free the memory
    free(mutex->attributes);
    free(mutex);

    return 0;
}

/**
 *  This function creates a thread
 * 
 *  Params:
 *      lpthread_mutex_t* mutex     -       Reference to the mutex to be unlocked  
 * 
 *  Returns
 *      int success of the operation
 */
int Lmutex_unlock(lpthread_mutex_t* mutex){

    // Value of the semaphore
    if (semop(mutex->sem_id, &sem_post, 1) == -1) {
        perror("semop_post");
        exit(EXIT_FAILURE); 
        
    }
    return 0;

}

/**
 *  This function creates a thread
 * 
 *  Params:
 *      lpthread_mutex_t* mutex     -       Reference to the mutex to be locked  
 * 
 *  Returns
 *      int success of the operation
 */
int Lmutex_trylock(lpthread_mutex_t* mutex){

    // Value of the semaphore
    if (semop(mutex->sem_id, &sem_wait, 1) == -1) {
        perror("semop_wait");
        exit(EXIT_FAILURE); 
        
    }

}




/*
 *  This function searches for a free space in the thread array and 
 *  sets its pid value 
 *
 * 
 *  Params:
 *      pid_t target - Identifier of the new process.
 */
void add_thread(pid_t target){

    int isFound = 0;

    for (size_t i = 0; i < MAX_THREADS; i++)
    {
        if(threads[i] == -1){
            isFound = 1;
            threads[i] = target;
            break;
        }
    }

    if(!isFound){
        perror("attempted_to_add_when_full");
        exit(EXIT_FAILURE);
    }
    
}




/*
 *  This function searches for a pid in a array and set it to -1
 * 
 *  Params:
 *      pid_t target - pid to remove from the list.
 */
void remove_thread(pid_t target){

    int isFound = 0;

    for (size_t i = 0; i < MAX_THREADS; i++)
    {
        if(threads[i] == target){
            isFound = 1;
            threads[i] = -1;
            break;
        }
    }

    if(!isFound){
        perror("attempted_to_remove_invalid_thread");
        exit(EXIT_FAILURE);
    }
    
}




#endif /* PROJECT2_LIB_LPTHREAD_C */


