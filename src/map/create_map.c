/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-elouan.savy-camaret
** File description:
** create_map
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

sfVector2f project_iso_point(int x, int y, int z)
{
    sfVector2f point_2d = {0, 0};
    double angle_x = 45 * MY_PI / 180.0;
    double angle_y = 35 * MY_PI / 180.0;

    point_2d.x = cos(angle_x) * x - cos(angle_x) * y;
    point_2d.y = sin(angle_y) * y + sin(angle_y) * x - z;
    point_2d.x += 1000;
    return (point_2d);
}

map_t *create_2d_map(map_t *map)
{
    map->vector_map = malloc(sizeof(sfVector2f *) * map->size.y);
    sfVector2f tmp;

    for (int y = 0; y < map->size.y; y++) {
        map->vector_map[y] = malloc(sizeof(sfVector2f) * (map->size.x));
        for (int x = 0; x < map->size.x; x++) {
            tmp = project_iso_point(x * 32, y * 32, map->map_3d[y][x] * 6);
            map->vector_map[y][x] = tmp;
        }
    }
    return (map);
}
