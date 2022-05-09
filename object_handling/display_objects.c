/*
** EPITECH PROJECT, 2021
** display_objects.c
** File description:
** display objects
*/

#include "my_runner.h"

void display_cars(sfRenderWindow *window, struct game_object *cars)
{
    sfSprite *sprite;

    sprite = cars[7].sprite;
    sfRenderWindow_drawSprite(window, sprite, NULL);
}

void display_objects(sfRenderWindow *window, struct game_object *objects,
int nb_of_sprites)
{
    sfRenderWindow_clear(window, sfBlack);
    for (int i = 0; i < nb_of_sprites; ++i) {
        sfRenderWindow_drawSprite(window, objects[i].sprite, NULL);
    }
}
