/*
** EPITECH PROJECT, 2021
** sound_handling
** File description:
** handles everything sound related
*/

#include <SFML/Audio/Music.h>
#include <SFML/Audio/Sound.h>
#include "my_runner.h"

sfMusic *play_music(void)
{
    sfMusic *soundtrack = sfMusic_createFromFile("sounds/almost_home.ogg");
    sfMusic_setVolume(soundtrack, 30);
    sfMusic_play(soundtrack);
    sfMusic_setLoop(soundtrack, sfTrue);
    return soundtrack;
}
