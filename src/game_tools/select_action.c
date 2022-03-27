/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-elouan.savy-camaret
** File description:
** tool_action
*/

#include "my_world.h"

void point_select(cursor_t *cursor, __attribute__((unused)) game_t *game)
{
    cursor->mode = POINT;
}

void line_select(cursor_t *cursor, __attribute__((unused)) game_t *game)
{
    cursor->mode = LINE;
}

void tile_select(cursor_t *cursor, __attribute__((unused)) game_t *game)
{
    cursor->mode = SQUARE;
}
