/*
** EPITECH PROJECT, 2021
** create_backgrounds
** File description:
** create all backgrounds
*/

#include "my_runner.h"
#include <stdlib.h>

static struct game_object *create_far_buildings(struct game_object *backgrounds)
{
    int pos[2] = {0, 0};
    int pos1[2] = {1920, 0};

    backgrounds[0] = create_bg_object("background_parallax/far-buildings.png",
    pos, first_bg);
    backgrounds[0].too_far = -1920;
    backgrounds[0].re_init = 0;
    backgrounds[0].speed = -4;
    object_resize(backgrounds[0], 7.74, 7.74);
    backgrounds[1] = create_bg_object("background_parallax/far-buildings.png",
    pos1, first_bg);
    backgrounds[1].too_far = 0;
    backgrounds[1].re_init = 1920;
    backgrounds[1].speed = -4;
    object_resize(backgrounds[1], 7.74, 7.74);
    return backgrounds;
}

static struct game_object *create_two_other_back_buildings(
struct game_object *backgrounds)
{
    int pos[2] = {1152, 0};
    int pos1[2] = {2304, 0};

    backgrounds[3] = create_bg_object("background_parallax/back-buildings.png",
    pos, second_bg);
    backgrounds[3].too_far = 0;
    backgrounds[3].re_init = 1152;
    backgrounds[3].speed = -7;
    object_resize(backgrounds[3], 4.5, 4.5);
    backgrounds[4] = create_bg_object("background_parallax/back-buildings.png",
    pos1, second_bg);
    backgrounds[4].too_far = 1152;
    backgrounds[4].re_init = 2304;
    backgrounds[4].speed = -7;
    object_resize(backgrounds[4], 4.5, 4.5);
    return backgrounds;
}

static struct game_object *create_back_buildings(struct game_object
*backgrounds)
{
    int pos[2] = {0, 0};

    backgrounds = create_two_other_back_buildings(backgrounds);
    backgrounds[2] = create_bg_object("background_parallax/back-buildings.png",
    pos, second_bg);
    backgrounds[2].too_far = -1152;
    backgrounds[2].re_init = 0;
    backgrounds[2].speed = -7;
    object_resize(backgrounds[2], 4.5, 4.5);
    return backgrounds;
}

static struct game_object *create_foreground(struct game_object *backgrounds)
{
    int pos[2] = {0, 0};
    int pos1[2] = {1918, 0};

    backgrounds[5] = create_bg_object("background_parallax/foreground.png",
    pos, second_bg);
    backgrounds[5].too_far = -1918;
    backgrounds[5].re_init = 0;
    backgrounds[5].speed = -15;
    object_resize(backgrounds[5], 5.45, 5.45);
    backgrounds[6] = create_bg_object("background_parallax/foreground.png",
    pos1, second_bg);
    backgrounds[6].too_far = 0;
    backgrounds[6].re_init = 1918;
    backgrounds[6].speed = -15;
    object_resize(backgrounds[6], 5.45, 5.45);
    return backgrounds;
}

struct game_object *create_backgrounds(struct game_object *backgrounds)
{
    backgrounds = create_far_buildings(backgrounds);
    backgrounds = create_back_buildings(backgrounds);
    backgrounds = create_foreground(backgrounds);
    return backgrounds;
}
