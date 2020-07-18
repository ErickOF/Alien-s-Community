#ifndef PROJECT2_GUI_GUI_H
#define PROJECT2_GUI_GUI_H


#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>

#include "gui_constants.h"


// Game Screen
ALLEGRO_DISPLAY *display;
// Event Queue detected
ALLEGRO_EVENT_QUEUE *event_queue;

// Timers
ALLEGRO_TIMER *timer;


// Indicates if the game is running
int play;

// Images
ALLEGRO_BITMAP *img_community_a_house;
ALLEGRO_BITMAP *img_community_b_house;


/**
 * This function loads all imagens
 */
void load_imgs();

/**
 * This function init all components
 */
int init_all();

/**
 * Destroy all components
 */
void destroy_all();

/**
 * This function updates the main window
 */
void update_mainwindow();

/**
 * This function displays main window
 */
void show_mainwindow();


#endif /* PROJECT2_GUI_GUI_H */
