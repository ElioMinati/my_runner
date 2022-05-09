/*
** EPITECH PROJECT, 2021
** get_obstacles
** File description:
** get obstacle functions
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "my_runner.h"

static int verify_if_obstacle(char const c)
{
    if (c == '1' || c == '2' || c == '3' || c == '4')
        return 1;
    return 0;
}

int get_obstacle_number(char const *filename)
{
    int i;
    int nb = 0;
    char *config = config_to_str(filename);

    for (i = 0; config[i] != '\0'; i++) {
        if (verify_if_obstacle(config[i]) == 1)
            ++nb;
    }
    return nb;
}
