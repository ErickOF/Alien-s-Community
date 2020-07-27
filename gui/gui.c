#include "gui.h"


// Map to draw
int map[MAP_Y][MAP_X] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

// Matrix to draw aliens
int aliens_matrix[MAP_Y][MAP_X];

// All aliens
Alien *all_aliens;

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
    timer_update = al_create_timer(1.0 / FPS_HIGHLIGHT);

    if (!timer_update) {
        al_show_native_message_box(NULL, NULL, "Error",
                                "Failed to create timer_update",
                                NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return FALSE;
    }

    // Start update timer
    al_start_timer(timer_update);

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

    // Init keyboard detection
    al_install_keyboard();
    // Init mouse detection
    al_install_mouse();

    // Register all events
    al_register_event_source(event_queue,
                            al_get_display_event_source(display));
    al_register_event_source(event_queue,
                            al_get_timer_event_source(timer_update));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    
    // Defining colors
    alpha_alien_color = al_map_rgb(255, 0, 0);
    avenue_color = al_map_rgb(180, 130, 0);
    beta_alien_color = al_map_rgb(0, 0, 255);
    background_color = al_map_rgb(0, 255, 0);
    bridge_color = al_map_rgb(30, 30, 255);
    intruder_color = al_map_rgb(0, 0, 0);
    normal_alien_color = al_map_rgb(255, 255, 255);
    road_color = al_map_rgb(150, 50, 0);
    street_color = al_map_rgb(255, 50, 50);

    // Fill alien matrix
    for (int i = 0; i < MAP_Y; i ++) {
        for (int j = 0; j < MAP_X; j++) {
            aliens_matrix[i][j] = 0;
        }
    }

    // Create aliens
    aliens = (Alien*) malloc(sizeof(Alien) * MAX_ALIENS_NUMBER);

    for (int i = 0; i < MAX_ALIENS_NUMBER; i++){
        (aliens + i)->status = 6;
        (aliens + i)->ticks = 0;
    }

    return TRUE;
}

/**
 * Destroy all components
 */
void destroy_all() {
    free (aliens);

    al_destroy_display(display);
    al_destroy_event_queue(event_queue);

    al_destroy_timer(timer_update);

    al_uninstall_keyboard();
    al_uninstall_mouse();

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
            // Check component type
            switch (map[i][j]) {
            case 1:
                color = road_color;
                break;
            case 2:
                color = street_color;
                break;
            case 3:
                color = avenue_color;
                break;
            case 4:
                color = bridge_color;
                break;
            default:
                color = background_color;
                break;
            };

            // Draw rectangle
            al_draw_filled_rectangle(j * TILE_SIZE, i * TILE_SIZE, (j + 1) * TILE_SIZE, (i + 1) * TILE_SIZE, color);
            al_draw_rectangle(j * TILE_SIZE, i * TILE_SIZE, (j + 1) * TILE_SIZE, (i + 1) * TILE_SIZE, al_map_rgb(0, 0, 0), 1);
        }
    }
}

/**
 * This function draw the aliens matrix.
 */
