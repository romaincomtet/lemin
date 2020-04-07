/*
** EPITECH PROJECT, 2019
** nodeer
** File description:
** main.c
*/

#include "lemin.h"

char **new_line(char **a, int len, char **b)
{
    for (; b[len] != NULL; len++);
    a = malloc(sizeof(char) * len + 2);
    for (int d = 0; b[d] != NULL; d++)
        a[d] = b[d];
    a[len] = NULL;
    a[len + 1] = NULL;
    free(b);
    return (a); 
}

int found_goal(road_t *D, node_t *end_node)
{
    node_t *tmp;
    int len = 0;
    char **a;

    for (; D->b[len] != NULL; len++);
    if (my_strcmp(D->current_node->name, end_node->name) == 0) {
        tmp = D->current_node;
        D->b = new_line(a, len, D->b);
        a[len] = my_strcat_free(my_itoa(tmp->g), ";");
        while (tmp != NULL) {
            a[len] = my_strcat_free(a[len], tmp->name);
            a[len] = my_strcat_free(a[len], ";");
            tmp = tmp->parent;
        }
        free_node(end_node);
        return (1);
    }
    return (0);
}

void find_new_square(road_t *D)
{
    array_t *tmp = D->current_node->road;
    
    while (tmp != NULL)
    {
        append_l(&D->children, init_node(D->current_node));
        tmp = tmp->next;
    }
}

int algo_start(road_t *D, array_t *n, node_t *start, node_t *end)
{
    D->b = NULL;
    append_l(&D->open_list, start);
    while (strlen_l(D->open_list) > 0) {
        get_the_current_node(D);
        pop_l(&D->open_list, D->current_index);
        append_l(&D->closed_list, D->current_node);
        if (found_goal(D, end) == 1)
            continue;
        find_new_square(D);
        loop_child(D, end);
    }
    free_node(end);
    return (0);
}

char **a_star(array_t *all_node, node_t *start, char *end)
{
    road_t D;
    int d = 0;

    algo_start(&D, all_node, start, end);
    return (D.b);
}