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

void reset_load_btn_state(game_t *game)
{
    load_t *btn = game->load;
    sfIntRect rect = sfSprite_getTextureRect(btn->btn_back);
    rect.top = 1356;
    sfSprite_setTextureRect(btn->btn_back, rect);
    rect = sfSprite_getTextureRect(btn->btn_load);
    rect.top = 1356;
    sfSprite_setTextureRect(btn->btn_load, rect);
}

void change_load_btn_state(game_t *game, sfMouseMoveEvent mouse)
{
    load_t *btn = game->load;
    sfIntRect rect = {0};
    reset_load_btn_state(game);
    if (check_collision(mouse.x, mouse.y, btn->btn_back)) {
        rect = sfSprite_getTextureRect(btn->btn_back);
        rect.top = 1448;
        sfSprite_setTextureRect(btn->btn_back, rect);
    }
    if (check_collision(mouse.x, mouse.y, btn->btn_load)) {
        rect = sfSprite_getTextureRect(btn->btn_load);
        rect.top = 1448;
        sfSprite_setTextureRect(btn->btn_load, rect);
    }
}
