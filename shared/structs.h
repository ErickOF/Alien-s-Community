#ifndef PROJECT2_SHARED_STRUCTS_H
#define PROJECT2_SHARED_STRUCTS_H

/**
 * This struct represents a generic alien.
 * 
 * int position[2] - starting position.
 * float speed - alien speed.
 *     - Normal:    x.
 *     - A-Alien:   0.2x.
 *     - B-Alien:   0.5x to 2x.
 *     - I-Alien:   2x.
 * short priority - priority to cross the bridge.
 *     - Normal:    2
 *     - A-Alien:   2
 *     - B-Alien:   1
 *     - I-Alien:   0
 * float execution_time - since creation to destruction.
 * short type - alien type.
 *     - Normal:    0
 *     - A-Alien:   1
 *     - B-Alien:   2
 *     - I-Alien:   3
 * short status
 *     - creation:  0
 *     - running:   1
 *     - completed: 2
 *     - waiting:   3
 *     - locked:    4 // Ask
 *     - dead:      5
 * float weight - alien weight.
 * 
 */
struct alien {
    // (x, y)
    int position[2];
    float speed;
    short priority;
    float execution_time;
    short type;
    short status;
    float weight;
} typedef Alien;

/**
 * Struct used to represent an Alien Data.
 * 
 * float speed - alien speed.
 * float execution_time - since creation to destruction.
 * float weight - alien weight.
 * 
 */
struct alien_data {
    float speed;
    float execution_time;
    float weight;
} typedef AlienData;

/**
 * Struct used to represent a Bridge.
 * 
 * int position[2] - bridge position.
 * float current_weight - current weight on the bridge.
 * float max_weight - max weight supported by the bridge.
 * int lenght
 * int south_aliens - current number of alien in the south.
 * int nord_aliens - current number of aliens in the nord.
 * int max_south_aliens - max number of alien in the south.
 * int max_nord_aliens - max number of aliens in the nord
 * void* algorithm - calendarization algorithm.
 * void* calendar - calendar type.
 * int direction - current bridge direction.
 * 
 */
struct bridge {
    // (x, y)
    short position;
    float current_weight;
    float max_weight;
    int length;
    int south_aliens;
    int nord_aliens;
    int max_south_aliens;
    int max_nord_aliens;
    void* algorithm;
    void* calendar;
    int direction;
} typedef Bridge;

/**
 * Struct to represent a Bridge Data.
 * 
 * float max_weight - max weight supported by the bridge.
 * int max_south_aliens - max number of alien in the south.
 * int max_nord_aliens - max number of aliens in the nord.
 * char* algorithm - name of the calendarization algorithm.
 * char* calendar - calendar type name.
 * 
 */
struct bridge_data {
    int length;
    float max_weight;
    int max_south_aliens;
    int max_nord_aliens;
    char* algorithm;
    char* calendar;
} typedef BridgeData;

/**
 * Struct to represen a Alien Spawner.
 *
 * float mean - distribution mean.
 * float alpha - percentage of alpha aliens.
 * float beta - percentage of beta aliens.
 * float normal - percentage of normal aliens.
 * 
 */
struct alien_spawner {
    float mean;
    float alpha;
    float beta;
    float normal;
} typedef AlienSpawner;

#endif /* PROJECT2_SHARED_STRUCTS_H */
