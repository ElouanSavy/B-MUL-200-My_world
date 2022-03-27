/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-elouan.savy-camaret
** File description:
** check_tools_btn
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Time.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_world.h"
#include "my.h"

void check_tools_hover(btns_t *list, sfRenderWindow *window)
{
    sfIntRect rect = {0};
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    while (list != NULL) {
        rect = sfSprite_getTextureRect(list->sprite);
        rect.top = 1356;
        if (check_collision(mouse.x, mouse.y, list->sprite)) {
            rect.top = 1448;
            sfRenderWindow_drawSprite(window, list->help, NULL);
        }
        sfSprite_setTextureRect(list->sprite, rect);
        list = list->next;
    }
}

void check_utils_hover(g_tools_t *utils, sfRenderWindow *window)
{
    sfIntRect rect = {0};
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    rect = sfSprite_getTextureRect(utils->btn_menu);
    rect.top = 1356;
    if (check_collision(mouse.x, mouse.y, utils->btn_menu))
        rect.top = 1448;
    sfSprite_setTextureRect(utils->btn_menu, rect);
    sfRenderWindow_drawSprite(window, utils->btn_menu, NULL);
    rect = sfSprite_getTextureRect(utils->btn_save);
    rect.top = 2199;
    if (check_collision(mouse.x, mouse.y, utils->btn_save))
        rect.top = 2291;
    sfSprite_setTextureRect(utils->btn_save, rect);
    sfRenderWindow_drawSprite(window, utils->btn_save, NULL);
    return;
}

void reset_tool_state(btns_t *list)
{
    while (list != NULL) {
        list->selected = 0;
        list = list->next;
    }
}

int check_selec_btn(game_t *game, sfMouseButtonEvent mouse)
{
    btns_t *list = game->tools->btn_selec;
    while (list != NULL) {
        if (check_collision(mouse.x, mouse.y, list->sprite)) {
            reset_tool_state(game->tools->btn_selec);
            list->selected = 1;
            list->btn_action(game->cursor, game);
            return 1;
        }
        list = list->next;
    }
    return 0;
}

int check_terra_btn(game_t *game, sfMouseButtonEvent mouse)
{
    btns_t *list = game->tools->btn_terra;
    while (list != NULL) {
        if (check_collision(mouse.x, mouse.y, list->sprite)) {
            reset_tool_state(game->tools->btn_terra);
            list->selected = 1;
            list->btn_action(game->cursor, game);
            return 1;
        }
        list = list->next;
    }
    return 0;
}
