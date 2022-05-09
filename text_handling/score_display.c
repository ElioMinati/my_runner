/*
** EPITECH PROJECT, 2021
** score_display
** File description:
** display score as text on screen
*/

#include <stdlib.h>
#include "my_runner.h"
#include "my.h"

void display_score(struct game_object *objects, sfRenderWindow *window)
{
    char *score_str = malloc(14 * sizeof(char));
    sfFont *font = sfFont_createFromFile("fonts/PixelsplitterBold-ErDW.ttf");
    sfText *text = sfText_create();
    sfVector2f pos_text = {10, 10};

    if (objects[0].score == 0) {
        sfText_setString(text, "0");
    } else {
        score_str = int_to_str(objects[0].score);
        sfText_setString(text, score_str);
    }
    sfText_setFont(text, font);
    sfText_setColor(text, sfBlack);
    sfText_setCharacterSize(text, 50);
    sfText_setPosition(text, pos_text);
    sfRenderWindow_drawText(window, text, NULL);
}
