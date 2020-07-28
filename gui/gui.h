#ifndef PROJECT2_GUI_GUI_H
#define PROJECT2_GUI_GUI_H


#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>

#include "gui_constants.h"
#include "../shared/structs.h"
#include "../shared/tools.h"
#include "../lib/lpthreads.h"


// Game Screen
ALLEGRO_DISPLAY* display;
// Event Queue detected
ALLEGRO_EVENT_QUEUE* event_queue;

// Timers
ALLEGRO_TIMER* timer_update;

// Images
ALLEGRO_BITMAP* img_community_a_house;
ALLEGRO_BITMAP* img_community_b_house;

// Colors
ALLEGRO_COLOR alpha_alien_color;
ALLEGRO_COLOR avenue_color;
ALLEGRO_COLOR beta_alien_color;
ALLEGRO_COLOR background_color;
ALLEGRO_COLOR bridge_color;
ALLEGRO_COLOR intruder_color;
ALLEGRO_COLOR normal_alien_color;
ALLEGRO_COLOR road_color;
ALLEGRO_COLOR street_color;


// Indicates if the game is running
int play;
// All created aliens
Alien* aliens;

// Mutex to move aliens
lpthread_mutex_t* mutex_move_aliens;

// Running program
static short running = TRUE;

/**
 * This function loads all imagens.
 */
void load_imgs();

/**
 * This function init all components.
 */
int init_all();

/**
 * Destroy all components.
 */
void destroy_all();

/**
 * This function updates game map.
 */
void draw_map();

/**
 * This function draw the aliens matrix.
 */
void draw_alien_matrix();

/**
 * This function updates the main window
 */
void update_mainwindow();

/**
 * This function moves an alien.
 * 
 * Inputs:
 *      - Alien* alien: alien to move.
 */
void move_alien(Alien* alien);

/**
 * This function inserts a new aliens in the aliens array.
 * 
 * Inputs:
 *      - Alien* new_alien: alien to insert.
 */
void insert_alien(Alien* new_alien);

/**
 * This function destroy an alien in the clicked cell.
 * 
 * Inputs:
 *      - short row - pressed row.
 *      - short col - pressed column.
 */
void destroy_alien(short row, short col);

/**
 * This function displays main window
 * 
 * Inputs:
 *      - Bridge* west_bridge: west bridge data.
 *      - Bridge* central_bridge: central bridge data.
 *      - Bridge* east_bridge: easte bridge data.
 *      - AlienSpawner* alien_spawner: alien spawner data.
 */
void show_mainwindow(BridgeData* west_bridge, BridgeData* central_bridge,
                     BridgeData* east_bridge, AlienSpawner* alien_spawner);

/**
 * This function run an alien in a thread.
 * 
 * Inputs:
 *      - Alien* alien: alien to run.
 */
int run_alien(void* args);


#endif /* PROJECT2_GUI_GUI_H */
