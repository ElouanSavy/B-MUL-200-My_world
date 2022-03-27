/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-elouan.savy-camaret
** File description:
** check_clic
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_world.h"

int check_utils_click(sfEvent ev, game_t *game)
{
    sfSprite *menu = game->tools->btn_menu;
    sfSprite *save = game->tools->btn_save;
    if (check_collision(ev.mouseButton.x, ev.mouseButton.y, menu)) {
        game->state = GS_MENU;
        save_file(game, game->save_path);
        free_map_ressources(game);
        game->save_path = NULL;
        return 1;
    }
    if (check_collision(ev.mouseButton.x, ev.mouseButton.y, save)) {
        save_file(game, game->save_path);
        return 1;
    }
    return 0;
}
