#include "tools.h"
#include "constants.h"
#include <stdio.h>


char* read_file(char* file_name) {
    // Open file in read mode
    FILE *file = fopen(file_name, "r");

    // Check if file was opened
    if (file == NULL) {
        printf("Error while opening the file %s.\n", file_name);
        exit(0);
    }

    // File content
    char* content = calloc(sizeof(char), MAX_FILE_SIZE);
    // Read char
    char value;
    // Current position
    int i = 0;

    // Read char from file
    while ((value = getc(file)) != EOF) {
        // Check if value is less then max
        if (i == MAX_FILE_SIZE - 1) {
            break;
        }

        // Assign char
        content[i] = value;
        // Next value
        i++;
    }

    // Close file
    fclose(file);

    return content;
}

AlienData* parse_alien(char* data) {
    AlienData alien;
    int i = 0;

    // Go through the data
    while (data[i] != '\0') {
        // Var where to store values
        char* param = calloc(75, sizeof(char));
        char* value = calloc(75, sizeof(char));

        int j = 0;

        // Search : delimiter
        while (data[i] != ':') {
            param[j] = data[i];
            i++;
            j++;
        }

        j = 0;
        // Search : delimiter
        while (data[i] != '\n') {
            value[j] = data[i];
            i++;
        }

        printf("%s : %s\n", param, value);

        // Free memory
        free(param);
        free(value);
    }
    
    return &alien;
}
