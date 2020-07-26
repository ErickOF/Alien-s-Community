#include "tools.h"


const int MAX_FILE_SIZE = 1024;


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
    while ((content[i] = getc(file)) != EOF) {
        // Check if value is less then max
        if (i == MAX_FILE_SIZE - 1) {
            break;
        }

        // Next value
        i++;
    }

    // Close file
    fclose(file);

    return content;
}

AlienData* parse_alien(char* data) {
    AlienData* alien_data = (AlienData*) malloc(sizeof(AlienData));
    int i = 0;

    // Go through the data
    while (data[i] != '\0') {
        // Var where to store values
        char* param = (char*) calloc(75, sizeof(char));
        char* value = (char*) calloc(75, sizeof(char));

        int j = 0;

        // Search : delimiter
        while (data[i] != ':') {
            param[j] = data[i];
            i++;
            j++;
        }

        j = 0;
        i++;

        // Search \n delimiter
        while (data[i] != '\n' && data[i] != EOF) {
            value[j] = data[i];
            i++;
            j++;
        }

        i++;

        // Check if the param is speed
        if (strcmp(param, "speed\0") == 0) {
            alien_data->speed = atof(value);
        }
        // Check if the param is max_execution_time
        if (strcmp(param, "max_execution_time\0") == 0) {
            alien_data->execution_time = atof(value);
        }
        // Check if the param is weight
        if (strcmp(param, "weight\0") == 0) {
            alien_data->weight = atof(value);
        }

        // Free memory
        free(param);
        free(value);
    }

    return alien_data;
}

BridgeData* parse_bridge(char* data) {
    BridgeData* bridge_data = (BridgeData*) malloc(sizeof(BridgeData));
    int i = 0;

    // Go through the data
    while (data[i] != '\0') {
        // Var where to store values
        char* param = (char*) calloc(75, sizeof(char));
        char* value = (char*) calloc(75, sizeof(char));

        int j = 0;

        // Search : delimiter
        while (data[i] != ':') {
            param[j] = data[i];
            i++;
            j++;
        }

        j = 0;
        i++;

        // Search \n delimiter
        while (data[i] != '\n' && data[i] != EOF) {
            value[j] = data[i];
            i++;
            j++;
        }

        i++;

        // Check if the param is length
        if (strcmp(param, "length\0") == 0) {
            bridge_data->length = atoi(value);
        }
        // Check if the param is max_weight
        if (strcmp(param, "max_weight\0") == 0) {
            bridge_data->max_weight = atof(value);
        }
        // Check if the param is algorithm
        if (strcmp(param, "algorithm\0") == 0) {
            // Assign algorithm here later
            //bridge_data->algorithm = value;
        }
        // Check if the param is calendar
        if (strcmp(param, "calendar\0") == 0) {
            // Assign calendar here later
            //bridge_data->calendar = value;
        }
        // Check if the param is max_north_aliens
        if (strcmp(param, "max_north_aliens\0") == 0) {
            bridge_data->max_north_aliens = atoi(value);
        }
        // Check if the param is max_south_aliens
        if (strcmp(param, "max_south_aliens\0") == 0) {
            bridge_data->max_south_aliens = atoi(value);
        }

        // Free memory
        free(param);
        free(value);
    }

    return bridge_data;
}

AlienSpawner* parse_spawner(char* data) {
    AlienSpawner* alien_spawner = (AlienSpawner*) malloc(sizeof(AlienSpawner));
    int i = 0;

    // Go through the data
    while (data[i] != '\0') {
        // Var where to store values
        char* param = (char*) calloc(75, sizeof(char));
        char* value = (char*) calloc(75, sizeof(char));

        int j = 0;

        // Search : delimiter
        while (data[i] != ':') {
            param[j] = data[i];
            i++;
            j++;
        }

        j = 0;
        i++;

        // Search \n delimiter
        while (data[i] != '\n' && data[i] != EOF) {
            value[j] = data[i];
            i++;
            j++;
        }

        i++;

        // Check if the param is mean
        if (strcmp(param, "mean\0") == 0) {
            alien_spawner->mean = atof(value);
        }
        // Check if the param is alpha
        if (strcmp(param, "alpha\0") == 0) {
            alien_spawner->alpha = atof(value);
        }
        // Check if the param is beta
        if (strcmp(param, "beta\0") == 0) {
            alien_spawner->beta = atof(value);
        }
        // Check if the param is normal
        if (strcmp(param, "normal\0") == 0) {
            alien_spawner->normal = atof(value);
        }

        // Free memory
        free(param);
        free(value);
    }

    return alien_spawner;
}

Alien* create_alpha_alien(AlienData data, short community) {
    // Creating Alien structure
    Alien* alpha_alien = malloc(sizeof(Alien));

    // Setting information from AlienData
    alpha_alien->execution_time = data.execution_time;
    alpha_alien->speed = data.speed;
    alpha_alien->weight = data.weight;

    // Setting alpha alien data
    if (community == 0) {
        alpha_alien->position[0] = 13;
        alpha_alien->position[1] = 7;
        alpha_alien->direction = 0;
    } else {
        alpha_alien->position[0] = 16;
        alpha_alien->position[1] = 46;
        alpha_alien->direction = 1;
    }

    alpha_alien->priority = 2;
    alpha_alien->status = 0;
    alpha_alien->type = 1;
}

Alien* create_beta_alien(AlienData data, short community) {}

Alien* create_normal_alien(AlienData data, short community) {}
