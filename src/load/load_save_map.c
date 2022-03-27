/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-elouan.savy-camaret
** File description:
** load_save_map
*/

#include <stdio.h>
#include "my_world.h"
#include "my.h"

map_t *load_save_map(game_t *game)
{
    to_load_t *load = game->load->tmp;
    game->save_path = str_concat("assets/save", load->name, '/');
    if (game->load->tmp != NULL) {
        return (init_map(str_concat("assets/save", load->name, '/')));
    }
    return (NULL);
}
