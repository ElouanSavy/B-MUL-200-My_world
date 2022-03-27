/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-elouan.savy-camaret
** File description:
** free_ressources
*/

#include <stdlib.h>
#include "my_world.h"

int free_map_ressources(game_t *game)
{
    for (int i = 0; i < 40; i++) {
        free(game->map->map_3d[i]);
        free(game->map->vector_map[i]);
    }
    free(game->map);
    return (0);
}
