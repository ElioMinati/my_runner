/*
** EPITECH PROJECT, 2021
** main
** File description:
** main function
*/

#include <stdlib.h>
#include <unistd.h>
#include <SFML/Audio/Music.h>
#include <SFML/Audio/Sound.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include "my_runner.h"
#include "my.h"

void launch_game(char *filename)
{
    sfRenderWindow *window = window_create(1920, 1080, 30u);
    sfEvent event;
    int nb_of_sprites = 8 + get_obstacle_number(filename);
    struct game_object *objects = malloc(nb_of_sprites *
    sizeof(struct game_object));

    objects = create_objects(objects, filename);
    objects[0].music = play_music();
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_display(window);
        while (sfRenderWindow_pollEvent(window, &event))
            analyse_events(window, event, objects, filename);
        if (objects[0].menu == 1)
            display_menu(window, objects);
        else if (objects[0].end == 1 || objects[0].end == 2)
            display_end(window, objects, nb_of_sprites);
        else
            display_game(window, objects, nb_of_sprites);
    }
    destroy_objects(objects, nb_of_sprites);
}

int main(int argc, char **argv)
{
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h' &&
    argv[1][2] == '\0') {
        display_help();
        return 0;
    }
    if (argc == 2) {
        launch_game(argv[1]);
    } else {
        my_putstr("ERROR: Invalid argument, -h for help\n");
        return 84;
    }
    return 0;
}
