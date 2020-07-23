#ifndef PROJECT2_LIB_LPTHREAD_H
#define PROJECT2_LIB_LPTHREAD_H

#define _GNU_SOURCE             /* See feature_test_macros(7) */
#include <linux/sched.h>

#include <stdlib.h>


#include "lpthreads_thread.h"
#include "lpthreads_mutex.hpp"







// Define manager thread
lpthread_t manager_thread;
/* Array of threads data

    MAX_THREADS:            Defines the maximum available threads

    short isInitialized:    Defines if the array is initialized

    pid_t threads:          Array with the unkilled threads

 */
#define MAX_THREADS 100
short isInitialized = 0;
pid_t threads[MAX_THREADS]; 



// Clone flags
const int clone_flags = CLONE_VM;


// Create thread function
pid_t Lthread_create(lpthread_t** lpthread_ptr,
                    lpthread_attr_t** lpthread_attr, 
                    int (*target_function) (void*), 
                    void* args);

// Kills the desired thread
pid_t Lthread_end(lpthread_t* lpthread_ptr);

// Yield back thread
// TODO: USE A SLEEP TO FORCE CONTEXT SWITCH
int Lthread_yield();

int sannity_check();
int Lthread_join();
int Lthread_detach();
int Lmutex_init(lpthread_mutex_t** mutex, lpthread_mutex_attr_t** attributes);
int Lmutex_destroy(lpthread_mutex_t* mutex);
int Lmutex_unlock(lpthread_mutex_t* mutex);
int Lmutex_trylock(lpthread_mutex_t* mutex);


void add_thread(pid_t target);
void remove_thread(pid_t target);

#endif /* PROJECT2_LIB_LPTHREAD_H */
