/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-elouan.savy-camaret
** File description:
** free_all_ressources
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

game_t *free_cursor(game_t *game)
{
    sfCircleShape_destroy(game->cursor->cursor_point_1);
    sfCircleShape_destroy(game->cursor->cursor_point_2);
    sfCircleShape_destroy(game->cursor->cursor_point_3);
    sfCircleShape_destroy(game->cursor->cursor_point_4);
    free(game->cursor);
    return (game);
}

game_t *free_tools(game_t *game)
{
    btns_t *save = NULL;
    sfSprite_destroy(game->tools->btn_menu);
    sfSprite_destroy(game->tools->btn_save);
    sfSprite_destroy(game->tools->selector);
    sfSprite_destroy(game->tools->terraforming);
    sfSprite_destroy(game->tools->utils_bg);
    while (game->tools->btn_selec != NULL) {
        save = game->tools->btn_selec;
        game->tools->btn_selec = game->tools->btn_selec->next;
        free(save);
    }
    free(game->tools->btn_selec);
    while (game->tools->btn_terra != NULL) {
        save = game->tools->btn_terra;
        game->tools->btn_terra = game->tools->btn_terra->next;
        free(save);
    }
    free(game->tools->btn_terra);
    return (game);
}

game_t *free_menu(game_t *game)
{
    sfSprite_destroy(game->menu->bg);
    sfSprite_destroy(game->menu->planet);
    sfClock_destroy(game->menu->planet_clock);
    sfSprite_destroy(game->menu->menu_btn.flat);
    sfSprite_destroy(game->menu->menu_btn.load);
    sfSprite_destroy(game->menu->menu_btn.noise);
    sfSprite_destroy(game->menu->menu_btn.quit);
    sfMusic_destroy(game->musics->hit_sound);
    free(game->musics);
    free(game->menu);
    return (game);
}

game_t *free_load(game_t *game)
{
    sfSprite_destroy(game->load->btn_back);
    sfSprite_destroy(game->load->btn_load);
    sfSprite_destroy(game->load->container);
    free(game->load->map_list);
    free(game->load);
    return (game);
}

int free_all_ressources(game_t *game)
{
    game = free_cursor(game);
    game = free_menu(game);
    game = free_tools(game);
    game = free_load(game);
    sfSprite_destroy(game->tools->scroller->background);
    sfSprite_destroy(game->tools->scroller->cursor);
    sfText_destroy(game->tools->scroller->text);
    free(game->tools->scroller);
    free(game->tools);
    free(game->save_path);
    sfTexture_destroy(game->texture);
    free(game);
    return (0);
}
