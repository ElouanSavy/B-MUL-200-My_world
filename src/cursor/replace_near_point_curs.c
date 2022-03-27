/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-elouan.savy-camaret
** File description:
** replace_near_point
*/

#include "my_world.h"
#include <math.h>

void replace_nearest_point_curs(cursor_t *cursor, sfVector2f point)
{
    cursor->c_fourth_point = cursor->c_third_point;
    cursor->c_third_point = cursor->c_sec_point;
    cursor->c_sec_point = cursor->c_point;
    cursor->c_point = point;
}

void replace_sec_nearest_point_curs(cursor_t *cursor, sfVector2f point)
{
    cursor->c_fourth_point = cursor->c_third_point;
    cursor->c_third_point = cursor->c_sec_point;
    cursor->c_sec_point = point;
}

void replace_third_nearest_point_curs(cursor_t *cursor, sfVector2f point)
{
    cursor->c_fourth_point = cursor->c_third_point;
    cursor->c_third_point = point;
}

void replace_fourth_nearest_point_curs(cursor_t *cursor, sfVector2f point)
{
    cursor->c_fourth_point = point;
}
