#include "bridge_algorithms.h"


void y_algorithm(Bridge bridge) {
    printf("Aliens al norte Inicial: %d", bridge.north_aliens_number);
    printf("Aliens al sur Inicial: %d", bridge.south_aliens_number);
    while ((bridge.north_aliens_number!=0) && (bridge.south_aliens_number!=0)){
        if (bridge.north_aliens_number >= bridge.y){
            bridge.direction = 0;
            for (int i=0; i<=bridge.y; i++){
                bridge.north_aliens_number -= 1;
                printf("(mayor y)Aliens al norte: %d", bridge.north_aliens_number);
            }
        }

        if (bridge.south_aliens_number >= bridge.y){
            bridge.direction = 1;
            for (int j=0; j<=bridge.y; j++) {
                bridge.south_aliens_number -= 1;
                printf("(mayor y) Aliens al sur: %d", bridge.south_aliens_number);
            }
        }

        if (bridge.south_aliens_number > bridge.north_aliens_number){
            bridge.direction = 1;
            for (int i=bridge.south_aliens_number; i>0; i--){
                bridge.south_aliens_number -= 1;
                printf("(mayor q norte)Aliens al sur: %d", bridge.south_aliens_number);
            }
        }

        if (bridge.north_aliens_number > bridge.south_aliens_number){
            bridge.direction = 0;
            for (int i=bridge.north_aliens_number; i>0; i--){
                bridge.north_aliens_number -= 1;
                printf("(mayor q sur)Aliens al norte: %d", bridge.north_aliens_number);
            }
        }
        if (bridge.south_aliens_number == bridge.north_aliens_number){
            if (bridge.direction == 0){
                for (int i=bridge.north_aliens_number; i>0; i--){
                bridge.north_aliens_number -= 1;
                printf("(dir)Aliens al norte: %d", bridge.north_aliens_number);
                }
            }
            else {
                for (int j=bridge.south_aliens_number; j>0; j--){
                bridge.south_aliens_number -= 1;
                printf("(dir)Aliens al sur: %d", bridge.north_aliens_number);
                }
            }
        }
    }    
}
