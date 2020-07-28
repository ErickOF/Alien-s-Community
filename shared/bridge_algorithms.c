#include "bridge_algorithms.h"

//***********************Y ALGORITHM****************************//
void y_algorithm(Bridge *bridge) {
    printf("Y algorithm \n");

    Lmutex_trylock(bridge->north_mutex);
    Lmutex_trylock(bridge->south_mutex);

    int north_max_index = bridge->north_aliens_number-1;
    int south_max_index = bridge->south_aliens_number-1;
    
    //Check if there are aliens waiting on either side of the bridge
    if ((bridge->north_aliens_number!=0) || (bridge->south_aliens_number!=0)){
        
        //More aliens at north than Y? Let Y north aliens cross
        if (bridge->north_aliens_number >= bridge->y){
            cross_north_aliens(bridge, bridge->y, north_max_index);
        }

        Lmutex_trylock(bridge->north_mutex);
        Lmutex_trylock(bridge->south_mutex);

        //More aliens at south than Y? Let Y south aliens cross    
        if (bridge->south_aliens_number >= bridge->y){
            cross_south_aliens(bridge, bridge->y, south_max_index);
        } 

        else{
            //More aliens at south than North but less than Y? Let all south aliens cross
            if (bridge->south_aliens_number > bridge->north_aliens_number){
                cross_south_aliens(bridge, bridge->south_aliens_number, south_max_index);
            }

            Lmutex_trylock(bridge->north_mutex);
            Lmutex_trylock(bridge->south_mutex);

            //More aliens at north than south but less than Y? Let all north aliens cross
            if (bridge->north_aliens_number > bridge->south_aliens_number){
                cross_north_aliens(bridge, bridge->north_aliens_number, north_max_index);
            }

            Lmutex_trylock(bridge->north_mutex);
            Lmutex_trylock(bridge->south_mutex);

            //Same amount of aliens on either side, but less than Y?
            if (bridge->south_aliens_number == bridge->north_aliens_number){
                //if direction was N-S, stays like that
                if (bridge->direction == 0){
                    cross_north_aliens(bridge, bridge->north_aliens_number, north_max_index);
                } 

                //if direction was S-N, stays like that
                else {
                    cross_south_aliens(bridge, bridge->south_aliens_number, south_max_index);
                }
            }
        }
    }    
}


/************************************************/
void cross_north_aliens(Bridge *bridge, int iterations, int max_index){
   printf("De N-S \n");
   Lmutex_unlock(bridge->south_mutex);
    
    printf("Llamo a check \n");
    //short cross_allowed = check_zero_weight(bridge);
    //printf("cross_allowd %d \n", cross_allowed);
    //Check all aliens crossed to change direction
    //*if (bridge->direction == 1){
        //while(cross_allowed != 0){
          //  cross_allowed = check_zero_weight(bridge);
            //printf("cross_allowed %d \n", cross_allowed);
        //}
    //}
    
    bridge->direction = 0;

    Alien alien;
    alien.status = 6;


    for (int i = 0; i < iterations; i++){
        //Busy Waiting
        short counter = 0;
        short crossing = check_max_weight(bridge, bridge->north_aliens[0].weight);
        while(crossing == 1){
            crossing = check_max_weight(bridge, bridge->north_aliens[0].weight);
            if (counter == 5){
                break;
            }
            counter++;
        }
        //An alien crossing
       // printf("Cruzando alien del norte \n");
        bridge->north_aliens_number -= 1;
        bridge->north_aliens[0].status = 1;

        Lmutex_trylock(bridge->curren_weight_mutex);
       // printf("Aliens weight = %d \n", bridge->north_aliens[0].weight);
        bridge->current_weight = bridge->current_weight + bridge->north_aliens[0].weight;
       // printf("Peso del puente %d \n", bridge->current_weight);
        Lmutex_unlock(bridge->curren_weight_mutex);
            
        //Move aliens in the list
        for (int j = 0; j < max_index; j++) {                
                bridge->north_aliens[j] = bridge->north_aliens[j + 1];
        }
        bridge->north_aliens[max_index] = alien;
    }
    Lmutex_unlock(bridge->north_mutex);
}


/************************************************/
void cross_south_aliens(Bridge *bridge, int iterations, int max_index){
    printf("De S-N \n");
    Lmutex_unlock(bridge->north_mutex);
   
    //short cross_allowed = check_zero_weight(bridge);
    //Check all aliens crossed to change direction
    //if (bridge->direction == 0){
        //while(cross_allowed != 0 && bridge->direction == 0){
            //cross_allowed = check_zero_weight(bridge);
       // }
   // }
     
    bridge->direction = 1;

    Alien alien;
    alien.status = 6;

    for (int i = 0; i < iterations; i++){
        //Busy Waiting
        short crossing = check_max_weight(bridge, bridge->south_aliens[0].weight);
        short counter = 0;
        while(crossing == 1){
            crossing = check_max_weight(bridge, bridge->south_aliens[0].weight);
            if(counter == 5){
                break;
            }
            counter++;
        }
        //An alien crossing
       // printf("Alien del sur cruzando \n");
        bridge->south_aliens_number -= 1;
        bridge->south_aliens[0].status = 1;

        Lmutex_trylock(bridge->curren_weight_mutex);
       // printf("Aliens weight = %d \n", bridge->north_aliens[0].weight);
        bridge->current_weight = bridge->current_weight + bridge->south_aliens[0].weight;
        //printf("Peso del puente %d \n", bridge->current_weight);
        Lmutex_unlock(bridge->curren_weight_mutex);

        //Move aliens in the list
        for (int j = 0; j < max_index; j++){
            bridge->south_aliens[j] = bridge->south_aliens[j + 1];
        }
        bridge->south_aliens[max_index] = alien;
    }
    Lmutex_unlock(bridge->south_mutex);
}


