#ifndef PROJECT2_LIB_LPTHREADS_THREAD_H
#define PROJECT2_LIB_LPTHREADS_THREAD_H


#include <stdlib.h>


// Define thread attributes
static const int STACK_SIZE = 65536;

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
    FINISHED,
    DETACHED
};

// Define lpthread structure
typedef struct lpthread
{
    pid_t                   thread_id;
    enum lpthread_state     state;
    lpthread_attr_t*        attributes;
} lpthread_t;

#endif /* PROJECT2_LIB_LPTHREADS_THREAD_H */
