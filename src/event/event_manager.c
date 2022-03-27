/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-elouan.savy-camaret
** File description:
** event_manager
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Time.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_world.h"

void quit_game(game_t *game)
{
    if (game->save_path != NULL)
        save_file(game, game->save_path);
    sfRenderWindow_close(game->window);
}

void up_down_map(game_t *game, sfEvent event)
{
    sfVector2i cursor_pos = sfMouse_getPositionRenderWindow(game->window);

    if (event.mouseButton.button == sfMouseLeft) {
        update_map(game, cursor_pos);
    } else if (event.mouseButton.button == sfMouseRight) {
        update_map(game, cursor_pos);
    }
    return;
}

void clicked_handling(sfEvent ev, game_t *game)
{
    sfSprite *cursor = game->tools->scroller->cursor;
    if (check_collision(ev.mouseButton.x, ev.mouseButton.y, cursor) == 1) {
        game->tracked = 1;
        return;
    }
    if (check_selec_btn(game, ev.mouseButton) == 1)
        return;
    if (check_terra_btn(game, ev.mouseButton) == 1)
        return;
    if (check_utils_click(ev, game) == 1)
        return;
    up_down_map(game, ev);
    sfMusic_stop(game->musics->hit_sound);
    sfMusic_play(game->musics->hit_sound);
    return;
}

void move_around(sfEvent event, game_t *game)
{
    switch (event.key.code) {
        case sfKeyRight :
            game->offset.x += 10;
            break;
        case sfKeyLeft :
            game->offset.x -= 10;
            break;
        case sfKeyUp :
            game->offset.y += 10;
            break;
        case sfKeyDown :
            game->offset.y -= 10;
            break;
        default :
            break;
    }
    zoom_around(event, game);
    return;
}

void event_handler(game_t *game)
{
    sfEvent event;
    if (sfRenderWindow_pollEvent(game->window, &event)) {
        switch (event.type) {
        case sfEvtClosed :
            quit_game(game);
            break;
        case sfEvtMouseButtonPressed :
            clicked_handling(event, game);
            break;
        case sfEvtMouseButtonReleased :
            if (game->tracked == 1)
                game->tracked = 0;
            break;
        case sfEvtKeyPressed :
            move_around(event, game);
            check_shortcut(event, game);
        default:
            break;
        }
    }
}
