#include "bridge_algorithms.h"


void y_algorithm(Bridge *bridge) {
    while ((bridge->north_aliens_number!=0) || (bridge->south_aliens_number!=0)){
        if (bridge->north_aliens_number >= bridge->y){
            cross_north_aliens(bridge, bridge->y);
        }

        if (bridge->south_aliens_number >= bridge->y){
            cross_south_aliens(bridge, bridge->y);
        }

        else{
            if (bridge->south_aliens_number > bridge->north_aliens_number){
                cross_south_aliens(bridge, bridge->south_aliens_number);
            }

            if (bridge->north_aliens_number > bridge->south_aliens_number){
                cross_north_aliens(bridge, bridge->north_aliens_number);
            }
            if (bridge->south_aliens_number == bridge->north_aliens_number){
                if (bridge->direction == 0){
                    cross_north_aliens(bridge, bridge->north_aliens_number);
                }
                else {
                    cross_south_aliens(bridge, bridge->south_aliens_number);
                }
            }
        }
    }    
}

void cross_north_aliens(Bridge *bridge, int iterations){
    bridge->direction = 0;
    Alien alien;
    int max_index;
    alien.status = 6;
    max_index = (bridge->max_north_aliens-1);
        for (int i=0; i<iterations; i++){
            bridge->north_aliens_number -= 1;
            bridge->north_aliens[0].status = 1;
            bridge->current_aliens[i] = bridge->north_aliens[0];
            printf("Alien norte-sur: %d \n", bridge->current_aliens[i].status);
            for (int j=0;j<max_index;j++){                
                bridge->north_aliens[j] = bridge->north_aliens[j+1];
                printf("Alien norte: %d \n", bridge->current_aliens[j].type);                
            } 
            bridge->north_aliens[max_index] = alien;           
        }
}

void cross_south_aliens(Bridge *bridge, int iterations){
    bridge->direction = 1;
    Alien alien;
    int max_index;
    alien.status = 6;
    max_index = (bridge->max_south_aliens-1);
        for (int i=0; i<iterations; i++){
            bridge->south_aliens_number -= 1;
            bridge->south_aliens[0].status = 1;
            bridge->current_aliens[i] = bridge->south_aliens[0];
            printf("Alien sur-norte: %d \n", bridge->current_aliens[i].status);
            for (int j=0;j<max_index;j++){
                bridge->south_aliens[j] = bridge->south_aliens[j+1];
                printf("Alien sur: %d \n", bridge->current_aliens[j].type);                
            } 
            bridge->south_aliens[max_index] = alien;           
        }
}
