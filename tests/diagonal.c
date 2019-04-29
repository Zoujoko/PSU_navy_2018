/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** diagonal
*/

#include <criterion/criterion.h>
#include "navy.h"
int *search_info(char *boat);

Test(Diagonal, pos1)
{
    int size = 8;
    char buffer[size];
    int *info;
    int rd = 3;
    int fd = open("pos1", O_RDONLY);

    while ((rd = read(fd, buffer, size)) > 0) {
        if (rd < size)
            buffer[rd] = '\0';
        info = search_info(buffer);
        cr_assert(info != NULL);
        cr_assert(find_side(info) != 'W');
    }
    close(fd);
}

Test(Diagonal, pos2)
{
    int size = 8;
    char buffer[size];
    int *info;
    int rd = 3;
    int fd = open("pos2", O_RDONLY);

    while ((rd = read(fd, buffer, size)) > 0) {
        if (rd < size)
            buffer[rd] = '\0';
        info = search_info(buffer);
        cr_assert(info != NULL);
        cr_assert(find_side(info) != 'W');
    }
    close(fd);
}