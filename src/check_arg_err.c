/*
** EPITECH PROJECT, 2020
** check_arg_err.c
** File description:
** check_arg_err
*/

#include"../include/my.h"
#include"../include/lemin.h"

int check_is_nb(char *str)
{
    for (int i = 0 ; str[i] != '\0'; i++)
        if (str[i] < '0' || str[i] > '9')
            exit_error;
    return (0);
}

int check_comment(char **dest)
{
    int n = 0;
    int a = 0;

    for (int i = 0 ; dest[i] != NULL ; i++) {
        if (dest[i][0] == '#' || dest[i][0] == ' ')
            n += 1;
    }
    while (dest[a] != NULL)
            a++;
    a = a - n;
    return (a);
}