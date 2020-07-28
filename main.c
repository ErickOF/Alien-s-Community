#include <stdio.h>

#include "gui/gui.h"
#include "shared/tools.h"


int main() {
    char* content;

    // Read files
    content = read_file("settings/alien.txt");
    AlienData* alien = parse_alien(content);
    free(content);
    
    content = read_file("settings/central_bridge.txt");
    BridgeData* central_bridge_data = parse_bridge(content);
    Bridge* central_bridge = create_bridge(central_bridge_data);
    free(content);

    content = read_file("settings/east_bridge.txt");
    BridgeData* east_bridge_data = parse_bridge(content);
    Bridge* east_bridge = create_bridge(east_bridge_data);
    free(content);

    content = read_file("settings/west_bridge.txt");
    BridgeData* west_bridge_data = parse_bridge(content);
    Bridge* west_bridge = create_bridge(west_bridge_data);
    free(content);

    content = read_file("settings/spawner.txt");
    AlienSpawner* alien_spawner = parse_spawner(content);
    alien_spawner->alien_data = alien;
    free(content);

    // Init all allegro components
    if (!init_all()) {
        destroy_all();
        return -1;
    }

    // Load images
    load_imgs();

    // Call mainwindow
    show_mainwindow(west_bridge, central_bridge, east_bridge, alien_spawner);

    // Delete all components
    destroy_all();

    // Destroy mutes
    Lmutex_destroy(central_bridge->north_mutex);
    Lmutex_destroy(central_bridge->south_mutex);
    Lmutex_destroy(east_bridge->north_mutex);
    Lmutex_destroy(east_bridge->south_mutex);
    Lmutex_destroy(west_bridge->north_mutex);
    Lmutex_destroy(west_bridge->south_mutex);

    // Free memory
    free(alien);
    free(central_bridge_data);
    free(east_bridge_data);
    free(west_bridge_data);
    free(central_bridge);
    free(east_bridge);
    free(west_bridge);
    free(alien_spawner);
}
