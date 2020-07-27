#include "bridge_algorithms.h"

//***********************Y ALGORITHM****************************//
void y_algorithm(Bridge *bridge) {
    Lmutex_trylock(bridge->north_mutex);
    Lmutex_trylock(bridge->south_mutex);
    int north_max_index = bridge->north_aliens_number-1;
    int south_max_index = bridge->south_aliens_number-1;
    if ((bridge->north_aliens_number!=0) || (bridge->south_aliens_number!=0)){
        if (bridge->north_aliens_number >= bridge->y){
            cross_north_aliens(bridge, bridge->y, north_max_index);
        }

        Lmutex_trylock(bridge->north_mutex);
        Lmutex_trylock(bridge->south_mutex);    
        if (bridge->south_aliens_number >= bridge->y){
            cross_south_aliens(bridge, bridge->y, south_max_index);
        } 

        else{
            if (bridge->south_aliens_number > bridge->north_aliens_number){
                cross_south_aliens(bridge, bridge->south_aliens_number, south_max_index);
            }

            Lmutex_trylock(bridge->north_mutex);
            Lmutex_trylock(bridge->south_mutex);
            if (bridge->north_aliens_number > bridge->south_aliens_number){
                cross_north_aliens(bridge, bridge->north_aliens_number, north_max_index);
            }

            Lmutex_trylock(bridge->north_mutex);
            Lmutex_trylock(bridge->south_mutex);
            if (bridge->south_aliens_number == bridge->north_aliens_number){
                if (bridge->direction == 0){
                    cross_north_aliens(bridge, bridge->north_aliens_number, north_max_index);
                } 
                
                else {
                    cross_south_aliens(bridge, bridge->south_aliens_number, south_max_index);
                }
            }
        }
    }    
}

void cross_north_aliens(Bridge *bridge, int iterations, int max_index){
    Lmutex_unlock(bridge->south_mutex);
    bridge->direction = 0;

    Alien alien;
    alien.status = 6;


    for (int i = 0; i < iterations; i++){
        //Busy Waiting
        short counter = 0;
        short crossing = check_weight(bridge, bridge->north_aliens[0].weight);
        while(crossing == 1){
            crossing = check_weight(bridge, bridge->north_aliens[0].weight);
            if (counter == 5){
                break;
            }
            counter++;
        }

        bridge->north_aliens_number -= 1;
        bridge->north_aliens[0].status = 1;
        bridge->current_weight += bridge->north_aliens[0].weight;

        for (int j = 0; j < max_index; j++) {                
            bridge->north_aliens[j] = bridge->north_aliens[j + 1];
        }
        bridge->north_aliens[max_index] = alien;
    }
    Lmutex_unlock(bridge->north_mutex);
}

void cross_south_aliens(Bridge *bridge, int iterations, int max_index){
    Lmutex_unlock(bridge->north_mutex);
    bridge->direction = 1;

    Alien alien;
    alien.status = 6;

    for (int i = 0; i < iterations; i++){
        //Busy Waiting
        short crossing = check_weight(bridge, bridge->south_aliens[0].weight);
        short counter = 0;
        while(crossing == 1){
            crossing = check_weight(bridge, bridge->south_aliens[0].weight);
            if(counter == 5){
                break;
            }
            counter++;
        }

        bridge->south_aliens_number -= 1;
        bridge->south_aliens[0].status = 1;
        bridge->current_weight += bridge->south_aliens[0].weight;

        for (int j = 0; j < max_index; j++){
            bridge->south_aliens[j] = bridge->south_aliens[j + 1];
        }
        bridge->south_aliens[max_index] = alien;
    }
    Lmutex_unlock(bridge->south_mutex);
}

//***********************SEMAPHORE ALGORITHM****************************//
void sem_algorithm(Bridge *bridge){

    clock_t begin;
    double time_spent;
    unsigned int i;

    /* Mark beginning time */
    begin = clock();
    printf("Beginning time: %ld \n", begin);
    for (i = 0 ; 1; i++)
        {
        printf("hello\n");
        /* Get CPU time since loop started */
        time_spent = (double)(clock() - begin) / CLOCKS_PER_SEC;
        printf("Time spent: %f \n", time_spent);
        if (time_spent>=bridge->north_waiting_seconds)
            break;
        }

    //**bridge->south_waiting_seconds;**//
}

//***********************SURVIVAL ALGORITHM****************************//
void survival_algorithm(Bridge *bridge){
    Lmutex_trylock(bridge->north_mutex);
    Lmutex_trylock(bridge->south_mutex);
    int north_max_index = bridge->north_aliens_number-1;
    int south_max_index = bridge->south_aliens_number-1;
    if(south_max_index >= 0){
        cross_south_aliens(bridge, bridge->south_aliens_number, south_max_index);
    }
    Lmutex_trylock(bridge->north_mutex);
    Lmutex_trylock(bridge->south_mutex);
    if(north_max_index >= 0){
        cross_north_aliens(bridge, bridge->north_aliens_number, north_max_index);
    }
    
}


//************************EXTRA FUNCTIONS***************************//
short check_weight(Bridge *bridge, float weight){
    float new_weight = weight + bridge->current_weight;
    printf("Aliens weight: %f \n", weight);
    printf("Bridge max weight: %f \n", bridge->max_weight);
    printf("Bridge current weight: %f \n ", bridge->current_weight);
    printf("Total weight if alien crosses: %f \n", new_weight);
    if(new_weight > bridge->max_weight){
        return 1; //False: Can't cross
    }
    else {
        return 0; //True: Can cross
    }
}