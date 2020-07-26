#include "gui.h"


// Map to draw
int map[MAP_Y][MAP_X] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

// Matrix to draw aliens
int matrix[MAP_Y][MAP_X];

/**
 * This function loads all imagens
 */
void load_imgs() {
	img_community_a_house = al_load_bitmap(IMG_COMMUNITY_A_HOUSE_PATH);
    img_community_b_house = al_load_bitmap(IMG_COMMUNITY_B_HOUSE_PATH);
}

/**
 * This function init all components
 */
int init_all() {
    // Init allegro library
    if (!al_init()) {
        al_show_native_message_box(NULL, NULL, "Error",
                                "Failed to initialize allegro",
                                NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return FALSE;
    }

    // Create timer
    timer = al_create_timer(1.0 / FPS_HIGHLIGHT);

    if (!timer) {
        al_show_native_message_box(NULL, NULL, "Error",
                                "Failed to create timer",
                                NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return FALSE;
    }

    // Start timer
    al_start_timer(timer);

    // Create the display
    display = al_create_display(WINDOW_WIDTH, WINDOW_HEIGHT);

    if (!display) {
        al_show_native_message_box(NULL, NULL, "Error",
                                "Failed to create display",
                                NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return FALSE;
    }

    // Set window title
    al_set_window_title(display, WINDOW_TITLE);

    // Init allegro images
    if(!al_init_image_addon()) {
        al_show_native_message_box(NULL, NULL, "Error",
                                "Failed to initialize image_addon",
                                NULL, ALLEGRO_MESSAGEBOX_ERROR);
      return FALSE;
    }

    // Create event queue
    event_queue = al_create_event_queue();

    if (!event_queue) {
        al_show_native_message_box(NULL, NULL, "Error",
                                "Failed to create event queue",
                                NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return FALSE;
    }
    
    // Init Allegro Fonts
    if (!al_init_font_addon()) {
        al_show_native_message_box(NULL, NULL, "Error",
                                "Failed to init font",
                                NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return FALSE;
    }

    // Init allegro TRUE type font
    if (!al_init_ttf_addon()) {
        al_show_native_message_box(NULL, NULL, "Error",
                                "Failed to init ttf",
                                NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return FALSE;
    }

    // Init primitives figures
    if (!al_init_primitives_addon()) {
        al_show_native_message_box(NULL, NULL, "Error",
                                "Failed to init primitives",
                                NULL, ALLEGRO_MESSAGEBOX_ERROR);
      return FALSE;
    }

    // Init keyboard detected
    al_install_keyboard();

    // Register all events of display and timer
    al_register_event_source(event_queue,
                            al_get_display_event_source(display));
    al_register_event_source(event_queue,
                            al_get_timer_event_source(timer));
    al_register_event_source(event_queue,
                            al_get_keyboard_event_source());
    
    // Defining colors
    alpha_alien = al_map_rgb(255, 255, 0);
    avenue = al_map_rgb(180, 130, 0);
    beta_alien = al_map_rgb(0, 0, 0);
    background = al_map_rgb(0, 255, 0);
    bridge = al_map_rgb(30, 30, 255);
    normal_alien = al_map_rgb(0, 0, 0);
    road = al_map_rgb(150, 50, 0);

    // Fill alien matrix
    for (int i = 0; i < MAP_Y; i ++) {
        for (int j = 0; j < MAP_X; j++) {
            matrix[i][j] = 0;
        }
    }

    return TRUE;
}

/**
 * Destroy all components
 */
void destroy_all() {
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);

    al_destroy_timer(timer);

    al_uninstall_keyboard();

	al_destroy_bitmap(img_community_a_house);
    al_destroy_bitmap(img_community_b_house);
}

/**
 * This function updates game map
 */
void draw_map() {
    ALLEGRO_COLOR color;
    for (int i = 0; i < MAP_Y; i ++) {
        for (int j = 0; j < MAP_X; j++) {
            switch (map[i][j]) {
            case 1:
                color = road;
                break;
            case 2:
                color = avenue;
                break;
            case 3:
                color = bridge;
                break;
            default:
                color = background;
                break;
            };

            al_draw_filled_rectangle(j * TILE_SIZE, i * TILE_SIZE, (j + 1) * TILE_SIZE, (i + 1) * TILE_SIZE, color);
        }
    }
}

/**
 * This function updates the main window
 */
void update_mainwindow() {
    // Clear window
	al_clear_to_color(al_map_rgb(0, 0, 0));

    // Draw map
    draw_map();

    // Community houses
	al_draw_bitmap(img_community_a_house, 3 * TILE_SIZE, ((int) WINDOW_HEIGHT/2 - 77), 0);
	al_draw_bitmap(img_community_b_house, WINDOW_WIDTH - 3 * TILE_SIZE - 170, ((int) WINDOW_HEIGHT/2 - 77), 0);
}

/**
 * This function displays main window
 */
void show_mainwindow() {
    // TRUE to show menu
    int menu = TRUE;
    // Indicates when graphics are drawn
    int redraw = FALSE;
    
    while (menu) {
        // Get event from queue
        ALLEGRO_EVENT event;
        al_wait_for_event(event_queue, &event);

        switch (event.type) {
            // When app is close, exit
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                menu = FALSE;
                play = FALSE;
                break;
            // When timer launch a event
            case ALLEGRO_EVENT_TIMER:
                redraw = TRUE;
                break;
            // When key was pressed
            case ALLEGRO_EVENT_KEY_DOWN:
                switch(event.keyboard.keycode) {
                    // When key escape was pressed, exit
                    case ALLEGRO_KEY_ESCAPE:
                        menu = FALSE;
                        play = FALSE;
                        break;
                    // Alpha Alien
                    case ALLEGRO_KEY_A:
                        break;
                    // Beta Alien
                    case ALLEGRO_KEY_B:
                        break;
                    // Normal Alien
                    case ALLEGRO_KEY_N:
                        break;
                    // When enter was pressed, go to waiting window
                    case ALLEGRO_KEY_ENTER:
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }

        // Update main window
        if (redraw) {
            update_mainwindow();
            redraw = FALSE;
        }

        // Update display
        al_flip_display();
    }
}
