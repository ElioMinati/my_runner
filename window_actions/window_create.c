/*
** EPITECH PROJECT, 2021
** window_create
** File description:
** create window
*/

#include "my_runner.h"

sfRenderWindow *window_create(int x, int y, int framerate)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {x, x, 32};

    window = sfRenderWindow_create(video_mode, "My runner", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, framerate);
    return window;
}
