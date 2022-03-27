/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-elouan.savy-camaret
** File description:
** modif_assist
*/

#include "my_world.h"
#include <math.h>

int check_proximity_curs_2(sfVector2i curs, sfVector2f point, \
cursor_t *cursor, float new_distance)
{
    if (check_simil(new_distance, curs, cursor->c_third_point) == 1)
        return 0;
    if (new_distance < calc_distances_2p(cursor->c_third_point, curs)) {
        replace_third_nearest_point_curs(cursor, point);
        return 0;
    }
    if (check_simil(new_distance, curs, cursor->c_fourth_point) == 1)
        return 0;
    if (new_distance < calc_distances_2p(cursor->c_fourth_point, curs)) {
        replace_fourth_nearest_point_curs(cursor, point);
        return 0;
    }
    return 0;
}

int check_proximity_curs(sfVector2i curs, sfVector2f point, \
cursor_t *cursor)
{
    float new_distance = calc_distances_2p(point, curs);
    if (check_simil(new_distance, curs, cursor->c_point) == 1)
        return 0;
    if (new_distance < calc_distances_2p(cursor->c_point, curs)) {
        replace_nearest_point_curs(cursor, point);
        return 0;
    }
    if (check_simil(new_distance, curs, cursor->c_sec_point) == 1)
        return 0;
    if (new_distance < calc_distances_2p(cursor->c_sec_point, curs)) {
        replace_sec_nearest_point_curs(cursor, point);
        return 0;
    }
    check_proximity_curs_2(curs, point, cursor, new_distance);
    return 0;
}

int update_map_line_curs(map_t *map, sfVector2i cursor_pos, \
int i, cursor_t *cursor)
{
    sfVector2f **map_2d = map->vector_map;
    int size_x = map->size.x;
    for (int j = 0; j < size_x; j++)
        check_proximity_curs(cursor_pos, map_2d[i][j], cursor);
    return 0;
}

int get_near_point(game_t *game, sfVector2i cursor_pos)
{
    map_t *map = game->map;
    for (int i = 0; i < map->size.y; i++) {
        update_map_line_curs(map, cursor_pos, i, game->cursor);
    }
    return 0;
}

int update_cursor(game_t *game)
{
    cursor_t *cursor = game->cursor;
    sfRenderWindow *window = game->window;
    sfVector2i cursor_pos = sfMouse_getPositionRenderWindow(game->window);
    get_near_point(game, cursor_pos);
    sfCircleShape_setPosition(cursor->cursor_point_1, cursor->c_point);
    sfCircleShape_setPosition(cursor->cursor_point_2, cursor->c_sec_point);
    sfCircleShape_setPosition(cursor->cursor_point_3, cursor->c_third_point);
    sfCircleShape_setPosition(cursor->cursor_point_4, cursor->c_fourth_point);
    sfRenderWindow_drawCircleShape(window, cursor->cursor_point_1, NULL);
    if (cursor->mode == LINE || cursor->mode == SQUARE)
    sfRenderWindow_drawCircleShape(window, cursor->cursor_point_2, NULL);
    if (cursor->mode == SQUARE) {
        sfRenderWindow_drawCircleShape(window, cursor->cursor_point_3, NULL);
        sfRenderWindow_drawCircleShape(window, cursor->cursor_point_4, NULL);
    }
    return 0;
}
