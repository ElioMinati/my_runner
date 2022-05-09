/*
** EPITECH PROJECT, 2021
** collision.c
** File description:
** fucntions that handle collision between player and obstacles
*/

#include <SFML/Audio/Music.h>
#include <SFML/Audio/Sound.h>
#include "my_runner.h"

void verify_collision(struct game_object *obj, sfVector2f obstacle_pos,
sfVector2f pos)
{
    if (pos.x >= (obstacle_pos.x - 480) && pos.x <= obstacle_pos.x &&
    pos.y >= (obstacle_pos.y - 137)) {
        obj[0].die_effect = sfMusic_createFromFile("sounds/bruh.ogg");
        sfMusic_setVolume(obj[0].die_effect, 100);
        sfMusic_play(obj[0].die_effect);
        obj[0].is_cleaned_die = 1;
        obj[0].end = 1;
    } else if ((pos.x - 366) >= (obstacle_pos.x - 480) && (pos.x - 366) <=
    (obstacle_pos.x - 50) && pos.y >= (obstacle_pos.y - 137)) {
        obj[0].die_effect = sfMusic_createFromFile("sounds/bruh.ogg");
        sfMusic_setVolume(obj[0].die_effect, 100);
        sfMusic_play(obj[0].die_effect);
        obj[0].is_cleaned_die = 1;
        obj[0].end = 1;
    }
}

void is_collision(struct game_object *obj, int nb_of_sprites)
{
    sfVector2f pos = sfSprite_getPosition(obj[7].sprite);
    sfVector2f obstacle_pos;

    pos.x += 366;
    for (int i = obj[0].size; i < nb_of_sprites; ++i) {
        obstacle_pos = sfSprite_getPosition(obj[i].sprite);
        verify_collision(obj, obstacle_pos, pos);
    }
    if (obj[0].end_pos.x <= 0)
        obj[0].end = 2;
}
