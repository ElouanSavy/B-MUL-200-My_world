/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-elouan.savy-camaret
** File description:
** init_load
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Time.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include "my_world.h"

to_load_t *free_map_list(game_t *game)
{
    to_load_t *list = game->load->map_list;
    to_load_t *save = NULL;
    while (list != NULL) {
        save = list;
        list = list->next;
        sfSprite_destroy(save->bg);
        sfText_destroy(save->text);
        free(save);
    }
    game->load->map_list = NULL;
    return (NULL);
}

to_load_t *init_to_load(game_t *game)
{
    DIR* directory = NULL;
    directory = opendir("assets/save/");
    to_load_t *list = NULL;
    struct dirent *dirent;

    while ((dirent = readdir(directory)) != NULL) {
        if (dirent->d_name[0] == '.' || check_map(dirent->d_name) == 84)
            continue;
        list = add_to_map_list(dirent->d_name, list, game);
    }
    return (list);
}

sfSprite *create_sprite(game_t *game, sfIntRect rect, int x, int y)
{
    sfSprite *sprite;
    sfVector2f pos = {x, y};
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, game->texture, sfTrue);
    sfSprite_setTextureRect(sprite, rect);
    sfSprite_setPosition(sprite, pos);
    return (sprite);
}

load_t *init_load(game_t *game)
{
    sfIntRect rect = {6788, 1356, 680, 805};
    load_t *load = malloc(sizeof(load_t));
    load->container = create_sprite(game, rect, 620, 69);
    rect.left = 7468;
    rect.width = 297;
    rect.height = 92;
    load->btn_back = create_sprite(game, rect, 620, 921);
    rect.left = 7765;
    load->btn_load = create_sprite(game, rect, 1003, 921);
    load->map_list = NULL;
    load->tmp = NULL;
    return (load);
}
