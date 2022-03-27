/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-elouan.savy-camaret
** File description:
** display_usage
*/

#include "my.h"

int display_usage(void)
{
    my_printf("USAGE:\n\n\t./my_world\n\n");
    my_printf("DESCRIPTION:\n\n\tThis game is a generator for world.");
    my_printf(" It allow you to terraform the world with tools.\n\n");
    my_printf("SHORTCUT:\n\n\t- Z\tzoom on map\n\t- S\tdezoom on map\n");
    my_printf("\t- Space\tsave the map\n\t- Arrows\t navigate on map\n\n");
    return (0);
}
