/*
** EPITECH PROJECT, 2021
** object_display.c
** File description:
** display background parallax
*/

#include <stdlib.h>
#include "my_runner.h"

void display_backgrounds(sfRenderWindow *window,
struct game_object *backgrounds)
{
    sfSprite *sprite;

    sprite = backgrounds[0].sprite;
    sfRenderWindow_drawSprite(window, backgrounds[0].sprite, NULL);
    sprite = backgrounds[1].sprite;
    sfRenderWindow_drawSprite(window, backgrounds[1].sprite, NULL);
    sprite = backgrounds[3].sprite;
    sfRenderWindow_drawSprite(window, backgrounds[3].sprite, NULL);
    sprite = backgrounds[4].sprite;
    sfRenderWindow_drawSprite(window, backgrounds[4].sprite, NULL);
    sprite = backgrounds[2].sprite;
    sfRenderWindow_drawSprite(window, backgrounds[2].sprite, NULL);
    sprite = backgrounds[5].sprite;
    sfRenderWindow_drawSprite(window, backgrounds[5].sprite, NULL);
    sprite = backgrounds[6].sprite;
    sfRenderWindow_drawSprite(window, backgrounds[6].sprite, NULL);
}

void display_obstacles(sfRenderWindow *window,
struct game_object *maps, int nb_of_sprites)
{
    sfSprite *sprite;

    for (int i = maps[0].size; i < nb_of_sprites; ++i)
        sfRenderWindow_drawSprite(window, maps[i].sprite, NULL);
}
