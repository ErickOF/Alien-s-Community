#include <stdio.h>

#include "gui/gui.h"
#include "shared/tools.h"


int main() {
    // Read files
    char* content;
    content = read_file("settings/alien.txt");
    printf("Alien file:\n%s.\n\n", content);
    parse_alien(content);
    free(content);

    content = read_file("settings/central_bridge.txt");
    printf("Central Bridge file:\n%s.\n\n", content);
    free(content);

    content = read_file("settings/east_bridge.txt");
    printf("East Bridge file:\n%s.\n\n", content);
    free(content);

    content = read_file("settings/west_bridge.txt");
    printf("West Bridge file:\n%s.\n\n", content);
    free(content);

    content = read_file("settings/generator.txt");
    printf("Generator file:\n%s.\n\n", content);
    free(content);

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
