/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-elouan.savy-camaret
** File description:
** offset_update
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Time.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "my_world.h"
#include "my.h"

char *int_to_char(int nb)
{
    char *result = malloc(sizeof(char) * 20);
    int i = 0;
    if (nb < 0) {
        result[i] = '-';
        nb = nb * -1;
        i++;
    }
    int deci = 1;
    if (nb == 0)
        result[0] = '0';
    while (deci <= nb)
        deci = deci * 10;
    while (deci / 10 >= 1) {
        deci = deci / 10;
        result[i] = ((nb / deci) + 48);
        nb = nb % deci;
        i++;
    }
    result[i] = '\0';
    return (result);
}

void update_text(game_t *game)
{
    scroller_t *scroll = game->tools->scroller;
    int offset = game->cursor->offset;
    sfVector2f pos = sfSprite_getPosition(scroll->cursor);
    if (offset == 10) {
        sfText_setPosition(scroll->text, (sfVector2f) {pos.x - 3, 14});
        sfText_setScale(scroll->text, (sfVector2f) {0.6, 0.6});
    } else {
        sfText_setPosition(scroll->text, (sfVector2f) {pos.x + 1, 12});
        sfText_setScale(scroll->text, (sfVector2f) {0.7, 0.7});
    }
    sfText_setString(scroll->text, int_to_char(offset));
    return;
}

void update_offset(game_t *game)
{
    sfSprite *cursor = game->tools->scroller->cursor;
    float pos_x = sfSprite_getPosition(cursor).x;
    int offset = 0;
    pos_x = pos_x - 435;
    offset = round((pos_x * 9 / 234) + 1);
    game->cursor->offset = offset;
    return;
}
