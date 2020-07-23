#ifndef PROJECT2_SHARED_TOOL_H
#define PROJECT2_SHARED_TOOL_H

#include <stdio.h>
#include <stdlib.h>
#include "structs.h"

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


#endif /* PROJECT2_SHARED_TOOLS_H */
