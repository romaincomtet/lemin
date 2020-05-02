/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** algo
*/

#include "lemin.h"
#include "my.h"

void get_presence(args_t *args)
{
    int i = 0;

    for (i = 0; args->room[i] != NULL; i++);
    args->pres = malloc(sizeof(int) * (i + 3));
    args->nb_chem = i;
    args->pres[0] = 1;
    for (i = 1; args->room[i] != NULL; i++)
        args->pres[i] = 0;
    args->pres[i] = 0;
    args->pres[i + 1] = '\0';
}

int s_pres(args_t *args, char *str)
{
    int i = 0;

    if (my_strcmp(str, args->start[0]) == 0)
        return (0);
    if (my_strcmp(str, args->end[0]) == 0)
        return (args->nb_chem + 1);
    for (i = 0; args->room[i] != NULL; i++) {
        if (my_strcmp(str, args->room[i][0]) == 0)
            return (i + 1);
    }
}

char ***parth_chem(algo_t *road, args_t *args)
{
    char ***chem;
    int i = 0, j = 0;
    algo_t *tmp = road;

    for (j = 0; tmp != NULL; j++) {
        tmp = tmp->next;
    }
    chem = malloc(sizeof(char **) * (j + 1));
    for (i = 0; road != NULL; i++) {
        chem[i] = str_new_tab1(road->chemin, ';');
        road = road->next;
    }
    args->nb_road = i;
    chem[i] = NULL;
    return (chem);
}

void cond_algo(char ***road, int *room, int j, args_t *args)
{
    if (road[j % args->nb_road][room[j] + 1] == NULL) {
        args->pres[args->nb_chem + 1] = 0;
        room[j] = -1;
        args->stop++;
    }
    else if (args->pres[s_pres(args,
    road[j % args->nb_road][room[j] + 1])] != 1 &&
    road[j % args->nb_road][room[j]] != NULL) {
        if (args->pass != 0)
            my_putchar(' ');
        my_putstr("P");
        my_put_nbr(j + 1);
        my_putchar('-');
        args->pres[s_pres(args, road[j % args->nb_road][room[j]])] = 0;
        room[j]++;
        args->pres[s_pres(args, road[j % args->nb_road][room[j]])] = 1;
        my_putstr(road[j % args->nb_road][room[j]]);
        args->pass++;
    }
}

void algo(args_t *args, char ***road)
{
    int i = 0, *room = malloc(sizeof(int) * (args->ants_nb + 1));

    args->stop = 0;
    get_presence(args);
    my_putstr("#moves");
    for (i = 0; i < args->ants_nb; i++)
        room[i] = 0;
    room[i] = '\0';
    while (args->stop != args->ants_nb) {
        my_putchar('\n');
        args->pass = 0;
        for (int j = 0; j < args->ants_nb; j++) {
            args->pres[args->nb_chem + 1] = 0;
            if (room[j] == -1);
            else
                cond_algo(road, room, j, args);
        }
    }
}