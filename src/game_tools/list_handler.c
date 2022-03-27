/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-elouan.savy-camaret
** File description:
** list_handler
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

btns_t *add_btn_list(btns_t *list, sfSprite *sprite, \
void *action, sfSprite *help)
{
    btns_t *element = malloc(sizeof(btns_t));

    element->btn_action = action;
    element->sprite = sprite;
    element->selected = 0;
    element->help = help;
    element->next = list;
    list = element;
    return (list);
}

sfSprite *create_btn(sfIntRect rect, game_t *game, sfVector2f pos)
{
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, game->texture, sfTrue);
    sfSprite_setTextureRect(sprite, rect);
    sfSprite_setPosition(sprite, pos);
    return (sprite);
}

sfSprite *hb_create(sfVector2f pos, game_t *game, int x, int y)
{
    sfSprite *help = sfSprite_create();
    sfSprite_setTexture(help, game->texture, sfTrue);
    sfSprite_setTextureRect(help, (sfIntRect) {x, y, 124, 34});
    sfSprite_setPosition(help, pos);
    return (help);
}

btns_t *init_list_selec(game_t *game)
{
    btns_t *list = NULL;
    sfIntRect rect = {6144, 1356, 92, 92};
    sfVector2f pos = {82, 921};
    sfSprite *hb1 = hb_create((sfVector2f) {8, 883}, game, 6144, 1949);
    sfSprite *hb2 = hb_create((sfVector2f) {224, 883}, game, 6268, 1949);
    sfSprite *hb3 = hb_create((sfVector2f) {357, 883}, game, 6392, 1949);

    list = add_btn_list(list, create_btn(rect, game, pos), &point_select, hb1);
    rect.left += 92;
    pos.x += 108;
    list = add_btn_list(list, create_btn(rect, game, pos), &line_select, hb2);
    rect.left += 92;
    pos.x += 108;
    list = add_btn_list(list, create_btn(rect, game, pos), &tile_select, hb3);
    list->selected = 1;
    return (list);
}

btns_t *init_list_terra(game_t *game)
{
    btns_t *list = NULL;
    sfIntRect rect = {6420, 1356, 92, 92};
    sfVector2f pos = {86, 12};
    sfSprite *help1 = hb_create((sfVector2f) {4, 112}, game, 6144, 1983);
    sfSprite *help2 = hb_create((sfVector2f) {259, 112}, game, 6268, 1983);
    sfSprite *help = hb_create((sfVector2f) {327, 112}, game, 6392, 1983);

    list = add_btn_list(list, create_btn(rect, game, pos), &up_terra, help1);
    list->selected = 1;
    rect.left += 92;
    pos.x += 108;
    list = add_btn_list(list, create_btn(rect, game, pos), &down_terra, help2);
    rect.left += 92;
    pos.x += 108;
    list = add_btn_list(list, create_btn(rect, game, pos), &reset_terra, help);
    return (list);
}
