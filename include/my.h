/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** yes
*/
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#pragma once

//Transform a string to an int
int my_getnbr(char const *str);
//Display on the standard output the character passed as parameter
void my_putchar(char c);
//Display the integer passed as parameter
int my_put_nbr(int nb);
//Display the string passed as parameter
int my_putstr(char const *str);
//Reverse the string passed as parameter
char *my_revstr(char *str);
//Concatenate two string
char *my_strcat(char *dest, char const *src);
//Copy the second string into the first one
char my_strcpy(char *dest, char const *src);
//Return the amount of character until \0 in the string passed as param
int my_strlen(char const *str);
//put the number passed as paramter in hexadecimal base
int my_put_nbr_hexa_x(int nb);
unsigned int negative_x(int nb);
int my_put_nbr_x(unsigned int nb);
//put the number passed as paramter in hexadecimal base
int my_put_nbr_hexa_x_caps(int nb);
int my_put_nbr_x_caps(unsigned int nb);
unsigned int negative_x_caps(int nb);
//put the number passed as paramter in octal base
int my_put_nbr_octal(int nb);
int my_put_nbr_o(unsigned int nb);
unsigned int negative_o(int nb);
int my_put_nbr_unsigned(int nb);
unsigned int negative_u(int nb);
int my_put_nbr_u(unsigned int nb);
int my_put_nbr_b(unsigned int nb);
unsigned int negative_b(int nb);
int my_put_nbr_bin(int nb);
int my_put_pointer(int nb);
int nintendo_switch(char flag, va_list param);
int nintendo_switch2(char flag, va_list param);
int nintendo_switch3(char flag, va_list param);
//My Printf use it like the printf in stdio.h
int my_printf(char *str, ...);
int put_zero(unsigned int octal);
void my_put_s_caps(char const *str);
int my_put_nbr_caps_s(int nb);
//duplicate the string passed as parameter and return a pointer to ti
char *my_strdup(char *str);
//my putstr on the standart error output
void my_put_error(char const *str);
//Transform a char * into a char ** with delim as delimeter between word
char **my_str_to_word_array(char *str, char delim);
//Compare the n first string of each string and return 0 is they are the same
int my_strncmp(char const *str1, char const *str2, int n);
//Compare the two string passed as parameter and return 0 is they are the same
int my_strcmp(char const *str1, char const *str2);
