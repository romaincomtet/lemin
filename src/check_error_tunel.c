/*
** EPITECH PROJECT, 2019
** check_error_tunel.c
** File description:
** check_error_tunel.c
*/

#include "my.h"
#include "lemin.h"

int check_with_name_room(args_t *a, char *str)
{
    int i = 0;

    for (; a->room[i] != NULL; i++) {
        if (check_word(a->room[i][0], str) == 0)
            return (0);
        if (check_word(a->start[0], str) == 0)
            return (0);
        if (check_word(a->end[0], str) == 0)
            return (0);
    }
    exit_error;
}

int check_tunnel_name(args_t *a)
{
    int i = 0;
    int j = 0;

    for (; a->tunel[i] != NULL; i++) {
        for (j = 0; a->tunel[i][j] != NULL; j++) {
            check_with_name_room(a, a->tunel[i][j]);
        }
    }
    return (0);
}