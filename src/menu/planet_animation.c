/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-elouan.savy-camaret
** File description:
** planet_animation
*/

#include "my_world.h"

void anim_planet(game_t *game)
{
    int time = sfClock_getElapsedTime(game->menu->planet_clock).microseconds;
    menu_t *menu = game->menu;
    if (time < 50000)
        return;
    sfClock_restart(menu->planet_clock);
    if (menu->sprite_rect.top == 5632 && menu->sprite_rect.left == 5632) {
        menu->sprite_rect.left = 0;
        menu->sprite_rect.top = 0;
    } else if (menu->sprite_rect.left == 5632) {
        menu->sprite_rect.left = 0;
        menu->sprite_rect.top += 512;
    } else
        menu->sprite_rect.left += 512;
    sfSprite_setTextureRect(menu->planet, menu->sprite_rect);
    return;
}
