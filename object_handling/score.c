/*
** EPITECH PROJECT, 2021
** score.c
** File description:
** score
*/

#include "my_runner.h"

void add_score(struct game_object *objects) {
    if (objects[0].seconds >= (0.01 * objects[0].verif_score)) {
        ++objects[0].score;
        ++objects[0].verif_score;
    }
    if (objects[0].seconds >= 1)
        objects[0].verif_score = 0;
}
