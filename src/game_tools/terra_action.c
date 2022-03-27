/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-elouan.savy-camaret
** File description:
** terra_action
*/

#include "my_world.h"

void up_terra(cursor_t *cursor, __attribute__((unused)) game_t *game)
{
    cursor->direction = 1;
    return;
}

void down_terra(cursor_t *cursor, __attribute__((unused)) game_t *game)
{
    cursor->direction = -1;
    return;
}

void reset_terra(cursor_t *cursor, __attribute__((unused)) game_t *game)
{
    cursor->direction = cursor->direction;
    free_map_ressources(game);
    game->map = init_map(game->save_path);
    return;
}
