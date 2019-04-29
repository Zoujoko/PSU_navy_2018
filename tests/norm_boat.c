/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** norm_boat
*/

#include <criterion/criterion.h>
#include "navy.h"
int boat_norm(int *info);
int *search_info(char *boat);

Test(info_test, pos1)
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
        cr_assert(boat_norm(info) == 0);
    }
    close(fd);
}

Test(info_test, pos2)
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
        cr_assert(boat_norm(info) == 0);
    }
    close(fd);
}