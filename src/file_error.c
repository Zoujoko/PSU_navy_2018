/*
** EPITECH PROJECT, 2019
** file errror
** File description:
** yes
*/

#include "navy.h"

char boat_rightleft(int *info, char side)
{
    if (side == 'V' && ((info[4] + info[0] - 1) == info[2]))
        return ('V');
    else if (side == 'H' && ((info[3] + info[0] - 1) == info[1]))
        return ('H');
    else
        return ('W');
}

char boat_leftright(int *info, char side)
{
    if (side == 'V' && ((info[2] + info[0] - 1) == info[4]))
        return ('V');
    else if (side == 'H' && ((info[1] + info[0] - 1) == info[3]))
        return ('H');
    else
        return (boat_rightleft(info, side));
}

char find_side(int *info)
{
    char side;

    if (info[1] == info[3])
        side = 'V';
    else if (info[2] == info[4])
        side = 'H';
    else
        side = 'W';
    side = boat_leftright(info, side);
    return (side);
}