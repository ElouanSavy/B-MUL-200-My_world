/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-elouan.savy-camaret
** File description:
** menu_handler
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Time.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_world.h"

sfSprite *create_menu_btn(game_t *game, sfIntRect rect, int x, int y)
{
    sfVector2f pos = {x, y};
    sfSprite *btn = sfSprite_create();
    sfSprite_setTexture(btn, game->texture, sfTrue);
    sfSprite_setTextureRect(btn, rect);
    sfSprite_setPosition(btn, pos);
    return (btn);
}

menu_btn_t init_menu_btn(game_t *game)
{
    menu_btn_t menu_btn;
    sfIntRect rect_load = {7130, 1080, 493, 92};
    sfIntRect rect_quit = {7623, 1080, 297, 92};
    sfIntRect rect_flat = {6144, 1080, 493, 92};
    sfIntRect rect_noise = {6637, 1080, 493, 92};

    menu_btn.rect_load = rect_load;
    menu_btn.rect_quit = rect_quit;
    menu_btn.rect_flat = rect_flat;
    menu_btn.rect_noise = rect_noise;
    menu_btn.load = create_menu_btn(game, rect_load, 281, 540);
    menu_btn.quit = create_menu_btn(game, rect_quit, 379, 696);
    menu_btn.flat = create_menu_btn(game, rect_flat, 281, 292);
    menu_btn.noise = create_menu_btn(game, rect_noise, 281, 416);
    return (menu_btn);
}

menu_t *init_menu(game_t *game)
{
    menu_t *menu = malloc(sizeof(menu_t));
    sfIntRect rect_bg = {6144, 0, 1920, 1080};
    sfIntRect rect_planet = {0, 0, 512, 512};
    sfVector2f pos_planet = {1085, 215};
    sfVector2f pos_bg = {0, 0};

    menu->sprite_rect = rect_planet;
    menu->bg = sfSprite_create();
    menu->planet = sfSprite_create();
    menu->planet_clock = sfClock_create();
    sfSprite_setTexture(menu->planet, game->texture, sfTrue);
    sfSprite_setTexture(menu->bg, game->texture, sfTrue);
    sfSprite_setTextureRect(menu->bg, rect_bg);
    sfSprite_setTextureRect(menu->planet, menu->sprite_rect);
    sfSprite_setPosition(menu->planet, pos_planet);
    sfSprite_setPosition(menu->bg, pos_bg);
    menu->menu_btn = init_menu_btn(game);
    return (menu);
}

int menu_loop(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    event_menu_handler(game);
    anim_planet(game);
    display_menu(game);
    sfRenderWindow_display(game->window);
    return (0);
}
