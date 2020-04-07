/*
** EPITECH PROJECT, 2019
** print_all.c
** File description:
** print_all.c
*/

#include"../include/my.h"
#include"../include/lemin.h"

int check_tab(char **ta)
{
    int size = 0;

    for (; ta[size] != NULL; size++);
    if (size == 3)
        return  (0);
    else
        return (84);
    return (0);
}

int check_word(char *str, char *str1)
{
    int i = 0;
    int size = my_strlen(str);
    int cpt = 0;

    while (str[i] != '\0') {
        if (str[i] == str1[i])
            cpt++;
        i++;
    }
    if (cpt == size)
        return (0);
    else
        return (84);
}

int check_name_ex(args_t *a)
{
    int i = 0;

    if (check_word(a->start[0], a->end[0]) == 0)
        exit_error;
    for (; a->room[i] != NULL; i++) {
        if (check_word(a->start[0], a->room[i][0]) == 0)
            exit_error;
        if (check_word(a->end[0], a->room[i][0]) == 0)
            exit_error;
    }
}

int check_coord(args_t *a)
{
    int i = 0;

    if ((a->start[1][0] == a->end[1][0]) && (a->start[2][0] == a->end[2][0]))
        exit_error;
    for (; a->room[i] != NULL; i++) {
        if ((a->start[1][0] == a->room[i][1][0]) &&
            (a->start[2][0] == a->room[i][2][0]))
            exit_error;
        if ((a->end[1][0] == a->room[i][1][0]) &&
            (a->end[2][0] == a->room[i][2][0]))
            exit_error;
    }
    return (0);
}