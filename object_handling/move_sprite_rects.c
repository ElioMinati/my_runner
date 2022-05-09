/*
** EPITECH PROJECT, 2021
** move_sprite_rects
** File description:
** move rects that determine which sprite is displayed
*/

#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include "my_runner.h"

void move_obstacle_sprite_rect(struct game_object *objects,
float seconds, int nb_of_sprites)
{
    for (int i = objects[7].size; i < nb_of_sprites; ++i) {
        objects[i].car_rect = rect_clock(objects[i].car_rect,
        seconds, objects[i]);
        if (seconds > 0.05 * objects[i].rect_count)
            objects[i].rect_count++;
    }
}

struct game_object move_bike_sprite_rect(struct game_object objects,
float seconds)
{
    if (objects.is_jump == 7) {
        objects.car_rect.top = 2;
        objects.is_jump = 0;
        objects.car_rect.left = 0;
    }
    if (objects.is_jump >= 1) {
        if (objects.is_jump == 1)
            objects.car_rect.left = 0;
        objects.car_rect.top = 68;
        objects.is_jump += 1;
    }
    objects.car_rect = bike_clock(objects.car_rect, seconds, objects);
    if (seconds > 0.07 * objects.rect_count)
        objects.rect_count++;
    return objects;
}
