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

// Game Screen
ALLEGRO_DISPLAY* display;
// Event Queue detected
ALLEGRO_EVENT_QUEUE* event_queue;

// Timers
ALLEGRO_TIMER* timer;

// Images
ALLEGRO_BITMAP* img_community_a_house;
ALLEGRO_BITMAP* img_community_b_house;

// Colors
ALLEGRO_COLOR alpha_alien;
ALLEGRO_COLOR avenue;
ALLEGRO_COLOR beta_alien;
ALLEGRO_COLOR background;
ALLEGRO_COLOR bridge;
ALLEGRO_COLOR normal_alien;
ALLEGRO_COLOR road;

// Indicates if the game is running
int play;
// All created aliens
Alien* aliens;

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
 * This function updates the main window
 */
void update_mainwindow();

/**
 * This function displays main window
 */
void show_mainwindow();


#endif /* PROJECT2_GUI_GUI_H */
