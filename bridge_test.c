#include "shared/bridge_algorithms.h"
#include <stdlib.h>

int main() {
    Bridge bridge;
    bridge.y = 2;
    bridge.direction = 0;
    bridge.south_aliens_number = 5;
    bridge.north_aliens_number = 6;
    bridge.max_south_aliens = 10;
    bridge.max_north_aliens = 10;
    bridge.south_aliens = (Alien*) malloc(sizeof(Alien) * bridge.max_south_aliens);
    bridge.north_aliens = (Alien*) malloc(sizeof(Alien) * bridge.max_north_aliens);

    for (int i = 0; i < bridge.max_north_aliens - 1; i++) {
        Alien alien;
        alien.status = 6;
        bridge.north_aliens[i] = alien;
        printf("Alien %d: status %d\n", i, bridge.north_aliens[i].status);
    }

    for (int i = 0; i < bridge.max_south_aliens; i++) {
        Alien alien;
        alien.status = 6;
        bridge.south_aliens[i] = alien;
        printf("Alien %d: status %d\n", i, bridge.south_aliens[i].status);
    }

    y_algorithm(&bridge);

    free(bridge.north_aliens);
    free(bridge.south_aliens);

    return 0;
}
