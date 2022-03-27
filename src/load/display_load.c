/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-elouan.savy-camaret
** File description:
** display_load
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Time.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include "my_world.h"

void display_load(game_t *game)
{
    to_load_t *map_list = game->load->map_list;
    sfRenderWindow_drawSprite(game->window, game->menu->bg, NULL);
    sfRenderWindow_drawSprite(game->window, game->load->container, NULL);
    sfRenderWindow_drawSprite(game->window, game->load->btn_back, NULL);
    sfRenderWindow_drawSprite(game->window, game->load->btn_load, NULL);
    while (map_list != NULL) {
        sfRenderWindow_drawSprite(game->window, map_list->bg, NULL);
        sfRenderWindow_drawText(game->window, map_list->text, NULL);
        map_list = map_list->next;
    }
    return;
}
