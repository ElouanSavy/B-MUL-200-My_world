/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-elouan.savy-camaret
** File description:
** map_list_manager
*/

#include <stdlib.h>
#include "my_world.h"

game_t *check_map_collision(game_t *game, sfMouseButtonEvent mouse)
{
    to_load_t *list = game->load->map_list;
    sfIntRect rect = {0};
    sfIntRect base = {6144, 2017, 622, 91};
    game->load->tmp = NULL;
    while (list != NULL) {
        sfSprite_setTextureRect(list->bg, base);
        if (check_collision(mouse.x, mouse.y, list->bg)) {
            rect = sfSprite_getTextureRect(list->bg);
            rect.top = 2108;
            sfSprite_setTextureRect(list->bg, rect);
            game->load->tmp = list;
        }
        list = list->next;
    }
    return (game);
}

sfText *create_text(char *name, int y)
{
    sfFont *font = sfFont_createFromFile("assets/fonts/Oswald-Medium.ttf");
    sfText *text = sfText_create();
    sfFloatRect rect = {0};
    sfVector2f pos = {0, y};
    sfText_setString(text, name);
    sfText_setFont(text, font);
    sfText_setColor(text, sfColor_fromRGB(255, 229, 242));
    sfText_setCharacterSize(text, 48);
    rect = sfText_getGlobalBounds(text);
    pos.x = 960 - (rect.width / 2);
    sfText_setPosition(text, pos);
    return (text);
}

to_load_t *add_to_map_list(char *name, to_load_t *list, game_t *game)
{
    sfIntRect rect = {6144, 2017, 622, 91};
    sfVector2f pos = {649, 101};
    to_load_t *element = malloc(sizeof(to_load_t));
    element->name = name;
    element->next = list;
    element->bg = sfSprite_create();
    sfSprite_setTexture(element->bg, game->texture, sfTrue);
    sfSprite_setTextureRect(element->bg, rect);
    if (list != NULL) {
        pos = sfSprite_getPosition(list->bg);
        pos.y += 107;
    }
    sfSprite_setPosition(element->bg, pos);
    element->text = create_text(name, pos.y + 16);
    list = element;
    return (list);
}
