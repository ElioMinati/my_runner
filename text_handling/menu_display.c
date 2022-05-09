/*
** EPITECH PROJECT, 2022
** menu_display
** File description:
** functions that display menus
*/

#include "my_runner.h"

void display_porsche_sprite(sfTexture *texture, sfSprite *sprite)
{
    sfVector2f pos_sprite = {600, -100};
    sfVector2f resize = {0.7, 0.7};

    sfSprite_setPosition(sprite, pos_sprite);
    sfSprite_setScale(sprite, resize);
    sfSprite_setTexture(sprite, texture, sfFalse);
}

static void display_win(sfRenderWindow *window)
{
    sfFont *font = sfFont_createFromFile("fonts/PixelsplitterBold-ErDW.ttf");
    sfText *text = sfText_create();
    sfVector2f pos_text = {370, 200};

    sfText_setString(text, "YOU MADE IT !");
    sfText_setFont(text, font);
    sfText_setColor(text, sfBlack);
    sfText_setCharacterSize(text, 170);
    sfText_setFillColor(text, sfWhite);
    sfText_setPosition(text, pos_text);
    sfText_setOutlineThickness(text, 10);
    sfRenderWindow_drawText(window, text, NULL);
}

void display_win_menu(sfRenderWindow *window, struct game_object *object)
{
    sfFont *font = sfFont_createFromFile("fonts/PixelsplitterBold-ErDW.ttf");
    sfText *text = sfText_create();
    sfVector2f pos_text = {640, 700};

    sfText_setString(text, "Press ENTER to restart");
    sfText_setFont(text, font);
    sfText_setColor(text, sfBlack);
    sfText_setCharacterSize(text, 50);
    sfText_setFillColor(text, sfWhite);
    sfText_setPosition(text, pos_text);
    sfText_setOutlineThickness(text, 10);
    sfRenderWindow_drawText(window, text, NULL);
    display_win(window);
    sfRenderWindow_drawSprite(window, object[7].sprite, NULL);
}