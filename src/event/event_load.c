/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-elouan.savy-camaret
** File description:
** event_load
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Time.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_world.h"

void click_manager(game_t *game, sfMouseButtonEvent mouse)
{
    if (check_collision(mouse.x, mouse.y, game->load->btn_back)) {
        game->load->map_list = free_map_list(game);
        game->state = GS_MENU;
        return;
    }
    if (check_collision(mouse.x, mouse.y, game->load->btn_load)) {
        game->map = load_save_map(game);
        game->load->map_list = free_map_list(game);
        if (game->map != NULL)
            game->state = GS_PLAY;
        return;
    }
    game = check_map_collision(game, mouse);
}

void event_load_handler(game_t *game)
{
    sfEvent event;
    if (sfRenderWindow_pollEvent(game->window, &event)) {
        switch (event.type) {
        case sfEvtClosed:
            quit_game(game);
            break;
        case sfEvtMouseMoved:
            change_load_btn_state(game, event.mouseMove);
            break;
        case sfEvtMouseButtonPressed:
            click_manager(game, event.mouseButton);
            break;
        default:
            break;
        }
    }
}
