#include "shared/bridge_algorithms.h"
#include <stdlib.h>

int main() {
    Bridge bridge;
    bridge.y = 2;
    bridge.direction = 0;
    bridge.south_aliens_number = 6;
    bridge.north_aliens_number = 5;
    bridge.max_south_aliens = 10;
    bridge.max_north_aliens = 10;
    bridge.south_aliens = (Alien*) malloc(sizeof(Alien) * bridge.max_south_aliens);
    bridge.north_aliens = (Alien*) malloc(sizeof(Alien) * bridge.max_north_aliens);
    bridge.current_aliens = (Alien*) malloc(sizeof(Alien) * (bridge.max_north_aliens + bridge.max_south_aliens));
    int max_number = bridge.south_aliens_number+bridge.north_aliens_number;

    for (int i = 0; i < bridge.north_aliens_number - 1; i++) {
        Alien alien;
        alien.status = 3;
        bridge.north_aliens[i] = alien;
        printf("Alien %d: status %d\n", i, bridge.north_aliens[i].status);
    }

    for (int i = 0; i < bridge.south_aliens_number; i++) {
        Alien alien;
        alien.status = 3;
        bridge.south_aliens[i] = alien;
        printf("Alien %d: status %d\n", i, bridge.south_aliens[i].status);
    }

    for (int i = 0; i < bridge.south_aliens_number; i = i+2) {
        Alien alien;
        alien.status = 2;
        bridge.south_aliens[i] = alien;
        printf("Alien %d: status %d\n", i, bridge.south_aliens[i].status);
    }

    for (int i = 0; i < bridge.north_aliens_number; i = i+2) {
        Alien alien;
        alien.status = 2;
        bridge.north_aliens[i] = alien;
        printf("Alien %d: status %d\n", i, bridge.south_aliens[i].status);
    }

    y_algorithm(&bridge);
    for(int j = 0; j < bridge.max_north_aliens; j++){
        printf("Alien norte: %d \n", bridge.north_aliens[j].status);
    }
    
    for(int j = 0; j < bridge.max_south_aliens; j++){
        printf("Alien sur: %d \n", bridge.south_aliens[j].status);
    }


    for (int n=0; n<max_number;n++){
        printf("Status Aliens cruzaron: %d \n", bridge.current_aliens[n].status);
    }

    free(bridge.north_aliens);
    free(bridge.south_aliens);
    free(bridge.current_aliens);

    return 0;
}
