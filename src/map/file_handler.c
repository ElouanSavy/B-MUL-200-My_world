/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-elouan.savy-camaret
** File description:
** file_handler
*/

#include <stdlib.h>
#include <stdio.h>

#include "my_world.h"
#include "my.h"

char *get_path(game_t *game)
{
    char *filename = get_random_name(game);
    int size = my_strlen(filename);
    char *path = malloc(sizeof(char) * (size + 13));
    my_strcpy(path, "assets/save/");
    my_strcat(path, filename);
    free(filename);
    return (path);
}

int save_file(game_t *game, char *path)
{
    FILE *file = fopen(path, "w+");
    int **map = game->map->map_3d;
    char *tmp = NULL;
    for (int i = 0; i < 40; i++) {
        for (int j = 0; j < 40; j++) {
            tmp = nb_to_str(map[i][j]);
            fwrite(tmp, 1, my_strlen(tmp), file);
            free(tmp);
            fwrite(" ", 1, 1, file);
        }
        fwrite("\n", 1, 1, file);
    }
    game->save_path = path;
    fclose(file);
    return (0);
}
