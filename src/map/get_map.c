/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-elouan.savy-camaret
** File description:
** get_map
*/

#include <stdio.h>
#include <sys/types.h>
#include "my_world.h"
#include "my.h"

map_t *parse_line(char *str, int line, map_t *map_info)
{
    char **parsed_line = my_str_to_word_array(str);
    int i = 0;
    int tmp = 0;

    map_info->map_3d[line] = malloc(sizeof(int) * 41);
    while (parsed_line[i] != NULL) {
        tmp = my_getnbr(parsed_line[i]);
        map_info->map_3d[line][i] = tmp;
        i += 1;
    }
    return (map_info);
}

map_t *get_map(filepath path)
{
    FILE *file = fopen(path, "r");
    map_t *map_info = malloc(sizeof(map_t));
    map_info->map_3d = malloc(sizeof(int *) * 40);
    char *buffer = malloc(sizeof(char) * 300);
    size_t size = 300;

    if (file == NULL)
        return (NULL);
    map_info->size.x = 40;
    map_info->size.y = 40;
    for (int i = 0; i < 40; i++) {
        getline(&buffer, &size, file);
        map_info = parse_line(buffer, i, map_info);
    }
    fclose(file);
    free(buffer);
    return (map_info);
}

map_t *init_map(filepath path)
{
    map_t *map = get_map(path);
    if (map == NULL)
        return (NULL);
    map = create_2d_map(map);
    return (map);
}
