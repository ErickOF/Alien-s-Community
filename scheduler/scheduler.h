#ifndef PROJECT2_SCHEDULER_SCHEDULER_H
#define PROJECT2_SCHEDULER_SCHEDULER_H

#include "../shared/structs.h"
#include "../lib/lpthreads.h"
#include <stdlib.h>


void sjf_sch(Alien* bridge_aliens, int current_max);

void priority_sch(Alien* bridge_aliens, int current_max);

void lottery_sch(Alien* bridge_aliens, int current_max);


/**
 *  This function is an interface to call any scheduler
 * 
 *  Params:
 *      Bridge* bridge              -   ptr of the bridge we are working on
 *      Alien* waiting_alien        -   ptr of the alien on the waiting line
 *      enum cardinals comesFrom    -   Defines if the alien comes from north or south
 *      enum schedulers sch         -   Defines the scheduler we are gonna use
 *
 */
int scheduler(  Bridge* bridge, 
                Alien* waiting_alien, 
                enum cardinals comesFrom,
                enum schedulers sch);


#endif /* PROJECT2_SCHEDULER_SCHEDULER_H */
