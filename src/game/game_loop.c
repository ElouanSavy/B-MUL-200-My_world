/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-elouan.savy-camaret
** File description:
** game_loop
*/

#include "my_world.h"

void display_scroller(game_t *game)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(game->window);
    scroller_t *scroller = game->tools->scroller;
    if (game->tracked == 0)
        update_cursor(game);
    if (game->tracked == 1 && pos.x >= 435 && pos.x <= 668) {
        sfSprite_setPosition(scroller->cursor, (sfVector2f) {pos.x, 12});
        update_text(game);
    }
    sfRenderWindow_drawSprite(game->window, scroller->background, NULL);
    sfRenderWindow_drawSprite(game->window, scroller->cursor, NULL);
    sfRenderWindow_drawText(game->window, scroller->text, NULL);
}

int game_loop(game_t *game)
{
    sfRenderWindow_clear(game->window, game->bg_color);
    draw_2d_map(game);
    update_cursor(game);
    update_offset(game);
    update_vector_map(game);
    display_scroller(game);
    display_container_tool(game);
    check_tools_hover(game->tools->btn_selec, game->window);
    check_tools_hover(game->tools->btn_terra, game->window);
    check_utils_hover(game->tools, game->window);
    display_game_tools(game->tools->btn_selec, game->window);
    display_game_tools(game->tools->btn_terra, game->window);
    display_game_utilities(game->tools, game->window);
    event_handler(game);
    sfRenderWindow_display(game->window);
    return (0);
}
