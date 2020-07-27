#include "shared/bridge_algorithms.h"
#include <stdlib.h>

int main() {
    Bridge bridge = {
        .y = 2, .direction = 0,
        .south_aliens_number = 6,
        .north_aliens_number = 5,
        .max_south_aliens = 10,
        .max_north_aliens = 10,
        .max_weight = 5,
        .north_waiting_seconds = 0.004,
        .south_waiting_seconds = 0.006
    };

    Lmutex_init(&bridge.south_mutex, NULL);
    Lmutex_init(&bridge.north_mutex, NULL);


    bridge.south_aliens = (Alien*) malloc(sizeof(Alien) * bridge.max_south_aliens);
    bridge.north_aliens = (Alien*) malloc(sizeof(Alien) * bridge.max_north_aliens);
    int max_number = bridge.south_aliens_number+bridge.north_aliens_number;

    for (int i = 0; i < bridge.north_aliens_number - 1; i++) {
        bridge.north_aliens[i].status = 3;
        bridge.north_aliens[i].weight = 2.1;
    }

    for (int i = 0; i < bridge.south_aliens_number; i++) {
        bridge.north_aliens[i].status = 3;
        bridge.north_aliens[i].weight = 2.1;
    }

    for (int i = 0; i < bridge.south_aliens_number; i = i+2) {
        bridge.north_aliens[i].status = 2;
        bridge.north_aliens[i].weight = 2.1;
    }

    for (int i = 0; i < bridge.north_aliens_number; i = i+2) {
        bridge.north_aliens[i].status = 2;
        bridge.north_aliens[i].weight = 2.1;
    }

    //*y_algorithm(&bridge);*//
    //survival_algorithm(&bridge);
    sem_algorithm(&bridge);

    free(bridge.north_aliens);
    free(bridge.south_aliens);

    Lmutex_destroy(bridge.south_mutex);
    Lmutex_destroy(bridge.north_mutex);

    return 0;
}
