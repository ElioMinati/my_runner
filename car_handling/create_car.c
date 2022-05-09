/*
** EPITECH PROJECT, 2021
** create_car
** File description:
** create a car object for runner
*/

#include "my_runner.h"
#include <stdlib.h>

sfIntRect create_240sx_rect(void)
{
    sfIntRect rect;

    rect.left = 0;
    rect.top = 0;
    rect.width = 480;
    rect.height = 137;
    return rect;
}

sfIntRect create_bike_rect(void)
{
    sfIntRect rect;

    rect.left = 0;
    rect.top = 2;
    rect.width = 122;
    rect.height = 65;
    return rect;
}

struct game_object *create_240sx(struct game_object *cars, sfIntRect rect)
{
    sfIntRect bike_rect = create_bike_rect();
    sfVector2f jump = {0, 200};
    int pos[2] = {50, 830};

    pos[1] += rand() % 2;
    pos[1] -= rand() % 2;
    cars[7] = create_car_object("sprites/bike.png", pos,
    bike_rect, car);
    cars[7].speed = 0;
    cars[7].size = 8;
    cars[7].is_jump = 0;
    cars[7].can_jump = 1;
    cars[7].jump = jump;
    cars[7].rect_count = 1;
    cars[7].jump_mult = 0.7;
    object_resize(cars[7], 3, 3);
    return cars;
}
