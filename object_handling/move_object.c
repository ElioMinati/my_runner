/*
** EPITECH PROJECT, 2021
** move_obj
** File description:
** move object according to speed
*/

#include "my_runner.h"

struct game_object move_background(struct game_object obj)
{
    sfVector2f pos = sfSprite_getPosition(obj.sprite);

    pos.x += obj.speed;
    if (pos.x <= obj.too_far)
        pos.x = obj.re_init;
    sfSprite_setPosition(obj.sprite, pos);
    return obj;
}

struct game_object move_car(struct game_object obj)
{
    sfVector2f pos = sfSprite_getPosition(obj.sprite);

    if (obj.can_jump == 0) {
        obj.jump.y *= obj.jump_mult;
        if (obj.jump.y <= 1)
            obj.jump_mult = 1.3;
        pos.y += (obj.jump_mult > 1.2 ? obj.jump.y : -obj.jump.y);
        if (pos.y >= 800) {
            obj.jump_mult = 0.7;
            obj.can_jump = 1;
        }
    } else {
        obj.jump.y = 200;
        pos.y = 830;
    }
    sfSprite_setTextureRect(obj.sprite, obj.car_rect);
    sfSprite_setPosition(obj.sprite, pos);
    return obj;
}

void object_resize(struct game_object obj, float x, float y)
{
    sfVector2f scale = {x, y};

    sfSprite_setScale(obj.sprite, scale);
}

struct game_object *move_obstacles(struct game_object *obj, int nb_of_sprites)
{
    sfVector2f pos;

    for (int i = 8; i < nb_of_sprites; ++i) {
        pos = sfSprite_getPosition(obj[i].sprite);
        pos.x += obj[i].speed;
        sfSprite_setTextureRect(obj[i].sprite, obj[i].car_rect);
        sfSprite_setPosition(obj[i].sprite, pos);
    }
    return obj;
}

void move_objects(struct game_object *objects, int nb_of_sprites)
{
    objects[0] = move_background(objects[0]);
    objects[1] = move_background(objects[1]);
    objects[2] = move_background(objects[2]);
    objects[3] = move_background(objects[3]);
    objects[4] = move_background(objects[4]);
    objects[5] = move_background(objects[5]);
    objects[6] = move_background(objects[6]);
    objects[7] = move_car(objects[7]);
    objects = move_obstacles(objects, nb_of_sprites);
    objects[0].end_pos.x -= 30;
}
