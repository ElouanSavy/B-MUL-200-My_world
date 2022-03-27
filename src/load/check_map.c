/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-elouan.savy-camaret
** File description:
** check_map
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include "my_world.h"
#include "my.h"

int check_char(char c)
{
    if (c == '\0' || c == ' ' || c == '\n' || (c >= '0' && c <= '9'))
        return 0;
    return 84;
}

int check_map_content(char *buffer)
{
    int nb_newline = 0;
    int nb_space = 0;
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (check_char(buffer[i]) == 84) {
            return 84;
        }
        if (buffer[i] == '\n')
            nb_newline++;
    }
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == ' ')
            nb_space++;
    }
    if (nb_newline != 40 || nb_space != 1600) {
        return 84;
    }
    return 0;
}

int check_map(char *path)
{
    char *full_path = malloc(sizeof(char) * (12 + my_strlen(path) + 1));
    my_strcpy(full_path, "assets/save/");
    my_strcat(full_path, path);
    full_path[12 + my_strlen(path)] = '\0';
    FILE *file = fopen(full_path, "r");
    size_t len = 10000;
    size_t chr = 1;
    char *buffer = malloc(sizeof(char) * 10000);
    size_t size = fread(buffer, chr, len, file);
    buffer[size] = '\0';
    int check = check_map_content(buffer);
    free(buffer);
    return check;
}