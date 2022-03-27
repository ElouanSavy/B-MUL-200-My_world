/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-elouan.savy-camaret
** File description:
** scroll_init
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

sfText *init_scroll_text(void)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/fonts/Oswald-Medium.ttf");
    sfColor color = sfColor_fromRGB(225, 229, 242);
    sfText_setFont(text, font);
    sfText_setString(text, "2");
    sfText_setFillColor(text, color);
    sfText_setScale(text, (sfVector2f) {0.7, 0.7});
    sfText_setPosition(text, (sfVector2f) {460, 12});
    sfText_setOrigin(text, (sfVector2f) {8, 0});
    return text;
}

scroller_t *init_scroller(game_t *game)
{
    scroller_t *scroller = malloc(sizeof(scroller_t));
    sfSprite *background = sfSprite_create();
    sfSprite *cursor = sfSprite_create();
    sfIntRect rect = {6476, 1782, 310, 49};
    sfIntRect rect_curs = {6476, 1831, 26, 26};
    sfSprite_setPosition(background, (sfVector2f) {402, 0});
    sfSprite_setPosition(cursor, (sfVector2f) {460, 12});
    sfSprite_setOrigin(cursor, (sfVector2f) {13, 0});
    sfSprite_setTexture(background, game->texture, sfTrue);
    sfSprite_setTexture(cursor, game->texture, sfTrue);
    sfSprite_setTextureRect(background, rect);
    sfSprite_setTextureRect(cursor, rect_curs);
    scroller->background = background;
    scroller->cursor = cursor;
    scroller->text = init_scroll_text();
    return scroller;
}
