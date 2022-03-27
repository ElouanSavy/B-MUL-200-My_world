/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-elouan.savy-camaret
** File description:
** display_map
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Time.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "my_world.h"

void display_lines(game_t *game, int x, int y)
{
    sfVertexArray *tmp = NULL;
    sfVector2f **map = game->map->vector_map;

    tmp = create_line(&map[x][y], &map[x + 1][y]);
    sfRenderWindow_drawVertexArray(game->window, tmp, NULL);
    sfVertexArray_destroy(tmp);
    tmp = create_line(&map[x][y], &map[x][y + 1]);
    sfRenderWindow_drawVertexArray(game->window, tmp, NULL);
    sfVertexArray_destroy(tmp);
}

void draw_2d_map(game_t *game)
{
    sfVertexArray *tmp = NULL;
    sfVector2f **map = game->map->vector_map;

    for (int y = 0; y < game->map->size.y - 1; y++) {
        for (int x = 0; x < game->map->size.x - 1; x++) {
            tmp = create_triangle(&map[x][y], &map[x + 1][y], &map[x][y + 1], \
            get_color(game, x, y));
            sfRenderWindow_drawVertexArray(game->window, tmp, NULL);
            sfVertexArray_destroy(tmp);
            tmp = create_triangle(&map[x + 1][y + 1], &map[x][y + 1], \
            &map[x + 1][y], get_color_reverse(game, x, y));
            sfRenderWindow_drawVertexArray(game->window, tmp, NULL);
            sfVertexArray_destroy(tmp);
            display_lines(game, x, y);
        }
    }
}
