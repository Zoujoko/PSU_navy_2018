/*
** EPITECH PROJECT, 2019
** attack
** File description:
** yes
*/

#include "navy.h"
int game;

void answering(int signum, siginfo_t *azy, void *bonsoir)
{
    if (signum == SIGUSR1) {
        my_printf(" hit\n\n");
        game = 2;
    }
    if (signum == SIGUSR2) {
        my_printf(" missed\n\n");
        game = 1;
    }
    azy = azy;
    bonsoir = bonsoir;
}

void answer(navy_t *seals)
{
    struct sigaction act;
    int letter = seals->attack[0] - 'A';
    int digit = seals->attack[1] - '0' - 1;

    sigemptyset(&act.sa_mask);
    act.sa_flags = SA_SIGINFO;
    act.sa_sigaction = answering;
    sigaction(SIGUSR1, &act, NULL);
    sigaction(SIGUSR2, &act, NULL);
    game = 0;
    pause();
    if (game == 1 && seals->ennemi_map[digit][letter] != 'x')
        seals->ennemi_map[digit][letter] = 'o';
    if (game == 2) {
        seals->ennemi_map[digit][letter] = 'x';
        seals->ennemi_lives--;
    }
}

int send_attack(navy_t *seals, char *attack)
{
    int letter = attack[0] - 'A' + 1;
    int number = attack[1] - '0';

    for (int i = 0; i <= letter - 1; i++) {
        game = 1;
        kill(seals->ennemi, SIGUSR1);
        usleep(500);
    }
    kill(seals->ennemi, SIGUSR2);
    usleep(5000);
    for (int i = 0; i <= number - 1; i++) {
        game = 1;
        kill(seals->ennemi, SIGUSR1);
        usleep(500);
    }
    kill(seals->ennemi, SIGUSR2);
    usleep(5000);
    return (0);
}

int error_attack(navy_t *seals)
{
    int end = 0;

    while (1) {
        end = 0;
        if (read(0, seals->attack, 4096) <= 0)
            return (-1);
        if (seals->attack[0] >= 'A' && seals->attack[0] <= 'H')
            end++;
        if (seals->attack[1] >= '1' && seals->attack[1] <= '8')
            end++;
        if (end == 2 && seals->attack[2] == '\n') {
            seals->attack[2] = '\0';
            return (1);
        }
        else {
            my_printf("\e[0mwrong position\n");
            my_printf("attack:  ");
            my_printf("\e[3m");
        }
    }
    return (0);
}

int attacking(navy_t *seals)
{
    my_printf("attack:  ");
    my_printf("\e[3m");
    if (error_attack(seals) == -1)
        return (-1);
    my_printf("\e[0m%s: ", seals->attack);
    send_attack(seals, seals->attack);
    answer(seals);
    return (0);
}