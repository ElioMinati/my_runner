/*
** EPITECH PROJECT, 2022
** obstacle_create
** File description:
** create obstacles
*/

#include <stdlib.h>
#include "my_runner.h"

void alloc_map_array(char **map_array, int nb_lines,
int nb_chars_on_line)
{
    for (int i = 0; i < (nb_lines + 1); ++i)
        map_array[i] = malloc((nb_chars_on_line - 1) *
        sizeof(char *));
}

int obs_create(obstacle_create obs, struct game_object *map,
int sprite_nb, char **map_array)
{
    sfIntRect rect = create_240sx_rect();
    int pos[2] = {0, 870};

    if (map_array[obs.i][obs.j] == '1') {
        pos[0] = obs.j * 100 + (obs.order * 7600);
        map[sprite_nb] = create_obstacle("sprites/240sx-sprite.png",
        pos, rect, obstacle);
        map[sprite_nb].speed = -30;
        ++sprite_nb;
    }
    if (map_array[obs.i][obs.j] == '2') {
        pos[0] = obs.j * 100 + (obs.order * 7600);
        map[sprite_nb] = create_obstacle("sprites/240sx-stance-sprite.png",
        pos, rect, obstacle);
        map[sprite_nb].speed = -40;
        ++sprite_nb;
    }
    return sprite_nb;
}

int more_obs_create(obstacle_create obs, struct game_object *map,
int sprite_nb, char **map_array)
{
    sfIntRect rect = create_240sx_rect();
    int pos[2] = {0, 870};

    if (map_array[obs.i][obs.j] == '3') {
        pos[0] = obs.j * 100 + (obs.order * 7600);
        map[sprite_nb] = create_obstacle("sprites/r34stock-sprite.png",
        pos, rect, obstacle);
        map[sprite_nb].speed = -50;
        ++sprite_nb;
    }
    if (map_array[obs.i][obs.j] == '4') {
        pos[0] = obs.j * 100 + (obs.order * 7600);
        map[sprite_nb] = create_obstacle("sprites/s15-stance-sprite.png",
        pos, rect, obstacle);
        map[sprite_nb].speed = -60;
        ++sprite_nb;
    }
    return sprite_nb;
}
