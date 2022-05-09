/*
** EPITECH PROJECT, 2021
** obj_creation
** File description:
** create object and puts it in obj struct
*/

#include <stdlib.h>
#include "my_runner.h"

struct game_object create_bg_object(const char *path_spritesheet,
int *pos, typeOfObj type)
{
    struct game_object object;
    sfTexture *texture = sfTexture_createFromFile(path_spritesheet, NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f coords = {pos[0], pos[1]};

    object.type = type;
    object.pos = coords;
    sfSprite_setPosition(sprite, object.pos);
    sfSprite_setTexture(sprite, texture, sfFalse);
    object.texture = texture;
    object.sprite = sprite;
    return object;
}

struct game_object create_car_object(const char *path_spritesheet,
int *pos, sfIntRect rect, typeOfObj type)
{
    struct game_object object;
    sfTexture *texture = sfTexture_createFromFile(path_spritesheet, NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f coords = {pos[0], pos[1]};

    sfSprite_setTextureRect(sprite, rect);
    object.type = type;
    object.pos = coords;
    sfSprite_setPosition(sprite, object.pos);
    sfSprite_setTexture(sprite, texture, sfFalse);
    object.texture = texture;
    object.sprite = sprite;
    object.car_rect = rect;
    return object;
}

struct game_object create_obstacle(const char *path_spritesheet,
int *pos, sfIntRect rect, typeOfObj type)
{
    struct game_object object;
    sfTexture *texture = sfTexture_createFromFile(path_spritesheet, NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f coords = {pos[0], pos[1]};
    sfVector2f resize = {-1, 1};

    sfSprite_setTextureRect(sprite, rect);
    sfSprite_setScale(sprite, resize);
    object.type = type;
    object.pos = coords;
    sfSprite_setPosition(sprite, object.pos);
    sfSprite_setTexture(sprite, texture, sfFalse);
    object.texture = texture;
    object.sprite = sprite;
    object.car_rect = rect;
    object.rect_count = 1;
    return object;
}

struct game_object *create_objects(struct game_object *objects,
char *config_file)
{
    sfIntRect sx_rect = create_240sx_rect();
    char *config_buffer = config_to_str(config_file);

    objects = create_backgrounds(objects);
    objects = create_240sx(objects, sx_rect);
    objects = create_map(objects, config_buffer);
    objects[0].clock = sfClock_create();
    objects[0].size = 8;
    objects[0].menu = 1;
    objects[0].end = 0;
    objects[7].life = 100;
    objects[0].score = 0;
    objects[0].verif_score = 1;
    objects[0].is_cleaned_die = 0;
    objects[0].is_cleaned_win = 0;
    return objects;
}
