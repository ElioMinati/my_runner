/*
** EPITECH PROJECT, 2021
** help.c
** File description:
** display help for runner
*/

#include "my.h"

void display_help(void)
{
    my_putstr("\nRunner created thanks to the CSFML Library\n\n");
    my_putstr("USAGE:\n");
    my_putstr("    ./my_runner [CONFIG_FILE]\n");
    my_putstr("    press spacebar to jump\n");
    my_putstr("    avoid the cars driving very furiously at you\n\n");
}
