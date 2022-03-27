/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-elouan.savy-camaret
** File description:
** calc_distances
*/

#include "my_world.h"
#include <math.h>

float calc_distances_2p(sfVector2f p1, sfVector2i c)
{
    float dist = (p1.x - c.x) * (p1.x - c.x) + (p1.y - c.y) * (p1.y - c.y);
    return sqrt(dist);
}

int check_simil(float new_distance, sfVector2i curs, sfVector2f c_point)
{
    float val1 = floor(new_distance * 10) / 10;
    float val2 = floor(calc_distances_2p(c_point, curs) * 10) / 10;
    if (val1 == val2)
        return 1;
    return 0;
}
