#include <stdio.h>

#include "gui/gui.h"
#include "shared/tools.h"


int main() {
    // Read files
    char* content;
    content = read_file("settings/alien.txt");
    printf("Alien file:\n%s\n\n", content);
    AlienData* alien = parse_alien(content);
    printf("Speed: %f, MET: %f, Weight: %f\n\n", alien->speed, alien->execution_time, alien->weight);
    free(content);
    free(alien);
    
    content = read_file("settings/central_bridge.txt");
    printf("Central Bridge file:\n%s.\n\n", content);
    BridgeData* central_bridge = parse_bridge(content);
    printf("length: %d, max_weight: %f, max_nord_aliens:%d, max_south_aliens: %d",
            central_bridge->length, central_bridge->max_weight,
            central_bridge->max_nord_aliens, central_bridge->max_south_aliens);
    free(content);
    free(central_bridge);

    content = read_file("settings/east_bridge.txt");
    printf("East Bridge file:\n%s.\n\n", content);
    BridgeData* east_bridge = parse_bridge(content);
    printf("length: %d, max_weight: %f, max_nord_aliens:%d, max_south_aliens: %d",
            east_bridge->length, east_bridge->max_weight,
            east_bridge->max_nord_aliens, east_bridge->max_south_aliens);
    free(content);
    free(east_bridge);

    content = read_file("settings/west_bridge.txt");
    printf("West Bridge file:\n%s.\n\n", content);
    BridgeData* west_bridge = parse_bridge(content);
    printf("length: %d, max_weight: %f, max_nord_aliens:%d, max_south_aliens: %d",
            west_bridge->length, west_bridge->max_weight,
            west_bridge->max_nord_aliens, west_bridge->max_south_aliens);
    free(content);
    free(west_bridge);

    content = read_file("settings/spawner.txt");
    printf("Spawner file:\n%s.\n\n", content);
    AlienSpawner* alien_spawner = parse_spawner(content);
    printf("mean: %f, alpha: %f, beta: %f, normal: %f",
            alien_spawner->mean, alien_spawner->alpha,
            alien_spawner->beta, alien_spawner->normal);
    free(content);
    free(alien_spawner);

    // Init all allegro components
    if (!init_all()) {
        destroy_all();
        return -1;
    }

    // Load images
    load_imgs();

    // Call mainwindow
    show_mainwindow();

    // Delete all components
    destroy_all();
}
