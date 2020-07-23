#ifndef PROJECT2_LIB_LPTHREADS_MUTEX_H
#define PROJECT2_LIB_LPTHREADS_MUTEX_H


#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdlib.h>
#include <stdio.h>


// Define mutex attributes
#define MUTEX_NAME_LEN 10


// Structure to operate the semaphore
union semun {
    int val;
    struct semid_ds *buf;
    unsigned short  *array;
};

// Post and wait
struct sembuf sem_wait = { 0, -1, 0};
struct sembuf sem_post = { 0, +1, 0};


// Define posible mutex characteristics
enum lpthread_mutex_type
{
    NORMAL,
    ERRORCHECK,
    RECURSIVE,
    DEFAULT,
};

typedef struct lpthread_mutex_attr{

    enum lpthread_mutex_type    type;

} lpthread_mutex_attr_t;


// Define a mutex as a semaphore
// Semaphore flags
const int SEM_FLAGS = 0666 | IPC_CREAT;
key_t sem_counter = 0;
typedef struct lpthread_mutex{

    lpthread_mutex_attr_t*  attributes;

    int                     sem_id;

} lpthread_mutex_t;




// Functions
/**
 *  This function creates a semaphore and manages errors
 * 
 *  Params:
 *      key_t key         -       Id to the semaphore.
 *      int num_sems    -       Number of semphores to be created.
 *      int flags       -       Creation flags of the semaphore.
 * 
 *  Returns
 *      int id of the created semaphore.
 */
int create_sem(key_t key, int num_sems){

    // Create the semaphore 
    int semid = semget(key, num_sems, SEM_FLAGS);
    // Error code is -1
    if(semid < 0)
    {
        perror("semget"); 
        exit(EXIT_FAILURE);
    }

    // Initialize semaphore to 1
    union semun sem_state;  // This union is necesary to set the 
    sem_state.val = 1;      // semaphore state
    if (semctl(semid, 0, SETVAL, sem_state) == -1) 
    {
        perror("semctl_initilization");
        exit(EXIT_FAILURE); 
    }

    // Return the sem_id
    return semid;
}




#endif /* PROJECT2_LIB_LPTHREADS_MUTEX_H */