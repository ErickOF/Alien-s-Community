#include "scheduler.h"


void sjf_sch(Alien* bridge_aliens, int current_max){

    for (size_t i = 0; i <= current_max - 1; ++i)
    {
        
        for (size_t j = (i + 1); j <= current_max; ++j)
        {

            // If aj->speed > ai->speed
            if(bridge_aliens[j].speed > bridge_aliens[i].speed){
               // Create a temporary copy of bridge_aliens + j in aj
                Alien tmp = bridge_aliens[j]; 
                // Overwrite bridge_aliens + j with bridge_aliens + i
                bridge_aliens[j] = bridge_aliens[i];
                // Move the contents in aj into bridge_aliens + i
                bridge_aliens[i] = tmp;
            }
            
        }
        
    }

}


void priority_sch(Alien* bridge_aliens, int current_max){

    for (size_t i = 0; i <= current_max - 1; ++i)
    {
        
        for (size_t j = (i + 1); j <= current_max; ++j)
        {

            // If aj->priority < ai->priority
            if(bridge_aliens[j].priority < bridge_aliens[i].priority){
                // Create a temporary copy of bridge_aliens + j in aj
                Alien tmp = bridge_aliens[j]; 
                // Overwrite bridge_aliens + j with bridge_aliens + i
                bridge_aliens[j] = bridge_aliens[i];
                // Move the contents in aj into bridge_aliens + i
                bridge_aliens[i] = tmp;
            }
            
        }
        
    }
}


void lottery_sch(Alien* bridge_aliens, int current_max){

    // Since every alien has the same probability of happening
    // the lotery process can be modeled as a simple shuffle  of the array
    for (size_t i = 0; i < current_max - 1; i++) {
        // Generate random pos
        size_t j = i + rand() / (RAND_MAX / (current_max - i) + 1);
        // Copy random pos data
        Alien t = bridge_aliens[j];
        // Overwrite random pos with current pos
        bridge_aliens[j] = bridge_aliens[i];
        // Overwite the current os with the random pos copy
        bridge_aliens[i] = t;
    }

}





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
                enum schedulers sch){

    // Get the ptr to the correct line
    Alien* waiting_line;
    int current_max, max_avail;
    // If they come from the north then get the north line
    if (comesFrom == NORTH){
        waiting_line = bridge->north_aliens;
        current_max = bridge->north_aliens_number++;
        max_avail = bridge->max_north_aliens;
    }
    // If they come from the south then get the south line
    else {
        waiting_line = bridge->south_aliens;
        current_max = bridge->south_aliens_number++;
        max_avail = bridge->max_south_aliens;
    }

    // Check if we are full
    if(max_avail < current_max)
    {
        return -1;
    }
    else if(waiting_alien != NULL){
        // Set the value to the new current max
        waiting_line += current_max;
        *waiting_line = *waiting_alien;
        // Reduce the ptr again for it to reference 
        // the begining of the array
        waiting_line -= current_max;

    }    
    

    // Select the scheduler
    switch (sch)
    {
        case FIFO:
            break;

        case SJF:
            sjf_sch(waiting_line, current_max);
            break;

        case PRIORITY:
            priority_sch(waiting_line, current_max);
            break;
        
        case LOTTERY:
            lottery_sch(waiting_line, current_max);
            break;
        
        default:
            break;
    }


    return 0;

}

