/*
** EPITECH PROJECT, 2019
** crit
** File description:
** crit
*/

#include <criterion/criterion.h>
#include "navy.h"
int check_lenght(int len, int when, int test);

Test(Boat_lenght, right_one)
{
    cr_assert(check_lenght(0, 2, 14) == 1);
    cr_assert(check_lenght(0, 2, 12) == -1);
    cr_assert(check_lenght(0, 2, 15) == -1);
    cr_assert(check_lenght(0, 2, 0) == -1);
}

Test(read_file, test)
{
    navy_t *seals = malloc(sizeof(navy_t));

    seals->your_map = create_map();
    seals->ennemi_map = create_map();
    cr_assert(read_file("pos1", seals) == 0);
    cr_assert(read_file("don'texist", seals) == 84);
}

Test(read_file, test_pos2)
{
    navy_t *seals = malloc(sizeof(navy_t));

    seals->your_map = create_map();
    seals->ennemi_map = create_map();
    cr_assert(read_file("pos2", seals) == 0);
    cr_assert(read_file("Makefile", seals) == 84);
}
