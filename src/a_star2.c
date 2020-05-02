/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** a_star2
*/

#include "lemin.h"

char **new_line(char **b)
{
    int len = 0;
    char **a;

    for (; b[len] != NULL; len++);
    a = malloc(sizeof(char *) * (len + 2));
    for (int d = 0; b[d] != NULL; d++)
        a[d] = b[d];
    a[len] = NULL;
    a[len + 1] = NULL;
    free(b);
    return (a);
}

int test(node_t *tmp)
{
    int a = 0;

    while (tmp != NULL) {
        a++;
        tmp = tmp->parent;
    }
}

void add_algo(algo_t **R, algo_t *new)
{
    algo_t *tmp = *R;

    new->next = NULL;
    if (tmp == NULL)
        *R = new;
    else {
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = new;
    }
}

int found_goal(road_t *D, char *end_node, algo_t **R)
{
    node_t *tmp;
    algo_t *new = malloc(sizeof(algo_t));
    int len = 0;
    char *str;

    if (my_strcmp(D->current_node->name, end_node) == 0) {
        for (; D->b[len] != NULL; len++);
        tmp = D->current_node;
        new->nb_turn = tmp->g;
        new->chemin = my_strdup(tmp->name);
        tmp = tmp->parent;
        while (tmp != NULL) {
            str = my_strcat(tmp->name, ";");
            new->chemin = my_strcat_free(str, new->chemin);
            tmp = tmp->parent;
        }
        add_algo(R, new);
        return (1);
    }
    return (0);
}
