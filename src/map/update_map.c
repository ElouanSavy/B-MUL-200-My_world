/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-elouan.savy-camaret
** File description:
** update_map
*/

#include "my_world.h"
#include "my.h"
#include <math.h>

void find_corresponding(game_t *game, sfVector2f point, int y)
{
    map_t *map = game->map;
    int offset = game->cursor->offset;

    sfVector2f map_point = {0, 0};
    for (int x = 0; x < map->size.x; x++) {
        map_point = map->vector_map[y][x];
        if (map_point.x == point.x && map_point.y == point.y) {
            map->map_3d[y][x] += (offset) * game->cursor->direction;
        }
    }
    return;
}

int check_proximity(sfVector2i curs, sfVector2f point, \
cursor_t *cursor)
{
    float new_distance = calc_distances_2p(point, curs);
    if (new_distance < calc_distances_2p(cursor->nearest_point, curs)) {
        replace_nearest_point(cursor, point);
        return 0;
    }
    if (new_distance < calc_distances_2p(cursor->sec_nearest_point, curs)) {
        replace_sec_nearest_point(cursor, point);
        return 0;
    }
    if (new_distance < calc_distances_2p(cursor->third_nearest_point, curs)) {
        replace_third_nearest_point(cursor, point);
        return 0;
    }
    if (new_distance < calc_distances_2p(cursor->fourth_nearest_point, curs)) {
        replace_fourth_nearest_point(cursor, point);
        return 0;
    }
    return 0;
}

int update_map_line(map_t *map, sfVector2i cursor_pos, \
int i, cursor_t *cursor)
{
    sfVector2f **map_2d = map->vector_map;
    int size_x = map->size.x;
    for (int j = 0; j < size_x; j++)
        check_proximity(cursor_pos, map_2d[i][j], cursor);
    return 0;
}

void update_map(game_t *game, sfVector2i cursor_pos)
{
    map_t *map = game->map;
    for (int i = 0; i < map->size.y; i++) {
        update_map_line(map, cursor_pos, i, game->cursor);
    }
    for (int y = 0; y < map->size.y; y++)
        find_corresponding(game, game->cursor->nearest_point, y);
    if (game->cursor->mode == LINE || game->cursor->mode == SQUARE) {
        for (int y = 0; y < map->size.y; y++)
            find_corresponding(game, game->cursor->sec_nearest_point, y);
    }
    if (game->cursor->mode == SQUARE) {
        for (int y = 0; y < map->size.y; y++)
            find_corresponding(game, game->cursor->third_nearest_point, y);
        for (int y = 0; y < map->size.y; y++)
            find_corresponding(game, game->cursor->fourth_nearest_point, y);
    }
    return;
}

void update_vector_map(game_t *game)
{
    sfVector2f tmp;
    map_t *map = game->map;
    int zoom = 32  + game->zoom;

    for (int y = 0; y < map->size.y; y++) {
        for (int x = 0; x < map->size.x; x++) {
            tmp = project_iso_point(x * zoom, y * zoom, map->map_3d[y][x] * 6);
            tmp.x += game->offset.x;
            tmp.y += game->offset.y;
            map->vector_map[y][x] = tmp;
        }
    }
    return;
}
