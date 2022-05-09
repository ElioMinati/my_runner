/*
** EPITECH PROJECT, 2021
** put_config_in_str
** File description:
** put config content in buffer
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char *config_to_str(const char *config)
{
    int file = open(config, O_RDONLY);
    int rd;
    char *buffer;

    buffer = malloc(1849 * sizeof(char));
    rd = read(file, buffer, 1848);
    buffer[1848] = '\0';
    return buffer;
}
