#ifndef PROJECT2_SHARED_STRUCTS_H

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
struct Alien {
    // (x, y)
    int position[2];
    float speed;
    short priority;
    float execution_time;
    short type;
    short status;
    float weight;
};


struct Bridge {
    // (x, y)
    short position;
    float current_weight;
    float max_weight;
    int lenght;
    int south_aliens;
    int nord_aliens;
    void* algorithm;
    int direction;
};

#endif /* PROJECT2_SHARED_STRUCTS_H */
