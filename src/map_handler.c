/*
** EPITECH PROJECT, 2019
** print map
** File description:
** yes
*/

#include "navy.h"

char **create_map(void)
{
    char **map = malloc(sizeof(char *) * (9));
    int i = 0;
    int j = 0;

    while (j < 8) {
        map[j] = malloc(sizeof(char) * (9));
        for (i = 0; i < 8; i++) {
            map[j][i] = '.';
        }
        map[j][i] = '\0';
        j++;
    }
    map[j] = NULL;
    return (map);
}

void test_char(char test)
{
    if (test == 'o')
        my_printf("\033[32;01mo\033[00m ");
    if (test == 'x')
        my_printf("\033[31;01mx\033[00m ");
    if (test >= '2' && test <= '5')
        my_printf("\033[34;01m%c\033[00m ", test);
    if (test == '.')
        my_printf("%c ", test);
}

void print_colored_maps(char *map)
{
    for (int j = 0; j < 7; j++) {
        test_char(map[j]);
    }
    test_char(map[7]);
}

void print_map(navy_t *seals)
{
    my_printf("\n\033[36;01m my positions:\033[00m\n");
    my_printf("\033[35;01m |A B C D E F G H\033[00m\n");
    my_printf("-+---------------\n");
    for (int i = 0; i < 8; i++) {
        my_printf("%d|", i + 1);
        print_colored_maps(seals->your_map[i]);
        my_putchar('\n');
    }
    my_printf("\n\033[33;01m enemy's positions:\033[00m\n");
    my_printf("\033[35;01m |A B C D E F G H\033[00m\n");
    my_printf("-+---------------\n");
    for (int i = 0; i < 8; i++) {
        my_printf("%d|", i + 1);
        print_colored_maps(seals->ennemi_map[i]);
        my_putchar('\n');
    }
}