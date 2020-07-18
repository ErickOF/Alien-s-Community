#ifndef PROJECT2_LIB_LPTHREAD_H
#define PROJECT2_LIB_LPTHREAD_H

#define _GNU_SOURCE             /* See feature_test_macros(7) */
#include <linux/sched.h>

#include <stdlib.h>
#include <semaphore.h>




// Define thread attributes
const int STACK_SIZE = 65536;
typedef struct lpthread_attr 
{
	int	    flags;

	void*   stackaddr_attr;

	size_t  stacksize_attr;
} lpthread_attr_t;


// Define posible stated of the thread
enum lpthread_state
{
    RUNNING,
    DEAD,
    EXITING,
    SLEEPING,
    JOINING
};

// Define lpthread structure
typedef struct lpthread
{
    pid_t                   thread_id;

    enum lpthread_state     state;

    struct lpthread_attr    attributes;

    unsigned short          isDettached;

} lpthread_t;

// Define a mutex as a semaphore
#define MUTEX_NAME_LEN 10
typedef struct lpthread_mutex{

    char mutex_name[MUTEX_NAME_LEN];

    sem_t mutex;

} lpthread_mutex_t;


// Define manager thread
lpthread_t manager_thread;
/* Array of threads data

    MAX_THREADS:            Defines the maximum available threads

    size_t latest_entry:    Defines the lowest free thread position

    lpthread_t threads:     Array of lpthreads with size MAX_THREADS

 */
#define MAX_THREADS 100
size_t latest_entry = 0;
lpthread_t threads[MAX_THREADS]; 



// Clone flags
const int clone_flags = CLONE_VM;


// Create thread function
int Lthread_create( lpthread_t** lpthread_ptr,
                    lpthread_attr_t** lpthread_attr, 
                    int (*target_function) (void*), 
                    void* args);

// Kills the desired thread
int Lthread_end(lpthread_t* lpthread_ptr);

// Yield back thread
// TODO: USE A SLEEP TO FORCE CONTEXT SWITCH
int Lthread_yield();


int Lthread_join();
int Lthread_detach();
int Lmutex_init();
int Lmutex_destroy();
int Lmutex_unlock();
int Lmutex_trylock();

#endif /* PROJECT2_LIB_LPTHREAD_H */
