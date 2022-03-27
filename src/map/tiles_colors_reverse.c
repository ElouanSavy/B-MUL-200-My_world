/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-elouan.savy-camaret
** File description:
** tiles_colors
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

sfColor get_color_reverse_green(int **map, int x, int y)
{
    sfColor dark_green = sfColor_fromRGB(89, 139, 44);
    sfColor light_green = sfColor_fromRGB(110, 171, 53);
    sfColor mid_green = sfColor_fromRGB(102, 157, 49);

    if (map[x + 1][y + 1] < map[x + 1][y] && map[x + 1][y + 1] < map[x][y + 1])
        return (light_green);
    if (map[x][y + 1] >= map[x + 1][y] && map[x][y + 1] >= map[x + 1][y + 1])
        return (dark_green);
    if (map[x + 1][y] >= map[x][y + 1] && map[x + 1][y] >= map[x + 1][y + 1])
        return (mid_green);
    return (light_green);
}

sfColor get_color_reverse_grey(int **map, int x, int y)
{
    sfColor clear_grey = sfColor_fromRGB(143, 143, 143);
    sfColor mid_grey = sfColor_fromRGB(125, 125, 125);
    sfColor dark_grey = sfColor_fromRGB(112, 112, 112);

    if (map[x + 1][y + 1] < map[x + 1][y] && map[x + 1][y + 1] < map[x][y + 1])
        return (clear_grey);
    if (map[x][y + 1] >= map[x + 1][y] && map[x][y + 1] >= map[x + 1][y + 1])
        return (dark_grey);
    if (map[x + 1][y] >= map[x][y + 1] && map[x + 1][y] >= map[x + 1][y + 1])
        return (mid_grey);
    return (clear_grey);
}

sfColor get_color_reverse_white(int **map, int x, int y)
{
    sfColor mid_white = sfColor_fromRGB(208, 230, 230);
    sfColor dark_white = sfColor_fromRGB(193, 214, 214);

    if (map[x + 1][y + 1] < map[x + 1][y] && map[x + 1][y + 1] < map[x][y + 1])
        return (sfWhite);
    if (map[x][y + 1] >= map[x + 1][y] && map[x][y + 1] >= map[x + 1][y + 1])
        return (dark_white);
    if (map[x + 1][y] >= map[x][y + 1] && map[x + 1][y] >= map[x + 1][y + 1])
        return (mid_white);
    return (sfWhite);
}

sfColor get_color_reverse(game_t *game, int x, int y)
{
    int **map = game->map->map_3d;
    float av_alt = (map[x + 1][y + 1] + map[x + 1][y] + map[x][y + 1]) / 3;

    if (av_alt > 33)
        return get_color_reverse_white(map, x, y);
    if (av_alt > 28)
        return get_color_reverse_grey(map, x, y);
    return get_color_reverse_green(map, x, y);
}
