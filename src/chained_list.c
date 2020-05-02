/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** chained_list.c
*/

#include "lemin.h"
#include "my.h"

void free_just_struct(array_t **all)
{
    array_t *tmp = *all;
    array_t *tmp1;

    while (tmp != NULL) {
        tmp1 = tmp;
        tmp = tmp->next;
        free(tmp1);
    }
}

node_t *init_all_node_tunnel(args_t args)
{
    node_t *tmp;
    array_t *all = NULL;

    tmp = init(args.start[0]);
    append_l(&all, tmp);
    all = list_arg(args.room, all);
    tmp = init(args.end[0]);
    append_l(&all, tmp);
    chain_list(args.tunel, &all);
    tmp = all->S;
    free_just_struct(&all);
    return (tmp);
}

node_t *find_str(char *str, array_t *all)
{
    array_t *tmp = all;

    if (all != NULL) {
        while (tmp != NULL) {
            if (my_strcmp(tmp->S->name, str) == 0)
                return (tmp->S);
            tmp = tmp->next;
        }
    }
    return (NULL);
}

void chain_list(char ***way, array_t **all)
{
    node_t *one, *two;
    array_t *tmp;

    for (int i = 0; way[i] != NULL; i++) {
        one = find_str(way[i][0], *all);
        two = find_str(way[i][1], *all);
        append_l(&one->tun, two);
        append_l(&two->tun, one);
    }
}