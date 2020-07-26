#ifndef PROJECT2_SHARED_TOOL_H
#define PROJECT2_SHARED_TOOL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

#endif /* PROJECT2_SHARED_TOOLS_H */
