/*
** EPITECH PROJECT, 2019
** file handling
** File description:
** yes
*/

#include "navy.h"

int check_lenght(int len, int when, int test)
{
    static int i = 0;

    if (when == 1 && (i != 14))
        return (-1);
    else if (when == 1 && (i == 14))
        return (0);
    else {
        if (when == 2 && test == 14)
            return (1);
        else if (when == 2 && test != 14)
            return (-1);
    }
    i += len;
    return (0);
}

int boat_norm(int *info)
{
    if (info[0] < 1 || info[0] > 5)
        return (-1);
    for (int i = 1; i <= 4; i++)
        if (info[i] > 8 || info[i] < 0)
            return (-1);
    if (check_lenght(info[0], 0, 0) == -1)
        return (-1);
    if (info[1] != info[3] && info[2] != info[4])
        return (-1);
    return (0);
}

int *search_info(char *boat)
{
    int *info = malloc(sizeof(int) * (5));

    if (boat[7] != '\n' && boat[7] != '\0')
        return (NULL);
    info[0] = boat[0] - '0';
    info[1] = boat[2] - 'A';
    info[2] = boat[3] - '0' - 1;
    info[3] = boat[5] - 'A';
    info[4] = boat[6] - '0' - 1;
    return (info);
}

int adding_boat(char *boat, navy_t *seals)
{
    int *info = search_info(boat);
    char side = find_side(info);

    if (side == 'W' || info == NULL || boat_norm(info) == -1) {
        my_put_error("Your Boats are not normed you can't enter there sorry\n");
        return (84);
    }
    for (int i = info[2], j = info[1], k = 0; k != info[0]; k++) {
        seals->your_map[i][j] = boat[0];
        if (side == 'V')
            i++;
        if (side == 'H')
            j++;
    }
    free(info);
    return (0);
}

int read_file(char *file, navy_t *seals)
{
    int fd = open(file, O_RDONLY);
    int size = 8;
    char buffer[size];
    int rd = 6;
    int rows = 1;

    if (fd == -1 || fd == 0)
        return (84);
    while ((rd = read(fd, buffer, size)) > 0) {
        if (rd < size)
            buffer[rd] = '\0';
        if ((buffer[7] != '\n' && rd == 8) || adding_boat(buffer, seals) == 84)
            return (84);
        rows++;
    }
    if (rows != 5 || check_lenght(0, 1, 0) == -1)
        return (84);
    return (0);
}
