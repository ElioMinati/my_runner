/*
** EPITECH PROJECT, 2021
** map_create
** File description:
** create objects to be put on map
*/

#include <stdlib.h>
#include "my_runner.h"
#include "my.h"

static int count_nb_lines(char *buffer)
{
    int count = 0;

    for (int i = 0; buffer[i] != '\0'; ++i) {
        if (buffer[i] == '\n')
            ++count;
    }
    return count;
}

static int count_nb_chars_on_line(char *buffer)
{
    int count = 0;
    int nb_chars_on_line = 0;

    for (int i = 0; buffer[i] != '\0'; ++i) {
        if (count == 0)
            ++nb_chars_on_line;
        if (buffer[i] == '\n')
            ++count;
    }
    return nb_chars_on_line;
}

static char **put_buffer_into_line_array(char *buffer)
{
    int f_index = 0;
    int count = count_nb_lines(buffer);
    int count_chars_on_line = count_nb_chars_on_line(buffer);
    int index = 0;
    char **array;

    array = malloc((count + 1) * sizeof(char *));
    for (int i = 0; i <= count; ++i)
        array[i] = malloc((count_chars_on_line + 1) * sizeof(char));
    for (int i = 0; buffer[i] != '\0'; ++i) {
        if (buffer[i] == '\n') {
            array[f_index][index] = '\0';
            index = 0;
            ++f_index;
            ++i;
        }
        array[f_index][index] = buffer[i];
        ++index;
    }
    return array;
}

int verify_char_of_file(struct game_object *map, char **map_array,
int sprite_nb, obstacle_create obs)
{
    sfIntRect rect = create_240sx_rect();
    sfVector2f vector = {0, 0};
    int pos[2] = {0, 870};

    sprite_nb = obs_create(obs, map, sprite_nb, map_array);
    sprite_nb = more_obs_create(obs, map, sprite_nb, map_array);
    if (map_array[obs.i][obs.j] == 'e') {
        vector.x = obs.j * 100 + (obs.order * 7600);
        map[0].end_pos = vector;
    }
    return sprite_nb;
}

struct game_object *create_map(struct game_object *map, char *buffer)
{
    obstacle_create obs;
    int sprite_nb = map[7].size;
    int order = 0;
    char **map_array = malloc((count_nb_lines(buffer) + 1) * sizeof(char *));

    alloc_map_array(map_array, count_nb_lines(buffer),
    count_nb_chars_on_line(buffer));
    map_array = put_buffer_into_line_array(buffer);
    for (obs.i = 0; obs.i < count_nb_lines(buffer); ++obs.i) {
        for (obs.j = 0; obs.j < count_nb_chars_on_line(buffer); ++obs.j) {
            obs.order = order;
            sprite_nb = verify_char_of_file(map, map_array, sprite_nb, obs);
        }
        if ((obs.i % 4) == 0 && obs.i != 0)
            order++;
    }
    for (int i = 0; i < count_nb_lines(buffer); ++i)
        free(map_array[i]);
    return map;
}
