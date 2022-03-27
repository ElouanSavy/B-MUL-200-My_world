/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-elouan.savy-camaret
** File description:
** load_handler
*/

#include "my_world.h"

void load_loop(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    if (game->load->map_list == NULL) {
        game->load->map_list = init_to_load(game);
    }
    display_load(game);
    event_load_handler(game);
    sfRenderWindow_display(game->window);
}
