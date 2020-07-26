#ifndef PROJECT2_SHARED_BRIDGE_ALGORITHMS_H
#define PROJECT2_SHARED_BRIDGE_ALGORITHMS_H

#include "structs.h"
#include <stdio.h>

/**
 * This function checks the conditions that the bridge
 * with the Algorithm Y shoul follow to let aliens cross
 *
 * Inputs:
 *      - bridge: pointer to the struct of the bridge the algorithm belongs to
 * 
 * 
 */
void y_algorithm(Bridge *bridge);

/**
 * This functions changes the data of the bridge and aliens according to the
 * aliens that cross in north-south direction
 *
 * Inputs:
 *      - bridge: pointer to the struct of the bridge the algorithm belongs to
 *      -iterations: number of aliens that should cross
 * 
 * 
 */
void cross_north_aliens(Bridge *bridge, int iterations, int max_index);

/**
 * This functions changes the data of the bridge and aliens according to the
 * aliens that cross in south-north direction
 *
 * Inputs:
 *      - bridge: pointer to the struct of the bridge the algorithm belongs to
 *      - iterations: number of aliens that should cross
 * 
 *   
 */
void cross_south_aliens(Bridge *bridge, int iterations, int max_index);

/**
 * This functions validates if an alien can cross the brodge depending on its weight
 *
 * Inputs:
 *      - bridge: pointer to the struct of the bridge the algorithm belongs to
 *      - weight: weight of the alien that should cross
 * 
 * Returns:
 *      - 0: True
 *      - 1: False
 */
short check_weight(Bridge *bridge, float weight);

/**
 * This func....
 *
 * Inputs:
 *      - y: kaksja
 * 
 * Returns:
 *      skfjskfjskfj
 */
void sem_algorithm(int y);

/**
 * This func....
 *
 * Inputs:
 *      - y: kaksja
 * 
 * Returns:
 *      skfjskfjskfj
 */
void survival_algorithm(int y);

#endif /* PROJECT2_SHARED_BRIDGE_ALGORITHMS_H */
