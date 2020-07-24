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

#endif /* PROJECT2_SHARED_TOOLS_H */
