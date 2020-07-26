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
    bridge.max_weight = 5;

    bridge.south_aliens = (Alien*) malloc(sizeof(Alien) * bridge.max_south_aliens);
    bridge.north_aliens = (Alien*) malloc(sizeof(Alien) * bridge.max_north_aliens);
    int max_number = bridge.south_aliens_number+bridge.north_aliens_number;

    for (int i = 0; i < bridge.north_aliens_number - 1; i++) {
        Alien alien;
        alien.status = 3;
        alien.weight = 2.1;
        bridge.north_aliens[i] = alien;
    }

    for (int i = 0; i < bridge.south_aliens_number; i++) {
        Alien alien;
        alien.status = 3;
        alien.weight = 2.1;
        bridge.south_aliens[i] = alien;
    }

    for (int i = 0; i < bridge.south_aliens_number; i = i+2) {
        Alien alien;
        alien.status = 2;
        alien.weight = 2.1;
        bridge.south_aliens[i] = alien;
    }

    for (int i = 0; i < bridge.north_aliens_number; i = i+2) {
        Alien alien;
        alien.status = 2;
        alien.weight = 2.1;
        bridge.north_aliens[i] = alien;
    }

    //*y_algorithm(&bridge);*//
    //*survival_algorithm(&bridge);*//

    free(bridge.north_aliens);
    free(bridge.south_aliens);

    return 0;
}
