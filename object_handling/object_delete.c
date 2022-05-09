/*
** EPITECH PROJECT, 2021
** obj_delete
** File description:
** object_deletion
*/

#include <stdlib.h>
#include <SFML/Audio/Music.h>
#include <SFML/Audio/Sound.h>
#include "my_runner.h"

void destroy_object(struct game_object obj)
{
    sfSprite_destroy(obj.sprite);
    sfTexture_destroy(obj.texture);
}

void destroy_objects(struct game_object *obj, int nb_of_sprites)
{
    for (int i = 0; i < nb_of_sprites; ++i) {
        destroy_object(obj[i]);
    }
    if (obj[0].is_cleaned_die == 1)
        sfMusic_destroy(obj[0].die_effect);
    sfMusic_destroy(obj[0].music);
    free(obj);
}
