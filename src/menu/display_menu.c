/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-elouan.savy-camaret
** File description:
** display_menu
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Time.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_world.h"

void display_menu(game_t *game)
{
    menu_t *menu = game->menu;

    sfRenderWindow_drawSprite(game->window, menu->bg, NULL);
    sfRenderWindow_drawSprite(game->window, menu->planet, NULL);
    sfRenderWindow_drawSprite(game->window, menu->menu_btn.load, NULL);
    sfRenderWindow_drawSprite(game->window, menu->menu_btn.quit, NULL);
    sfRenderWindow_drawSprite(game->window, menu->menu_btn.noise, NULL);
    sfRenderWindow_drawSprite(game->window, menu->menu_btn.flat, NULL);
}
