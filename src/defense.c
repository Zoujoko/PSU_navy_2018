/*
** EPITECH PROJECT, 2019
** defense
** File description:
** yes
*/

#include "navy.h"
int game;

void receiver(int signum, siginfo_t *azy, void *bonsoir)
{
    static int i = 0;

    if (signum == SIGUSR1) {
        i++;
    }
    azy = azy;
    bonsoir = bonsoir;
    if (signum == SIGUSR2) {
        game = i;
        i = 0;
    }
}

void testing_attack(navy_t *seals, int letter, int digit)
{
    if (seals->your_map[digit][letter] >= '2'
        && seals->your_map[digit][letter] <= '5') {
        seals->your_map[digit][letter] = 'x';
        seals->your_lives--;
        my_printf(":  hit\n\n");
        usleep(50000);
        kill(seals->ennemi, SIGUSR1);
    }
    else {
        my_printf(":  missed\n\n");
        if (seals->your_map[digit][letter] != 'x')
            seals->your_map[digit][letter] = 'o';
        usleep(50000);
        kill(seals->ennemi, SIGUSR2);
    }
}

void defensing(navy_t *seals)
{
    my_printf("waiting for enemy's attack...\n");
    game = 0;
    seals->attack[0] = receive_attack() + 'A' - 1;
    game = 0;
    seals->attack[1] = receive_attack() + '0';
    seals->attack[2] = '\0';
    my_printf("%s", seals->attack);
    testing_attack(seals, seals->attack[0] - 'A', seals->attack[1] - '0' - 1);
}

int receive_attack(void)
{
    struct sigaction act;

    sigemptyset(&act.sa_mask);
    act.sa_flags = SA_SIGINFO;
    act.sa_sigaction = receiver;
    sigaction(SIGUSR1, &act, NULL);
    sigaction(SIGUSR2, &act, NULL);
    while (1) {
        if (game != 0) {
            return (game);
        }
    }
    return (0);
}
