#include "gui.h"


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
}

/**
 * This function updates the main window
 */
void update_mainwindow() {
    // Clear window
	al_clear_to_color(al_map_rgb(0, 0, 0));

    // Community houses
	al_draw_bitmap(img_community_a_house, 100, ((int) WINDOW_HEIGHT/2 - 75), 0);
	al_draw_bitmap(img_community_b_house, WINDOW_WIDTH - 250, ((int) WINDOW_HEIGHT/2 - 75), 0);
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
