/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-elouan.savy-camaret
** File description:
** cursor
*/

#include "my_world.h"
#include <stdlib.h>

sfCircleShape *create_circle(void)
{
    sfCircleShape *cursor_shape = sfCircleShape_create();
    sfCircleShape_setFillColor(cursor_shape, sfBlack);
    sfCircleShape_setRadius(cursor_shape, 5);
    sfCircleShape_setOrigin(cursor_shape, (sfVector2f) {5, 5});
    return cursor_shape;
}

cursor_t *create_cursor(void)
{
    cursor_t *cursor = malloc(sizeof(cursor_t));
    cursor->nearest_point = (sfVector2f) {0, 0};
    cursor->sec_nearest_point = (sfVector2f) {0, 0};
    cursor->third_nearest_point = (sfVector2f) {0, 0};
    cursor->fourth_nearest_point = (sfVector2f) {0, 0};
    cursor->c_point = (sfVector2f) {0, 0};
    cursor->c_sec_point = (sfVector2f) {0, 0};
    cursor->c_third_point = (sfVector2f) {0, 0};
    cursor->c_fourth_point = (sfVector2f) {0, 0};
    cursor->cursor_point_1 = create_circle();
    cursor->cursor_point_2 = create_circle();
    cursor->cursor_point_3 = create_circle();
    cursor->cursor_point_4 = create_circle();
    cursor->mode = SQUARE;
    cursor->direction = 1;
    return cursor;
}
