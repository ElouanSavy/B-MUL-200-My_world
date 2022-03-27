/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-elouan.savy-camaret
** File description:
** event_menu
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Time.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_world.h"

int check_collision(float x, float y, sfSprite* sprite)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(sprite);

    if (x > bounds.left && x < (bounds.left + bounds.width)) {
        if (y > bounds.top && y < (bounds.top + bounds.height)) {
            return (1);
        }
    }
    return (0);
}

void click_handler(game_t *game, sfMouseButtonEvent mouse)
{
    if (check_collision(mouse.x, mouse.y, game->menu->menu_btn.noise)) {
        anime_menu_btn_click(game->menu->menu_btn.noise);
        game->map = init_rand_map(game);
        save_file(game, get_path(game));
        game->state = GS_PLAY;
    }
    if (check_collision(mouse.x, mouse.y, game->menu->menu_btn.flat)) {
        anime_menu_btn_click(game->menu->menu_btn.flat);
        game->map = init_map("assets/maps/map_flat.txt");
        save_file(game, get_path(game));
        game->state = GS_PLAY;
    }
    if (check_collision(mouse.x, mouse.y, game->menu->menu_btn.load)) {
        anime_menu_btn_click(game->menu->menu_btn.load);
        game->state = GS_LOAD;
    }
    if (check_collision(mouse.x, mouse.y, game->menu->menu_btn.quit)) {
        anime_menu_btn_click(game->menu->menu_btn.quit);
        quit_game(game);
    }
}

void event_menu_handler(game_t *game)
{
    sfEvent event;
    if (sfRenderWindow_pollEvent(game->window, &event)) {
        switch (event.type) {
        case sfEvtClosed :
            quit_game(game);
            break;
        case sfEvtMouseMoved :
            change_menu_btn_state(game, event.mouseMove);
            break;
        case sfEvtMouseButtonPressed :
            click_handler(game, event.mouseButton);
            break;
        default :
            break;
        }
    }
}

void zoom_around(sfEvent event, game_t *game)
{
    if (event.key.code == sfKeyZ)
        game->zoom += 5;
    if (event.key.code == sfKeyS)
        game->zoom -= 5;
    return;
}
