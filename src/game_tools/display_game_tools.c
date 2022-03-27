/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-elouan.savy-camaret
** File description:
** display_game_tools
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

void display_container_tool(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->tools->selector, NULL);
    sfRenderWindow_drawSprite(game->window, game->tools->terraforming, NULL);
}

void display_game_tools(btns_t *list, sfRenderWindow *window)
{
    sfIntRect rect = {0};
    while (list != NULL) {
        if (list->selected) {
            rect = sfSprite_getTextureRect(list->sprite);
            rect.top = 1540;
            sfSprite_setTextureRect(list->sprite, rect);
        }
        sfRenderWindow_drawSprite(window, list->sprite, NULL);
        list = list->next;
    }
}

void display_game_utilities(g_tools_t *tools, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, tools->utils_bg, NULL);
    sfRenderWindow_drawSprite(window, tools->btn_menu, NULL);
    sfRenderWindow_drawSprite(window, tools->btn_save, NULL);
    return;
}
