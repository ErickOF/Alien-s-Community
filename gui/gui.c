#include "gui.h"


// Map to draw
int map[MAP_Y][MAP_X] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 5, 0, 0, 0, 0, 0, 5, 2, 0, 0, 0, 0, 0, 0, 5, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 5, 0, 0, 0, 0, 0, 5, 2, 0, 0, 0, 0, 0, 0, 5, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 5, 0, 0, 0, 0, 0, 5, 2, 0, 0, 0, 0, 0, 0, 5, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 5, 0, 0, 0, 0, 0, 5, 2, 0, 0, 0, 0, 0, 0, 5, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 5, 0, 0, 0, 0, 0, 5, 2, 0, 0, 0, 0, 0, 0, 5, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 5, 0, 0, 0, 0, 0, 5, 2, 0, 0, 0, 0, 0, 0, 5, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 5, 0, 0, 0, 0, 0, 5, 2, 0, 0, 0, 0, 0, 0, 5, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 5, 0, 0, 0, 0, 0, 5, 2, 0, 0, 0, 0, 0, 0, 5, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 5, 0, 0, 0, 0, 0, 5, 2, 0, 0, 0, 0, 0, 0, 5, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 5, 0, 0, 0, 0, 0, 5, 2, 0, 0, 0, 0, 0, 0, 5, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 5, 0, 0, 0, 0, 0, 5, 2, 0, 0, 0, 0, 0, 0, 5, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 5, 0, 0, 0, 0, 0, 5, 2, 0, 0, 0, 0, 0, 0, 5, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 5, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 5, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
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
            case 5:
                color = street_color;
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
                al_draw_circle(j * TILE_SIZE + TILE_SIZE / 2, i * TILE_SIZE + TILE_SIZE / 2, TILE_SIZE / 2, al_map_rgb(0, 0, 0), 2);
            } else if (aliens_matrix[i][j] == 2) {
                al_draw_filled_circle(j * TILE_SIZE + TILE_SIZE / 2, i * TILE_SIZE + TILE_SIZE / 2, TILE_SIZE / 2, alpha_alien_color);
                al_draw_circle(j * TILE_SIZE + TILE_SIZE / 2, i * TILE_SIZE + TILE_SIZE / 2, TILE_SIZE / 2, al_map_rgb(0, 0, 0), 2);
            } else if (aliens_matrix[i][j] == 3) {
                al_draw_filled_circle(j * TILE_SIZE + TILE_SIZE / 2, i * TILE_SIZE + TILE_SIZE / 2, TILE_SIZE / 2, beta_alien_color);
                al_draw_circle(j * TILE_SIZE + TILE_SIZE / 2, i * TILE_SIZE + TILE_SIZE / 2, TILE_SIZE / 2, al_map_rgb(0, 0, 0), 2);
            } else if (aliens_matrix[i][j] == 4) {
                al_draw_filled_circle(j * TILE_SIZE + TILE_SIZE / 2, i * TILE_SIZE + TILE_SIZE / 2, TILE_SIZE / 2, intruder_color);
                al_draw_circle(j * TILE_SIZE + TILE_SIZE / 2, i * TILE_SIZE + TILE_SIZE / 2, TILE_SIZE / 2, al_map_rgb(0, 0, 0), 2);
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

    if ((alien->position[0] == 13 && alien->position[1] == 5 && alien->community == 1) ||
        (alien->position[0] == 16 && alien->position[1] == 48 && alien->community == 0)) {
        alien->status = 2;
        aliens_matrix[previous_position[0]][previous_position[1]] = 0;
        return;
    }

    switch (direction) {
        // Up
        case 0:
            if (map[alien->position[0] - 1][alien->position[1]] == 4) {
                // alien->status = 3;
            } else if (alien->position[0] == 6 && alien->position[1] == 27 && alien->community == 1) {
                if (aliens_matrix[alien->position[0] - 1][alien->position[1]] == 0) {
                    alien->position[0]--;
                }
            } // If there's a street up
            else if (map[alien->position[0] - 1][alien->position[1]] == 2) {
                if (aliens_matrix[alien->position[0] - 1][alien->position[1]] == 0) {
                    // If there's background to the left or right
                    if (map[alien->position[0]][alien->position[1] - 1] == 0 ||
                        map[alien->position[0]][alien->position[1] + 1] == 0) {
                        alien->position[0]--;
                    }
                }
            } // If there's an avenue up
            else if (map[alien->position[0] - 1][alien->position[1]] == 3) {
                if (aliens_matrix[alien->position[0] - 1][alien->position[1]] == 0) {
                    alien->position[0]--;

                    // If alien is on the road
                    if (map[alien->position[0]][alien->position[1]] == 1) {
                        // Random direction
                        alien->direction = get_rand_int(2, 4);
                    } else {
                        if (map[alien->position[0]][alien->position[1] + 1] == 0) {
                            alien->direction = 2;
                        } else if (map[alien->position[0]][alien->position[1] - 1] == 0) {
                            alien->direction = 3;
                        }
                    }
                }
            } // If there's an avenue to the left
            else if (map[alien->position[0]][alien->position[1] - 1] == 3) {
                // If there's an avenue to the right
                if (map[alien->position[0]][alien->position[1] + 1] == 3) {
                    // Go to the right
                    if (get_rand_int(0, 2) == 0) {
                        if (aliens_matrix[alien->position[0]][alien->position[1] + 1] == 0) {
                            alien->position[1]++;
                            alien->direction = 3;
                        }
                    } // Go to the left
                    else {
                        if (aliens_matrix[alien->position[0]][alien->position[1] - 1] == 0) {
                            alien->position[1]--;
                            alien->direction = 2;
                        }
                    }
                } // Continues left
                else {
                    if (aliens_matrix[alien->position[0]][alien->position[1] - 1] == 0) {
                        alien->position[1]--;
                        alien->direction = 2;
                    }
                }
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
            if (map[alien->position[0] + 1][alien->position[1]] == 4) {
                // alien->status = 3;
            } else if (alien->position[0] == 23 && alien->position[1] == 27 && alien->community == 0) {
                if (aliens_matrix[alien->position[0] - 1][alien->position[1]] == 0) {
                    alien->position[0]++;
                }
            } // If there's a street down
            else if (map[alien->position[0] + 1][alien->position[1]] == 5) {
                if (aliens_matrix[alien->position[0] + 1][alien->position[1]] == 0) {
                    // If there's background to the left or right
                    if (map[alien->position[0]][alien->position[1] - 2] == 0 ||
                        map[alien->position[0]][alien->position[1] + 2] == 0) {
                        alien->position[0]++;
                    }
                }
            } // If there's an avenue down
            else if (map[alien->position[0] + 1][alien->position[1]] == 3) {
                if (aliens_matrix[alien->position[0] + 1][alien->position[1]] == 0) {
                    alien->position[0]++;

                    if (map[alien->position[0]][alien->position[1] + 2] == 0) {
                        alien->direction = 2;
                    } else if (map[alien->position[0]][alien->position[1] - 2] == 0) {
                        alien->direction = 3;
                    } else {
                        if (map[alien->position[0]][alien->position[1]] == 1) {
                            // Random direction
                            alien->direction = get_rand_int(2, 4) == 2 ? 1 : 3;
                        } else {
                            if (map[alien->position[0]][alien->position[1] + 1] == 0) {
                                alien->direction = 2;
                            } else if (map[alien->position[0]][alien->position[1] - 1] == 0) {
                                alien->direction = 3;
                            }
                        }
                    }
                }
            } // If there's an avenue to the left
            else if (map[alien->position[0]][alien->position[1] - 1] == 3) {
                // If there's an avenue to the right
                if (map[alien->position[0]][alien->position[1] + 1] == 3) {
                    // Go to the right
                    if (get_rand_int(0, 2) == 0) {
                        if (aliens_matrix[alien->position[0]][alien->position[1] + 1] == 0) {
                            alien->position[1]++;
                            alien->direction = 3;
                        }
                    } // Go to the left
                    else {
                        if (aliens_matrix[alien->position[0]][alien->position[1] - 1] == 0) {
                            alien->position[1]--;
                            alien->direction = 2;
                        }
                    }
                } // Continues left
                else {
                    if (aliens_matrix[alien->position[0]][alien->position[1] - 1] == 0) {
                        alien->position[1]--;
                        alien->direction = 2;
                    }
                }
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
            if (alien->position[0] == 6 && alien->position[1] == 27 && alien->community == 1) {
                if (aliens_matrix[alien->position[0] - 1][alien->position[1]] == 0) {
                    alien->position[0]--;
                    direction = 0;
                }
            } else if (alien->position[0] == 23 && alien->position[1] == 27 && alien->community == 0) {
                if (aliens_matrix[alien->position[0] - 1][alien->position[1]] == 0) {
                    alien->position[0]++;
                    direction = 1;
                }
            } // If there's a street up
            else if(map[alien->position[0] - 1][alien->position[1]] == 2 && alien->community == 1) {
                // If there's background to the left
                if (map[alien->position[0]][alien->position[1] - 1] == 0) {
                    if (aliens_matrix[alien->position[0] - 1][alien->position[0]] == 0) {
                        alien->position[0]--;
                        alien->direction = 0;
                    }
                } // Road continues to the left
                else {
                    // Go up
                    if (get_rand_int(0, 2) == 0) {
                        if (aliens_matrix[alien->position[0] - 1][alien->position[1]] == 0) {
                            alien->position[0]--;
                            alien->direction = 0;
                        }
                    } // Go to the left
                    else {
                        if (aliens_matrix[alien->position[0]][alien->position[1] - 1] == 0) {
                            alien->position[1]--;
                        }
                    }
                }
            } // If there's a street down
            else if(map[alien->position[0] + 1][alien->position[1]] == 5 && alien->community == 0) {
                // If there's background to the left
                if (map[alien->position[0]][alien->position[1] - 2] == 0) {
                    if (aliens_matrix[alien->position[0] + 1][alien->position[0]] == 0) {
                        alien->position[0]++;
                        alien->direction = 1;
                    }
                } // Road continues to the left
                else {
                    // Go down
                    if (get_rand_int(0, 2) == 0) {
                        if (aliens_matrix[alien->position[0] + 1][alien->position[1]] == 0) {
                            alien->position[0]++;
                            alien->direction = 0;
                        }
                    } // Go to the left
                    else {
                        if (aliens_matrix[alien->position[0]][alien->position[1] - 1] == 0) {
                            alien->position[1]--;
                        }
                    }
                }
            } // If there's an avenue to the left
            else if (map[alien->position[0]][alien->position[1] - 1] == 3) {
                if (aliens_matrix[alien->position[0]][alien->position[1] - 1] == 0) {
                    alien->position[1]--;
                }
            } else if (map[alien->position[0]][alien->position[1] - 1] == 5 && alien->community == 1) {
                if (aliens_matrix[alien->position[0]][alien->position[1] - 1] == 0) {
                    alien->position[1]--;
                }
            } // If the road continues to the left
            else if (map[alien->position[0]][alien->position[1] - 1] == 1) {
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
            if (alien->position[0] == 6 && alien->position[1] == 27 && alien->community == 1) {
                if (aliens_matrix[alien->position[0] - 1][alien->position[1]] == 0) {
                    alien->position[0]--;
                    direction = 0;
                }
            } else if (alien->position[0] == 23 && alien->position[1] == 27 && alien->community == 0) {
                if (aliens_matrix[alien->position[0] - 1][alien->position[1]] == 0) {
                    alien->position[0]++;
                    direction = 1;
                }
            } // If there's a street up
            else if(map[alien->position[0] - 1][alien->position[1]] == 2) {
                // If there's background to the right
                if (map[alien->position[0]][alien->position[1] + 1] == 0) {
                    if (aliens_matrix[alien->position[0] - 1][alien->position[1]] == 0) {
                        alien->position[0]--;
                        alien->direction = 0;
                    }
                } // Road continues to the right
                else {
                    // Go up
                    if (get_rand_int(0, 2) == 0) {
                        if (aliens_matrix[alien->position[0] - 1][alien->position[1]] == 0) {
                            alien->position[0]--;
                            alien->direction = 0;
                        }
                    } // Go to the right
                    else {
                        if (aliens_matrix[alien->position[0]][alien->position[1] + 1] == 0) {
                            alien->position[1]++;
                        }
                    }
                }
            } // If there's a street down
            else if(map[alien->position[0] + 1][alien->position[1]] == 5) {
                // If there's background to the right
                if (map[alien->position[0]][alien->position[1] + 2] == 0) {
                    if (aliens_matrix[alien->position[0] + 1][alien->position[1]] == 0) {
                        alien->position[0]++;
                        alien->direction = 1;
                    }
                } // Road continues to the right
                else {
                    // Go down
                    if (get_rand_int(0, 2) == 0) {
                        if (aliens_matrix[alien->position[0] + 1][alien->position[1]] == 0) {
                            alien->position[0]++;
                            alien->direction = 1;
                        }
                    } // Go to the right
                    else {
                        if (aliens_matrix[alien->position[0]][alien->position[1] + 1] == 0) {
                            alien->position[1]++;
                        }
                    }
                }
            } // If there's an avenue to the right
            else if (map[alien->position[0]][alien->position[1] + 1] == 3) {
                if (aliens_matrix[alien->position[0]][alien->position[1] + 1] == 0) {
                    alien->position[1]++;
                }
            } else if (map[alien->position[0]][alien->position[1] + 1] == 5 && alien->community == 1) {
                if (aliens_matrix[alien->position[0]][alien->position[1] + 1] == 0) {
                    alien->position[1]++;
                }
            } // If the road continues to the right
            else if (map[alien->position[0]][alien->position[1] + 1] == 1) {
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
 * This function run an alien in a thread.
 * 
 * Inputs:
 *      - Alien* alien: alien to run.
 */
int run_alien(void* args) {
    Alien* alien = (Alien*) args;

    while (running) {
        // Get event from queue
        ALLEGRO_EVENT event;
        al_wait_for_event(event_queue, &event);

        switch (event.type) {
            // When timer launches an event
            case ALLEGRO_EVENT_TIMER:
                alien->ticks++;

                if (alien->ticks >= alien->speed) {
                    Lmutex_trylock(mutex_move_aliens);
                    move_alien(alien);
                    Lmutex_unlock(mutex_move_aliens);

                    alien->ticks = 0;
                }
            break;
        }
    }

    return 0;
}

/**
 * This function inserts a new aliens in the aliens array.
 * 
 * Inputs:
 *      - Alien* new_alien: alien to insert.
 */
void insert_alien(Alien* new_alien) {
    /************ Running the Alien ************/
    new_alien->status = 1;
    /************ Running the Alien ************/
    aliens_matrix[new_alien->position[0]][new_alien->position[1]] = new_alien->type + 1;

    // Search for a empty space
    for (int i = 0; i < MAX_ALIENS_NUMBER; i++) {
        if ((aliens + i)->status == 6) {
            *(aliens + i) = *new_alien;
            Lthread_create(NULL, NULL, &run_alien, (void*) new_alien);
            break;
        }
    }
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
void show_mainwindow(Bridge* west_bridge, Bridge* central_bridge,
                     Bridge* east_bridge, AlienSpawner* alien_spawner) {
    // Init mutex
    Lmutex_init(&mutex_move_aliens, NULL);

    // Indicates when graphics are drawn
    short redraw = FALSE;
    // Indicates when map is clicked
    short clicked = FALSE;
    // Creates an intruder
    aliens[0] = *create_intruder(*alien_spawner->alien_data);
    // Ticks to create a new alien
    int ticks = 60 * get_rand_exp(alien_spawner->mean);
    printf("Time before next alien: %ds\n", ticks / 60);

    while (running) {
        Alien* new_alien;

        // Get event from queue
        ALLEGRO_EVENT event;
        al_wait_for_event(event_queue, &event);

        switch (event.type) {
            // When app is close, exit
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                running = FALSE;
                play = FALSE;

                break;
            // When timer launches an event
            case ALLEGRO_EVENT_TIMER:
                redraw = TRUE;
                ticks--;

                break;
            // When key was pressed
            case ALLEGRO_EVENT_KEY_DOWN:
                switch(event.keyboard.keycode) {
                    // Exit
                    case ALLEGRO_KEY_ESCAPE:
                        running = FALSE;
                        play = FALSE;
                        break;
                    // Alpha Alien from A Community
                    case ALLEGRO_KEY_A:
                        if (alien_spawner->mode == 0) {
                            // printf("Creating new alpha alien in A Commmunity\n");

                            // Create alien
                            new_alien = create_alpha_alien(*alien_spawner->alien_data, 0);
                            // Inserting the alien
                            insert_alien(new_alien);
                        }

                        break;
                    // Beta Alien from A Community
                    case ALLEGRO_KEY_B:
                        if (alien_spawner->mode == 0) {
                            // printf("Creating new beta alien in A Commmunity\n");

                            // Create alien
                            new_alien = create_beta_alien(*alien_spawner->alien_data, 0);
                            // Inserting the alien
                            insert_alien(new_alien);
                        }

                        break;
                    // Normal Alien from A Community
                    case ALLEGRO_KEY_N:
                        if (alien_spawner->mode == 0) {
                            // printf("Creating new normal alien in A Commmunity\n");

                            // Create alien
                            new_alien = create_normal_alien(*alien_spawner->alien_data, 0);
                            // Inserting the alien
                            insert_alien(new_alien);
                        }

                        break;
                    // Alpha Alien from B Community
                    case ALLEGRO_KEY_2:
                        if (alien_spawner->mode == 0) {
                            // printf("Creating new alpha alien in B Commmunity\n");

                            // Create alien
                            new_alien = create_alpha_alien(*alien_spawner->alien_data, 1);
                            // Inserting the alien
                            insert_alien(new_alien);
                        }

                        break;
                    // Beta Alien from B Community
                    case ALLEGRO_KEY_3:
                        if (alien_spawner->mode == 0) {
                            // printf("Creating new beta alien in B Commmunity\n");

                            // Create alien
                            new_alien = create_beta_alien(*alien_spawner->alien_data, 1);
                            // Inserting the alien
                            insert_alien(new_alien);
                        }

                        break;
                    // Normal Alien from B Community
                    case ALLEGRO_KEY_1:
                        if (alien_spawner->mode == 0) {
                            // printf("Creating new normal alien in B Commmunity\n");
                            // Create alien
                            new_alien = create_normal_alien(*alien_spawner->alien_data, 1);
                            // Inserting the alien
                            insert_alien(new_alien);
                        }

                        break;
                    // When enter was pressed, go to waiting window
                    case ALLEGRO_KEY_ENTER:
                        if (aliens[0].status == 5) {
                            // Position
                            short row, col;
                            // Indicates if the row and col are valid numbers
                            short valid = FALSE;
                            // Number of tries to get row and col
                            short tries = 0;

                            while (!valid && tries < 1000) {
                                // Get row a columns
                                row = get_rand_int(0, MAP_Y) > (MAP_Y / 2) ? 25 : 4;
                                col = get_rand_int(2, MAP_X - 2);

                                // Validate row and column
                                valid = map[row][col] == 1 && aliens_matrix[row][col] == 0;
                                // On try more
                                tries++;
                            }

                            // If the position is valid
                            if (valid) {
                                // Activating intruder
                                aliens[0].status = 1;
                                aliens[0].position[0] = row;
                                aliens[0].position[1] = col;
                                aliens[0].direction = get_rand_int(0, 4);
                                aliens[0].ticks = 0;
                                aliens_matrix[row][col] = 4;
                            }
                        }

                        break;
                    default:
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

        // If mode is automatic
        if (alien_spawner->mode == 1) {
            if (ticks <= 0) {
                // Creating a new alien
                Alien* new_alien = generate_random_alien(*alien_spawner, get_rand_int(0, 2));
                map[new_alien->position[0]][new_alien->position[1]] = new_alien->type + 1;
                // Inserting the alien
                insert_alien(new_alien);

                printf("New alien was created\n");
                // New ticks to create a new alien
                while ((ticks = 60 * get_rand_exp(alien_spawner->mean)) < 120);
                printf("Time before next alien: %ds\n\n", ticks / 60);
            }
        }

        // Update main window
        if (redraw) {
            update_mainwindow();
            redraw = FALSE;
        }

        // Update display
        al_flip_display();
    }

    printf("\n");

    for (int i = 0; i < MAX_ALIENS_NUMBER; i++) {
        if (aliens[i].status != 6) {
            printf("Alien #%d\n", i);
            printf("Type: %s\n", aliens[i].type == 0 ? "Normal" : aliens[i].type == 1 ? "Alpha": aliens[i].type == 2 ? "Beta" : "Intruder");
            printf("Priority: %d\n", aliens[i].priority);
            printf("Execution time: %f\n", aliens[i].execution_time);
            printf("Status: %d\n\n", aliens[i].status);
        }
    }

    Lmutex_destroy(mutex_move_aliens);
}
