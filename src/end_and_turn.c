/*
** EPITECH PROJECT, 2019
** check end
** File description:
** yes
*/

#include "navy.h"

int turn_p1(navy_t *seals)
{
    if (attacking(seals) == -1)
        return (-1);
    defensing(seals);
    return (0);
}

int turn_p2(navy_t *seals)
{
    defensing(seals);
    if (attacking(seals) == -1)
        return (-1);
    return (0);
}

int whos_playing(navy_t *seals)
{
    if (seals->player == 1)
        if (turn_p1(seals) == -1)
            return (-1);
    if (seals->player == 2)
        if (turn_p2(seals) == -1)
            return (-1);
    print_map(seals);
    return (0);
}

void attack_inyours(navy_t *seals, int letter ,int digit, char add)
{
    if (seals->player == 2)
        seals->your_map[digit][letter] = add;
    if (seals->player == 1)
        seals->your_map[digit][letter] = add;
}

int check_end(navy_t *seals)
{
    if (seals->your_lives != 0 && seals->ennemi_lives != 0) {
        my_putchar('\n');
        return (0);
    }
    if (seals->your_lives == 0) {
        my_printf("\nEnemy won\n");
        return (1);
    }
    if (seals->ennemi_lives == 0) {
        my_printf("\nI won\n");
        return (0);
    }
    return (0);
}