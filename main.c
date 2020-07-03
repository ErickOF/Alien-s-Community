#include "gui/gui.h"


int main() {
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
