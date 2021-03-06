#ifndef PROJECT2_LIB_LPTHREAD_H
#define PROJECT2_LIB_LPTHREAD_H

#define _GNU_SOURCE             /* See feature_test_macros(7) */
#include <linux/sched.h>

#include <stdlib.h>


#include "lpthreads_thread.h"
#include "lpthreads_mutex.h"
#include "lpthreads_tools.h"


#define MAX_THREADS 100


// Clone flags
static const int clone_flags = CLONE_VM;

// Mantain the system coherent and safe :)
int sannity_check();

// Create thread function
pid_t Lthread_create(lpthread_t** lpthread_ptr,
                     lpthread_attr_t** lpthread_attr, 
                     int (*target_function) (void*), 
                     void* args);

// Exit the process and set the thread as ready to join
int Lthread_end(void* args);

// Yield back thread
int Lthread_yield();

// Wait for all the joinable threads to terminate
int Lthread_join(lpthread_t* lpthread_ptr);

// Make a thread un-joinable
int Lthread_detach(lpthread_t* lpthread_ptr);

// Initialize a mutex
int Lmutex_init(lpthread_mutex_t** mutex, lpthread_mutex_attr_t** attributes);

// Destroy a mutex
int Lmutex_destroy(lpthread_mutex_t* mutex);

// Unlock a mutex
int Lmutex_unlock(lpthread_mutex_t* mutex);

// Lock a mutex
int Lmutex_trylock(lpthread_mutex_t* mutex);


void add_thread(pid_t target, lpthread_t** lpthread_ptr);
size_t search_target_pid(pid_t pid);


#endif /* PROJECT2_LIB_LPTHREAD_H */
