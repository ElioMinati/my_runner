/*
** EPITECH PROJECT, 2021
** text_display
** File description:
** display text on screen
*/

#include "my_runner.h"

static void display_car_and_name(sfRenderWindow *window)
{
    sfTexture *texture = sfTexture_createFromFile("images/porsche.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfFont *font = sfFont_createFromFile("fonts/PixelsplitterBold-ErDW.ttf");
    sfText *text = sfText_create();
    sfVector2f pos_text = {400, 350};

    display_porsche_sprite(texture, sprite);
    sfText_setString(text, "Cyber Racer 2069");
    sfText_setFont(text, font);
    sfText_setColor(text, sfBlack);
    sfText_setCharacterSize(text, 100);
    sfText_setFillColor(text, sfWhite);
    sfText_setOutlineThickness(text, 10);
    sfText_setPosition(text, pos_text);
    sfRenderWindow_drawText(window, text, NULL);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfFont_destroy(font);
    sfText_destroy(text);
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
}

void display_beginning_menu(sfRenderWindow *window)
{
    sfFont *font = sfFont_createFromFile("fonts/PixelsplitterBold-ErDW.ttf");
    sfText *text = sfText_create();
    sfVector2f pos_text = {640, 700};

    sfText_setString(text, "Press ENTER to start");
    sfText_setFont(text, font);
    sfText_setColor(text, sfBlack);
    sfText_setCharacterSize(text, 50);
    sfText_setFillColor(text, sfWhite);
    sfText_setPosition(text, pos_text);
    sfText_setOutlineThickness(text, 10);
    sfRenderWindow_drawText(window, text, NULL);
    display_car_and_name(window);
    sfText_destroy(text);
    sfFont_destroy(font);
}

static void display_wasted(sfRenderWindow *window)
{
    sfFont *font = sfFont_createFromFile("fonts/PixelsplitterBold-ErDW.ttf");
    sfText *text = sfText_create();
    sfVector2f pos_text = {370, 200};

    sfText_setString(text, "WASTED");
    sfText_setFont(text, font);
    sfText_setColor(text, sfBlack);
    sfText_setCharacterSize(text, 300);
    sfText_setFillColor(text, sfWhite);
    sfText_setPosition(text, pos_text);
    sfText_setOutlineThickness(text, 10);
    sfRenderWindow_drawText(window, text, NULL);
    sfText_destroy(text);
    sfFont_destroy(font);
}

void display_dead_bike(sfRenderWindow *window)
{
    sfTexture *texture = sfTexture_createFromFile("sprites/bike.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f pos_sprite = {50, 830};
    sfVector2f resize = {3, 3};
    sfIntRect rect;

    rect.left = 745;
    rect.top = 136;
    rect.width = 122;
    rect.height = 65;
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setTextureRect(sprite, rect);
    sfSprite_setPosition(sprite, pos_sprite);
    sfSprite_setScale(sprite, resize);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
}

void display_end_menu(sfRenderWindow *window)
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
    display_wasted(window);
    display_dead_bike(window);
    sfText_destroy(text);
    sfFont_destroy(font);
}
