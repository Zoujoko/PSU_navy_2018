/*
** EPITECH PROJECT, 2019
** navy main
** File description:
** yes
*/
#include "navy.h"
int game;

void for_pid(int signum, siginfo_t *azy, void *bonsoir)
{
    game = azy->si_pid;
    signum = signum;
    bonsoir = bonsoir;
    my_printf("\nenemy connected\n");
}

navy_t *receive_signal(char *file)
{
    navy_t *seals = malloc(sizeof(navy_t));
    struct sigaction act;

    if (seals == NULL)
        return (NULL);
    seals->you = getpid();
    seals->your_map = create_map();
    seals->ennemi_map = create_map();
    if (read_file(file, seals) == 84)
        return (NULL);
    sigemptyset(&act.sa_mask);
    act.sa_flags = SA_SIGINFO;
    act.sa_sigaction = for_pid;
    seals->player = 1;
    sigaction(SIGUSR2, &act, NULL);
    my_printf("my_pid:  %d\n", seals->you);
    my_printf("waiting for enemy connection...\n");
    pause();
    seals->ennemi = game;
    return (seals);
}

navy_t *sending_signal(int pid_p1, char *file)
{
    navy_t *seals = malloc(sizeof(navy_t));

    if (seals == NULL)
        return (NULL);
    seals->you = getpid();
    seals->your_map = create_map();
    seals->ennemi_map = create_map();
    seals->ennemi = pid_p1;
    if (read_file(file, seals) == 84)
        return (NULL);
    seals->player = 2;
    seals->your_lives = 14;
    seals->ennemi_lives = 14;
    my_printf("my_pid: %d\n", seals->you);
    if (kill(pid_p1, SIGUSR2) == -1)
        return (NULL);
    my_printf("successfully connected\n");
    return (seals);
}

int for_the_navy(navy_t *seals)
{
    print_map(seals);
    while (seals->your_lives > 0 && seals->ennemi_lives > 0) {
        if (whos_playing(seals) == -1)
            return (check_end(seals));
    }
    return (check_end(seals));
}

int main(int argc, char **argv)
{
    navy_t *seals;

    print_usage(argv[1]);
    if (argc == 2 && my_strcmp(argv[1], "-h" ) != 0) {
        if ((seals = receive_signal(argv[1])) == NULL)
            return (84);
    }
    else if (argc == 3) {
        if ((seals = sending_signal(my_getnbr(argv[1]), argv[2])) == NULL)
            return (84);
    }
    else {
        my_put_error("Wrong usage mate use the -h to understand how it");
        my_put_error(" works\n");
        return (84);
    }
    seals->your_lives = 14;
    seals->ennemi_lives = 14;
    return (for_the_navy(seals));
}
