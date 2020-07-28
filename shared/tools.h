#ifndef PROJECT2_SHARED_TOOL_H
#define PROJECT2_SHARED_TOOL_H

#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "structs.h"
#include "constants.h"


/**
 * This function reads the content from a file.
 * 
 * Inputs:
 *      - char* file_name: path to file.
 * 
 * Returns:
 *      File content as a char pointer.
 */
char* read_file(char* file_name);

/*
 * This function parses the content file to alien data.
 * 
 * Inputs:
 *      - char* data: read data from file.
 * 
 * Returns:
 *      An AlienData structure representing the file content.
 */
AlienData* parse_alien(char* data);

/*
 * This function parses the content file to bridge data.
 * 
 * Inputs:
 *      - char* data: read data from file.
 * 
 * Returns:
 *      An Bridge Data structure representing the file content.
 */
BridgeData* parse_bridge(char* data);

/*
 * This function parses the content file to bridge data.
 * 
 * Inputs:
 *      - char* data: read data from file.
 * 
 * Returns:
 *      An Alien Spawner structure representing the file content.
 */
AlienSpawner* parse_spawner(char* data);

/**
 * This function creates an alpha alien.
 * 
 * Inputs:
 *      - AlienData data: alien data to create new alpha alien.
 *      - short communiy: 0 to A community or 1 to B community.
 * 
 * Returns:
 *      An Alien structure representing the alpha alien.
 */
Alien* create_alpha_alien(AlienData data, short community);

/**
 * This function creates a beta alien.
 * 
 * Inputs:
 *      - AlienData data: alien data to create new beta alien.
 *      - short communiy: 0 to A community or 1 to B community.
 * 
 * Returns:
 *      An Alien structure representing the beta alien.
 */
Alien* create_beta_alien(AlienData data, short community);

/**
 * This function creates a normal alien.
 * 
 * Inputs:
 *      - AlienData data: alien data to create new normal alien.
 *      - short communiy: 0 to A community or 1 to B community.
 * 
 * Returns:
 *      An Alien structure representing the normal alien.
 */
Alien* create_normal_alien(AlienData data, short community);

/**
 * This function creates a intruder alien.
 * 
 * Inputs:
 *      - AlienData data: alien data to create new intruder alien.
 * 
 * Returns:
 *      An Alien structure representing the intruder alien.
 */
Alien* create_intruder(AlienData data);

/**
 * This function creates a bridge.
 * 
 * Inputs:
 *      - Bridge data: bridge data used to create the bridge.
 * 
 * Returns:
 *      A Bridge structure representing the new bridge.
 */
Bridge* create_bridge(BridgeData* bridge_data);

/**
 * This function computes a random integer number between a given range.
 * 
 * Inputs:
 *      - int min: min value.
 *      - int max: max value.
 * 
 * Returns:
 *      A new random integer number between min and max.
 */
int get_rand_int(int min, int max);

/**
 * This function computes a random double number using an exponential
 * distribution.
 * 
 * Inputs
 *      - double mean: mean in seconds.
 * 
 * Returns
 *      An random double number folling a exponential distribution.
 * 
 */
double get_rand_exp(double mean);


/**
 * This function creates a random alien.
 * 
 * Inputs:
 *      - AlienSpawner spawner: alien spawner with distribution data.
 *      - short communiy: 0 to A community or 1 to B community.
 * 
 * Returns:
 *      An Alien structure representing the new alien.
 */
Alien* generate_random_alien(AlienSpawner spawner, short community);


#endif /* PROJECT2_SHARED_TOOLS_H */
