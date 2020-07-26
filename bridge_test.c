#include "shared/bridge_algorithms.h"


int main() {
    Bridge bridge;
    bridge.y = 2;
    bridge.direction=0;
    bridge.south_aliens_number=5;
    bridge.north_aliens_number=6;
    y_algorithm(bridge);

    return 0;
}
