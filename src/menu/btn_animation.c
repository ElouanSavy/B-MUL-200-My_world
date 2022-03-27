/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-elouan.savy-camaret
** File description:
** btn_animation
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Time.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_world.h"

void reset_menu_btn_state(game_t *game)
{
    menu_btn_t btn = game->menu->menu_btn;
    btn.rect_flat.top = 1080;
    sfSprite_setTextureRect(btn.flat, btn.rect_flat);
    btn.rect_noise.top = 1080;
    sfSprite_setTextureRect(btn.noise, btn.rect_noise);
    btn.rect_quit.top = 1080;
    sfSprite_setTextureRect(btn.quit, btn.rect_quit);
    btn.rect_load.top = 1080;
    sfSprite_setTextureRect(btn.load, btn.rect_load);
}

void anime_menu_btn_click(sfSprite *sprite)
{
    sfIntRect rect = sfSprite_getTextureRect(sprite);
    rect.top = 1264;
    sfSprite_setTextureRect(sprite, rect);
}

void change_menu_btn_state(game_t *game, sfMouseMoveEvent mouse)
{
    menu_btn_t btn = game->menu->menu_btn;
    reset_menu_btn_state(game);
    if (check_collision(mouse.x, mouse.y, btn.flat)) {
        btn.rect_flat.top += 92;
        sfSprite_setTextureRect(btn.flat, btn.rect_flat);
    }
    if (check_collision(mouse.x, mouse.y, btn.noise)) {
        btn.rect_noise.top += 92;
        sfSprite_setTextureRect(btn.noise, btn.rect_noise);
    }
    if (check_collision(mouse.x, mouse.y, btn.load)) {
        btn.rect_load.top += 92;
        sfSprite_setTextureRect(btn.load, btn.rect_load);
    }
    if (check_collision(mouse.x, mouse.y, btn.quit)) {
        btn.rect_quit.top += 92;
        sfSprite_setTextureRect(btn.quit, btn.rect_quit);
    }
}
