/*
** EPITECH PROJECT, 2021
** analyse_events
** File description:
** analyse events of window
*/

#include <SFML/Audio/Music.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Window/Export.h>
#include "my_runner.h"

static void re_init_win_obj(struct game_object *objects, char *filename)
{
    sfMusic *music = objects[0].music;

    objects[0].end = 0;
    objects = create_objects(objects, filename);
    objects[0].music = music;
    objects[0].menu = 0;
}

static void re_init_obj(struct game_object *objects, char *filename)
{
    sfMusic *music = objects[0].music;

    objects[0].end = 0;
    sfMusic_destroy(objects[0].die_effect);
    objects = create_objects(objects, filename);
    objects[0].music = music;
    objects[0].menu = 0;
}

void analyse_events(sfRenderWindow *window, sfEvent event,
struct game_object *objects, char *filename)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtKeyPressed && objects[0].end >= 1) {
        if (sfKeyboard_isKeyPressed(sfKeyEnter) && objects[0].end == 1) {
            re_init_obj(objects, filename);
        } else if (sfKeyboard_isKeyPressed(sfKeyEnter))
            re_init_win_obj(objects, filename);
    }
    if (event.type == sfEvtKeyPressed && objects[0].menu == 1)
        objects[0].menu = (sfKeyboard_isKeyPressed(sfKeyEnter) ? 0 : 1);
    else if (event.type == sfEvtKeyPressed) {
        if (sfKeyboard_isKeyPressed(sfKeySpace) && objects[7].can_jump == 1) {
            objects[7].is_jump = 1;
            objects[7].can_jump = 0;
        }
    }
}
