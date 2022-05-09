/*
** EPITECH PROJECT, 2021
** menu_handling
** File description:
** functions that display either end menu, beginning menu, or play game
*/

#include <SFML/Audio/Music.h>
#include <SFML/Audio/Sound.h>
#include "my_runner.h"

void display_menu(sfRenderWindow *window, struct game_object *objects)
{
    sfRenderWindow_clear(window, sfBlack);
    for (int i = 0; i < 7; ++i) {
        sfRenderWindow_drawSprite(window, objects[i].sprite, NULL);
    }
    display_beginning_menu(window);
    objects[0] = move_background(objects[0]);
    objects[1] = move_background(objects[1]);
    objects[2] = move_background(objects[2]);
    objects[3] = move_background(objects[3]);
    objects[4] = move_background(objects[4]);
    objects[5] = move_background(objects[5]);
    objects[6] = move_background(objects[6]);
}

void display_end(sfRenderWindow *window, struct game_object *objects,
int nb_of_sprites)
{
    sfRenderWindow_clear(window, sfBlack);
    for (int i = 0; i < 7; ++i) {
        sfRenderWindow_drawSprite(window, objects[i].sprite, NULL);
    }
    if (objects[0].end == 1)
        display_end_menu(window);
    else {
        display_win_menu(window, objects);
    }
}

void display_game(sfRenderWindow *window, struct game_object *objects,
int nb_of_sprites)
{
    objects[0].seconds = sfTime_asSeconds(sfClock_getElapsedTime(
    objects[0].clock));
    is_collision(objects, nb_of_sprites);
    objects[7] = move_bike_sprite_rect(objects[7], objects[0].seconds);
    add_score(objects);
    if (objects[0].seconds >= 1) {
        sfClock_restart(objects[0].clock);
        objects[7].rect_count = 1;
        for (int i = objects[0].size; i < nb_of_sprites; ++i)
            objects[i].rect_count = 1;
    }
    move_obstacle_sprite_rect(objects, objects[0].seconds, nb_of_sprites);
    display_objects(window, objects, nb_of_sprites);
    display_score(objects, window);
    move_objects(objects, nb_of_sprites);
}
