/*
** EPITECH PROJECT, 2021
** clock
** File description:
** 1 second clock
*/

#include "my_runner.h"
#include <unistd.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>

sfIntRect move_rect(sfIntRect rect, int offset, int max_value)
{
    int current_value = rect.left;

    rect.left = current_value + offset;
    if (rect.left == max_value) {
        rect.left = 0;
    }
    return rect;
}

sfIntRect rect_clock(sfIntRect rect, float seconds, struct game_object obj)
{
    if (seconds > 0.05 * obj.rect_count) {
        rect = move_rect(rect, 480, 1440);
        return rect;
    }
    return rect;
}

sfIntRect bike_clock(sfIntRect rect, float seconds, struct game_object obj)
{
    if (seconds > 0.07 * obj.rect_count) {
        rect = move_rect(rect, 124, 868);
        return rect;
    }
    return rect;
}
