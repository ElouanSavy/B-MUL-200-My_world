/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-elouan.savy-camaret
** File description:
** main
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Time.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

#include "my_world.h"
#include "my.h"

void check_gs(game_t *game)
{
    switch (game->state) {
    case GS_MENU:
        menu_loop(game);
        break;
    case GS_PLAY:
        game_loop(game);
        break;
    case GS_LOAD:
        load_loop(game);
    default:
        break;
    }
}

int check_display(char **env)
{
    for (int i = 0; env[i]; i++) {
        if (my_strncmp(env[i], "DISPLAY", 7) == 0)
            return 0;
    }
    return 84;
}

int check_ressources(void)
{
    if (open("assets/fonts/Oswald-Medium.ttf", O_RDONLY) == -1)
        return 84;
    if (open("assets/hash/hash.txt", O_RDONLY) == -1)
        return 84;
    if (open("assets/musics/hit_sound.ogg", O_RDONLY) == -1)
        return 84;
    if (opendir("assets/save") == NULL)
        return 84;
    if (open("assets/sprite/sheet.png", O_RDONLY) == -1)
        return 84;
    if (open("assets/maps/map_flat.txt", O_RDONLY) == -1)
        return 84;
    if (open("assets/sprite/icon.png", O_RDONLY) == -1)
        return 84;
    return 0;
}

game_t *init_game(game_t *game)
{
    sfVideoMode mode = {1920, 1080, 32};
    if (check_ressources() == 84)
        return NULL;
    game->save_path = NULL;
    game->window = create_window(mode, "my_world");
    game->state = GS_MENU;
    game->cursor = create_cursor();
    game->texture = sfTexture_createFromFile("assets/sprite/sheet.png", NULL);
    game->menu = init_menu(game);
    game->bg_color = sfColor_fromRGB(2, 43, 58);
    game->tools = init_game_tools(game);
    game->tools->scroller = init_scroller(game);
    game->tracked = 0;
    game->musics = init_game_musics();
    game->offset = (sfVector2i) {0, 0};
    game->load = init_load(game);
    game->zoom = 0;
    return (game);
}

int main(int argc, char **argv, char **env)
{
    game_t *game = malloc(sizeof(game_t));

    if (!env[0] || check_display(env) == 84)
        return (84);
    if (argc > 1 && !my_strcmp(argv[1], "-h")) {
        display_usage();
        return (0);
    }
    game = init_game(game);
    if (game == NULL)
        return (84);
    sfRenderWindow_setFramerateLimit(game->window, 60);
    window_icon(game);
    while (sfRenderWindow_isOpen(game->window))
        check_gs(game);
    free_all_ressources(game);
    return (0);
}
