/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-elouan.savy-camaret
** File description:
** shortcut_handler
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Time.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_world.h"

game_t *check_shortcut(sfEvent event, game_t *game)
{
    switch (event.key.code) {
        case sfKeySpace :
            save_file(game, game->save_path);
            break;
        case sfKeyEscape :
            game->state = GS_MENU;
            save_file(game, game->save_path);
            free_map_ressources(game);
            game->save_path = NULL;
            break;
        default :
            break;
    }
    return (game);
}
