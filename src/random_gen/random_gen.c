/*
** EPITECH PROJECT, 2022
** PERLIN
** File description:
** random_gen
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "my_world.h"
#include "my.h"

int *get_hash(void)
{
    FILE *file = fopen("assets/hash/hash.txt", "r");
    char *buffer = malloc(sizeof(char) * 10000);
    int *hash = malloc(sizeof(int) * 256);
    char **char_hash = NULL;
    size_t len = 10000;
    size_t chr = 1;
    size_t size = fread(buffer, chr, len, file);
    buffer[size] = '\0';
    char_hash = my_str_to_word_array(buffer);
    for (int i = 0; i < 256; i++)
        hash[i] = my_getnbr(char_hash[i]);
    free(buffer);
    fclose(file);
    return hash;
}

int **random_gen(game_t *game)
{
    int *hash = get_hash();
    srand(sfClock_getElapsedTime(game->menu->planet_clock).microseconds);
    int seed = rand();
    int **map = malloc(sizeof(int *) * 40);
    for (int i = 0; i < 40; i++) {
        map[i] = malloc(sizeof(int) * 40);
    }
    for (int x = 0; x < 40; x++) {
        for (int y = 0; y < 40; y++) {
            map[x][y] = (int) round(my_perlin(x, y, seed, hash) * 40) % 40 + 4;
        }
    }
    return map;
}

map_t *get_rand_map(game_t *game)
{
    map_t *map_info = malloc(sizeof(map_t));

    map_info->size.x = 40;
    map_info->size.y = 40;
    map_info->map_3d = random_gen(game);
    return (map_info);
}

map_t *init_rand_map(game_t *game)
{
    map_t *map = get_rand_map(game);
    if (map == NULL)
        return (NULL);
    map = create_2d_map(map);
    return (map);
}
