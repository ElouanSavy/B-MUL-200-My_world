/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-elouan.savy-camaret
** File description:
** replace_near_point
*/

#include "my_world.h"

void replace_nearest_point(cursor_t *cursor, sfVector2f point)
{
    cursor->fourth_nearest_point = cursor->third_nearest_point;
    cursor->third_nearest_point = cursor->sec_nearest_point;
    cursor->sec_nearest_point = cursor->nearest_point;
    cursor->nearest_point = point;
}

void replace_sec_nearest_point(cursor_t *cursor, sfVector2f point)
{
    cursor->fourth_nearest_point = cursor->third_nearest_point;
    cursor->third_nearest_point = cursor->sec_nearest_point;
    cursor->sec_nearest_point = point;
}

void replace_third_nearest_point(cursor_t *cursor, sfVector2f point)
{
    cursor->fourth_nearest_point = cursor->third_nearest_point;
    cursor->third_nearest_point = point;
}

void replace_fourth_nearest_point(cursor_t *cursor, sfVector2f point)
{
    cursor->fourth_nearest_point = point;
}
