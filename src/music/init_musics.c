/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-elouan.savy-camaret
** File description:
** init_musics
*/

#include "my_world.h"
#include "my.h"

musics_t *init_game_musics(void)
{
    musics_t *musics = malloc(sizeof(musics_t));
    sfMusic *hit_sound = sfMusic_createFromFile("assets/musics/hit_sound.ogg");

    musics->hit_sound = hit_sound;
    return musics;
}
