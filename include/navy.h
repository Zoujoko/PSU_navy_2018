/*
** EPITECH PROJECT, 2019
** navy function
** File description:
** yes
*/

#ifndef NAVY_H_
#define NAVY_H_
#include "my.h"
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
extern int game;

typedef struct navy_s{
    char **your_map;
    char **ennemi_map;
    int you;
    int ennemi;
    char attack[3];
    int player;
    int your_lives;
    int ennemi_lives;
}               navy_t;

//map handling
char **create_map(void);
void print_map(navy_t *seals);

//file handling
int read_file(char *file, navy_t *seals);

//defense
void receiver(int signum, siginfo_t *azy, void *bonsoir);
void testing_attack(navy_t *seals, int letter, int digit);
void defensing(navy_t *seals);
int receive_attack(void);

//attack
void answering(int signum, siginfo_t *azy, void *bonsoir);
void answer(navy_t *seals);
int send_attack(navy_t *seals, char *attack);
int attacking(navy_t *seals);

//-h
void print_usage(char *heyfun);

//file error
char find_side(int *info);

//check end return
int check_end(navy_t *seals);

//whos playing
int whos_playing(navy_t *seals);
int turn_p1(navy_t *seals);
int turn_p2(navy_t *seals);
void attack_inyours(navy_t *seals, int letter ,int digit, char add);
#endif /* !NAVY_H_ */
