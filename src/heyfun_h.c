/*
** EPITECH PROJECT, 2019
** heyfun h
** File description:
** yes
*/

#include "navy.h"

void print_usage(char *heyfun)
{
    if (my_strcmp(heyfun, "-h") == 0) {
        my_printf("USAGE\n");
        my_printf("./navy [first_player_pid] navy_positions\n");
        my_printf("DESCRIPTION\n");
        my_printf("first_player_pid: only for the 2nd player. pid of the ");
        my_printf("first player.\n");
        my_printf("navy_positions: file representing the positions of ");
        my_printf("the ships.\n");
    }
}