//***********************SEMAPHORE ALGORITHM****************************//
void sem_algorithm(Bridge *bridge){
    printf("Semaphore Algorithm \n");

    clock_t begin;
    double time_spent;

    //Start the time so aliens cross from south to north
    Lmutex_trylock(bridge->north_mutex);
    if(bridge->north_aliens_number != 0){
        Lmutex_unlock(bridge->north_mutex);
        /* Mark beginning time */
        printf("Tiempo total que tarda: %f", bridge->north_waiting_seconds);
        begin = clock();
        unsigned int i;
        time_spent = (double)(clock() - begin) / CLOCKS_PER_SEC;
        printf("Beginning time: %ld \n", begin);

        while(time_spent < bridge->north_waiting_seconds){
            Lmutex_trylock(bridge->north_mutex);
            Lmutex_trylock(bridge->south_mutex);
            while(bridge->north_aliens_number > 0) {
                cross_north_aliens(bridge, 1, bridge->north_aliens_number-1);

                /* Get CPU time since loop started */
                time_spent = (double)(clock() - begin) / CLOCKS_PER_SEC;
                printf("Time spent: %f \n", time_spent);

                if (time_spent>=bridge->north_waiting_seconds)
                    break;
            }
            time_spent = (double)(clock() - begin) / CLOCKS_PER_SEC;
        }
    }

    //Start the time so aliens cross from south to north
    Lmutex_trylock(bridge->south_mutex);
    if(bridge->south_aliens_number != 0){
        Lmutex_unlock(bridge->south_mutex);
        /* Mark beginning time */
        printf("Tiempo total que tarda: %f", bridge->south_waiting_seconds);
        begin = clock();
        unsigned int i;
        printf("Beginning time: %ld \n", begin);
        time_spent = (double)(clock() - begin) / CLOCKS_PER_SEC;

        while(time_spent < bridge->south_waiting_seconds){
            Lmutex_trylock(bridge->south_mutex);
            Lmutex_trylock(bridge->north_mutex);
            while(bridge->south_aliens_number > 0) {
                cross_south_aliens(bridge, 1, bridge->south_aliens_number-1);

                /* Get CPU time since loop started */
                time_spent = (double)(clock() - begin) / CLOCKS_PER_SEC;
                printf("Time spent: %f \n", time_spent);
                
                if (time_spent >= bridge->south_waiting_seconds)
                    break;
            }
            time_spent = (double)(clock() - begin) / CLOCKS_PER_SEC;
        }    
    }
}


//***********************SURVIVAL ALGORITHM****************************//
void survival_algorithm(Bridge *bridge){
    printf("Survival Algorithm \n");
    Lmutex_trylock(bridge->north_mutex);
    Lmutex_trylock(bridge->south_mutex);
    int north_max_index = bridge->north_aliens_number-1;
    int south_max_index = bridge->south_aliens_number-1;
    //Are there aliens in the south?
    if(south_max_index >= 0){
        cross_south_aliens(bridge, bridge->south_aliens_number, south_max_index);
    }
    Lmutex_trylock(bridge->north_mutex);
    Lmutex_trylock(bridge->south_mutex);
    //Aliens in the north?
    if(north_max_index >= 0){
        cross_north_aliens(bridge, bridge->north_aliens_number, north_max_index);
    }
    
}


//************************OTHER FUNCTIONS***************************//
//See if an aliend can cross depending on its weight
short check_max_weight(Bridge *bridge, float weight){
    Lmutex_trylock(bridge->curren_weight_mutex);
    int new_weight = weight + bridge->current_weight;
    if(new_weight > bridge->max_weight){
        printf("Alien no puede cruzar ya que el nuevo peso seria de %d y el puente permite %d", new_weight, bridge->max_weight);
        Lmutex_trylock(bridge->curren_weight_mutex);
        return 1; //False: Can't cross
    }
    else {
        printf("Alien puede cruzar ya que el nuevo peso seria de %d y el puente permite %d", new_weight, bridge->max_weight);
        Lmutex_trylock(bridge->curren_weight_mutex);
        return 0; //True: Can cross
    }
}


//Sees if the bridge is empty
short check_zero_weight(Bridge *bridge){
    Lmutex_trylock(bridge->curren_weight_mutex);
    if(bridge->current_weight > 0){
        printf("El peso del puente es: %d, por lo que no se puede cambiar la direccion del puente \n", bridge->current_weight);
        bridge->current_weight = bridge->current_weight - 2.1; 
        Lmutex_unlock(bridge->curren_weight_mutex);
        return 1; //False: Can't change
    }

    else {
        printf("El peso del puente es: %d, por lo que ya se puede cambiar la direccion del puente \n", bridge->current_weight);
        Lmutex_unlock(bridge->curren_weight_mutex);
        return 0; //True: Can change
    }
}