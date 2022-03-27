/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-elouan.savy-camaret
** File description:
** game_tools_handler
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

g_tools_t *init_game_tools(game_t *game)
{
    g_tools_t *g_tools = malloc(sizeof(g_tools_t));
    sfIntRect rect = {6144, 1632, 332, 150};
    sfIntRect rect_save = {6144, 2199, 92, 92};
    sfIntRect rect_menu = {6696, 1356, 92, 92};
    sfIntRect rect_bg = {6236, 2199, 225, 116};

    g_tools->btn_selec = init_list_selec(game);
    g_tools->btn_terra = init_list_terra(game);
    g_tools->selector = create_menu_btn(game, rect, 70, 875);
    g_tools->btn_menu = create_menu_btn(game, rect_menu, 1761, 12);
    g_tools->btn_save = create_menu_btn(game, rect_save, 1652, 12);
    g_tools->utils_bg = create_menu_btn(game, rect_bg, 1640, 0);
    rect.top = 1782;
    g_tools->terraforming = create_menu_btn(game, rect, 70, 0);
    return (g_tools);
}
