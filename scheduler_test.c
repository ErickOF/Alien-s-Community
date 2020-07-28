#include "scheduler/scheduler.c"


int main(){

    Bridge* bridge = malloc(sizeof(Bridge));

    bridge->y = 2;
    bridge->direction = 0;
    bridge->south_aliens_number = 6;
    bridge->north_aliens_number = 5;
    bridge->max_south_aliens = 10;
    bridge->max_north_aliens = 10;
    bridge->max_weight = 5;

    bridge->south_aliens = malloc(sizeof(Alien) * bridge->max_south_aliens);
    bridge->north_aliens = malloc(sizeof(Alien) * bridge->max_north_aliens);

    for (size_t i = 0; i < bridge->north_aliens_number; i++)
    {
        (bridge->north_aliens + i)->speed = (float) i;
        printf("%li. Speed = %f\n", i, (bridge->north_aliens + i)->speed);
        (bridge->north_aliens + i)->priority = bridge->north_aliens_number - i;

    }
    printf("\n");

    for (size_t i = 0; i < bridge->south_aliens_number; i++)
    {

        (bridge->south_aliens + i)->speed = (float)i;
        (bridge->south_aliens + i)->priority = bridge->south_aliens_number - i;
    }


    Alien wa = {.speed=50.0, .priority=20};


    scheduler(bridge, &wa, NORTH, LOTTERY);


    for (size_t i = 0; i < bridge->north_aliens_number; i++)
    {
        printf("%li. Speed = %f\t Priority = %i\n", i, 
                (bridge->north_aliens + i)->speed,
                (bridge->north_aliens + i)->priority);
    }
    



    free(bridge);
    free(bridge->north_aliens);
    free(bridge->south_aliens);
    
}
