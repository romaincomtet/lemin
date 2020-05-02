/*
** EPITECH PROJECT, 2020
** newline_tab.c
** File description:
** newline_tab
*/

#include "my.h"
#include "lemin.h"

void print_start_end(char **dest)
{
    my_putstr(dest[0]);
    my_putstr(" ");
    my_putstr(dest[1]);
    my_putstr(" ");
    my_putstr(dest[2]);
    my_putstr("\n");
    return;
}

int count_lin1_env(char ***env)
{
    int n = 0;

    for (int i = 0 ; env[i] != NULL ; i++) {
        n += 1;
    }
    n += 1;
    return (n);
}

char ***text_malloc_env(char ***env, char **nest)
{
    int nb_lin = count_lin1_env(env);
    char ***dest = malloc(sizeof(char **) * (nb_lin + 1));
    int j = 0;

    for (j = 0 ; env[j] != NULL ; j++) {
        dest[j] = env[j];
    }
    dest[j] = nest;
    dest[j + 1] = NULL;
    free(env);
    return (dest);
}