void draw_alien_matrix() {
    ALLEGRO_COLOR color;

    for (int i = 0; i < MAP_Y; i ++) {
        for (int j = 0; j < MAP_X; j++) {
            // Draw normal alien
            if (aliens_matrix[i][j] == 1) {
                al_draw_filled_circle(j * TILE_SIZE + TILE_SIZE / 2, i * TILE_SIZE + TILE_SIZE / 2, TILE_SIZE / 2, normal_alien_color);
            } else if (aliens_matrix[i][j] == 2) {
                al_draw_filled_circle(j * TILE_SIZE + TILE_SIZE / 2, i * TILE_SIZE + TILE_SIZE / 2, TILE_SIZE / 2, alpha_alien_color);
            } else if (aliens_matrix[i][j] == 3) {
                al_draw_filled_circle(j * TILE_SIZE + TILE_SIZE / 2, i * TILE_SIZE + TILE_SIZE / 2, TILE_SIZE / 2, beta_alien_color);
            }
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
    // Draw alien matrix
    draw_alien_matrix();

    // Community houses
	al_draw_bitmap(img_community_a_house, 3 * TILE_SIZE, ((int) WINDOW_HEIGHT/2 - 77), 0);
	al_draw_bitmap(img_community_b_house, WINDOW_WIDTH - 3 * TILE_SIZE - 170, ((int) WINDOW_HEIGHT/2 - 77), 0);
}

/**
 * This function moves an alien.
 * 
 * Inputs:
 *      - Alien* alien: alien to move.
 */
void move_alien(Alien* alien) {
    int previous_position[2];
    previous_position[0] = alien->position[0];
    previous_position[1] = alien->position[1];

    // Check direction
    short direction = alien->direction;

    switch (direction) {
        // Up
        case 0:
            // If there's an avenue up
            if (map[alien->position[0] - 1][alien->position[1]] == 3) {
            } // If the road continues up
            else if (map[alien->position[0] - 1][alien->position[1]] == 1) {
                if (aliens_matrix[alien->position[0] - 1][alien->position[1]] == 0) {
                    alien->position[0]--;
                }
            } // If the road continues to the right
            else if (map[alien->position[0]][alien->position[1] + 1] == 1) {
                if (aliens_matrix[alien->position[0]][alien->position[1] + 1] == 0) {
                    alien->position[1]++;
                    alien->direction = 3;
                }
            } // If the road continues to the left
            else if (map[alien->position[0]][alien->position[1] - 1] == 1) {
                if (aliens_matrix[alien->position[0]][alien->position[1] - 1] == 0) {
                    alien->position[1]--;
                    alien->direction = 2;
                }
            } // If the road continues down
            else if (map[alien->position[0] + 1][alien->position[1]] == 1) {
                if (aliens_matrix[alien->position[0] + 1][alien->position[1]] == 0) {
                    alien->position[0]++;
                    alien->direction = 1;
                }
            }
            break;
        // Down
        case 1:
            // If there's an avenue up
            if (map[alien->position[0] + 1][alien->position[1]] == 3) {
            } // If the road continues down
            else if (map[alien->position[0] + 1][alien->position[1]] == 1) {
                if (aliens_matrix[alien->position[0] + 1][alien->position[1]] == 0) {
                    alien->position[0]++;
                }
            } // If the road continues to the right
            else if (map[alien->position[0]][alien->position[1] + 1] == 1) {
                if (aliens_matrix[alien->position[0]][alien->position[1] + 1] == 0) {
                    alien->position[1]++;
                    alien->direction = 3;
                }
            } // If the road continues to the left
            else if (map[alien->position[0]][alien->position[1] - 1] == 1) {
                if (aliens_matrix[alien->position[0]][alien->position[1] - 1] == 0) {
                    alien->position[1]--;
                    alien->direction = 2;
                }
            } // If the road continues up
            else if (map[alien->position[0] - 1][alien->position[1]] == 1) {
                if (aliens_matrix[alien->position[0] - 1][alien->position[1]] == 0) {
                    alien->position[0]--;
                    alien->direction = 0;
                }
            }
            break;
        // Left
        case 2:
            // If the road continues to the left
            if (map[alien->position[0]][alien->position[1] - 1] == 1) {
                if (aliens_matrix[alien->position[0]][alien->position[1] - 1] == 0) {
                    alien->position[1]--;
                }
            } // If the road continues up
            else if (map[alien->position[0] - 1][alien->position[1]] == 1) {
                if (aliens_matrix[alien->position[0] - 1][alien->position[1]] == 0) {
                    alien->position[0]--;
                    alien->direction = 0;
                }
            } // If the road continues down
            else if (map[alien->position[0] + 1][alien->position[1]] == 1) {
                if (aliens_matrix[alien->position[0] + 1][alien->position[1]] == 0) {
                    alien->position[0]++;
                    alien->direction = 1;
                }
            } // If the road continues to the right
            else if (map[alien->position[0]][alien->position[1] + 1] == 1) {
                if (aliens_matrix[alien->position[0]][alien->position[1] + 1] == 0) {
                    alien->position[1]++;
                    alien->direction = 3;
                }
            }
            break;
        // Right
        case 3:
            // If the road continues to the right
            if (map[alien->position[0]][alien->position[1] + 1] == 1) {
                if (aliens_matrix[alien->position[0]][alien->position[1] + 1] == 0) {
                alien->position[1]++;
                }
            } // If the road continues up
            else if (map[alien->position[0] - 1][alien->position[1]] == 1) {
                if (aliens_matrix[alien->position[0] - 1][alien->position[1]] == 0) {
                    alien->position[0]--;
                    alien->direction = 0;
                }
            } // If the road continues down
            else if (map[alien->position[0] + 1][alien->position[1]] == 1) {
                if (aliens_matrix[alien->position[0] + 1][alien->position[1]] == 0) {
                    alien->position[0]++;
                    alien->direction = 1;
                }
            } // If the road continues to the left
            else if (map[alien->position[0]][alien->position[1] - 1] == 1) {
                if (aliens_matrix[alien->position[0]][alien->position[1] - 1] == 0) {
                    alien->position[1]--;
                    alien->direction = 2;
                }
            }
            break;
        default:
            break;
    }

    // Moving the alien in the matrix
    aliens_matrix[previous_position[0]][previous_position[1]] = 0;
    aliens_matrix[alien->position[0]][alien->position[1]] = alien->type + 1;
}

/**
 * This function destroy an alien in the clicked cell.
 * 
 * Inputs:
 *      - short row - pressed row.
 *      - short col - pressed column.
 */
void destroy_alien(short row, short col) {
    // Check if an alien exists in that position
    if (aliens_matrix[row][col] != 0) {
        // Search alien
        for (int i = 0; i < MAX_ALIENS_NUMBER; i++) {
            if (aliens[i].position[0] == row && aliens[i].position[1] == col) {
                // Kill alien
                aliens_matrix[row][col] = 0;
                aliens[i].status = 5;
                break;
            }
        }
    }
}

/**
 * This function displays main window
 */
void show_mainwindow(BridgeData* west_bridge, BridgeData* central_bridge,
                     BridgeData* east_bridge, AlienSpawner* alien_spawner) {
    // Running program
    int runnning = TRUE;
    // Indicates when graphics are drawn
    int redraw = FALSE;
    // Indicates when map is clicked
    int clicked = FALSE;
    
    while (runnning) {
        Alien* new_alien;

        // Get event from queue
        ALLEGRO_EVENT event;
        al_wait_for_event(event_queue, &event);

        switch (event.type) {
            // When app is close, exit
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                runnning = FALSE;
                play = FALSE;

                break;
            // When timer launches an event
            case ALLEGRO_EVENT_TIMER:
                redraw = TRUE;

                for (int i = 0; i < MAX_ALIENS_NUMBER; i++) {
                    if ((aliens + i)->status == 1) {
                        (aliens + i)->ticks += 1;
                    }
                }

                break;
            // When key was pressed
            case ALLEGRO_EVENT_KEY_DOWN:
                if (alien_spawner->mode == 0) {
                    switch(event.keyboard.keycode) {
                        // Exit
                        case ALLEGRO_KEY_ESCAPE:
                            runnning = FALSE;
                            play = FALSE;
                            break;
                        // Alpha Alien from A Community
                        case ALLEGRO_KEY_A:
                            // printf("Creating new alpha alien in A Commmunity\n");

                            // Create alien
                            new_alien = create_alpha_alien(*alien_spawner->alien_data, 0);
                            aliens_matrix[new_alien->position[0]][new_alien->position[1]] = 2;

                            /************ Running the Alien ************/
                            new_alien->status = 1;
                            /************ Running the Alien ************/

                            // Insert Alien
                            for (int i = 0; i < MAX_ALIENS_NUMBER; i++) {
                                if ((aliens + i)->status == 6) {
                                    *(aliens + i) = *new_alien;
                                    break;
                                }
                            }
                            
                            break;
                        // Beta Alien from A Community
                        case ALLEGRO_KEY_B:
                            // printf("Creating new beta alien in A Commmunity\n");

                            // Create alien
                            new_alien = create_beta_alien(*alien_spawner->alien_data, 0);
                            aliens_matrix[new_alien->position[0]][new_alien->position[1]] = 3;

                            /************ Running the Alien ************/
                            new_alien->status = 1;
                            /************ Running the Alien ************/

                            // Insert Alien
                            for (int i = 0; i < MAX_ALIENS_NUMBER; i++) {
                                if ((aliens + i)->status == 6) {
                                    *(aliens + i) = *new_alien;
                                    break;
                                }
                            }
                            
                            break;
                        // Normal Alien from A Community
                        case ALLEGRO_KEY_N:
                            // printf("Creating new normal alien in A Commmunity\n");

                            // Create alien
                            new_alien = create_normal_alien(*alien_spawner->alien_data, 0);
                            aliens_matrix[new_alien->position[0]][new_alien->position[1]] = 1;

                            /************ Running the Alien ************/
                            new_alien->status = 1;
                            /************ Running the Alien ************/

                            // Insert Alien
                            for (int i = 0; i < MAX_ALIENS_NUMBER; i++) {
                                if ((aliens + i)->status == 6) {
                                    *(aliens + i) = *new_alien;
                                    break;
                                }
                            }

                            break;
                        // Alpha Alien from B Community
                        case ALLEGRO_KEY_2:
                            // printf("Creating new alpha alien in B Commmunity\n");

                            // Create alien
                            new_alien = create_alpha_alien(*alien_spawner->alien_data, 1);
                            aliens_matrix[new_alien->position[0]][new_alien->position[1]] = 2;

                            /************ Running the Alien ************/
                            new_alien->status = 1;
                            /************ Running the Alien ************/

                            // Insert Alien
                            for (int i = 0; i < MAX_ALIENS_NUMBER; i++) {
                                if ((aliens + i)->status == 6) {
                                    *(aliens + i) = *new_alien;
                                    break;
                                }
                            }

                            break;
                        // Beta Alien from B Community
                        case ALLEGRO_KEY_3:
                            // printf("Creating new beta alien in B Commmunity\n");

                            // Create alien
                            new_alien = create_beta_alien(*alien_spawner->alien_data, 1);
                            aliens_matrix[new_alien->position[0]][new_alien->position[1]] = 3;

                            /************ Running the Alien ************/
                            new_alien->status = 1;
                            /************ Running the Alien ************/

                            // Insert Alien
                            for (int i = 0; i < MAX_ALIENS_NUMBER; i++) {
                                if ((aliens + i)->status == 6) {
                                    *(aliens + i) = *new_alien;
                                    break;
                                }
                            }
                            
                            break;
                        // Normal Alien from B Community
                        case ALLEGRO_KEY_1:
                            // printf("Creating new normal alien in B Commmunity\n");
                            // Create alien
                            new_alien = create_normal_alien(*alien_spawner->alien_data, 1);
                            aliens_matrix[new_alien->position[0]][new_alien->position[1]] = 1;

                            /************ Running the Alien ************/
                            new_alien->status = 1;
                            /************ Running the Alien ************/

                            // Insert Alien
                            for (int i = 0; i < MAX_ALIENS_NUMBER; i++) {
                                if ((aliens + i)->status == 6) {
                                    *(aliens + i) = *new_alien;
                                    break;
                                }
                            }

                            break;
                        // When enter was pressed, go to waiting window
                        case ALLEGRO_KEY_ENTER:
                            break;
                        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
                            printf("Mouse pressed\n");
                            break;
                        default:
                            break;
                    }
                    break;
                }
            default:
                break;
        }

        // Detect mouse click
        ALLEGRO_MOUSE_STATE state;
        al_get_mouse_state(&state);

        // If left button was pressed
        if ((state.buttons & 1) && !clicked) {
            clicked = TRUE;

            destroy_alien(state.y / TILE_SIZE, state.x / TILE_SIZE);
        } // If left button was released
        else if (!state.buttons & 1) {
            clicked = FALSE;
        }

        // Update main window
        if (redraw) {
            // Check if an alien has to move
            for (int i = 0; i < MAX_ALIENS_NUMBER; i++) {
                if ((aliens + i)->status == 1) {
                    if ((aliens + i)->ticks >= (aliens + i)->speed) {
                        // printf("Moving alien %d, ticks %d\n", i, (aliens + i)->ticks);
                        move_alien(aliens + i);
                        (aliens + i)->ticks = 0;
                    }
                }
            }

            update_mainwindow();
            redraw = FALSE;
        }

        // Update display
        al_flip_display();
    }

    for (int i = 0; i < MAX_ALIENS_NUMBER; i++) {
        if (aliens[i].status != 6) {
            printf("Alien #%d\n", i);
            printf("Type: %s\n", aliens[i].type == 0 ? "Normal" : aliens[i].type == 1 ? "Alpha": aliens[i].type == 2 ? "Beta" : "Intruder");
            printf("Priority: %d\n", aliens[i].priority);
            printf("Execution time: %f\n", aliens[i].execution_time);
            printf("Status: %d\n\n", aliens[i].status);
        }
    }
}
