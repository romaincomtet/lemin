/*
** EPITECH PROJECT, 2019
** nodeer
** File description:
** main.c
*/

#include "lemin.h"

node_t *init_node_a_star(node_t *node, node_t *parent)
{
    node_t *new = malloc(sizeof(node_t));

    new->parent = parent;
    new->name = node->name;
    new->g = node->g;
    new->tun = node->tun;
    return (new);
}

void find_new_square(road_t *D)
{
    array_t *tmp = D->current_node->tun;

    while (tmp != NULL)
    {
        append_l(&D->children, init_node_a_star(tmp->S, D->current_node));
        tmp = tmp->next;
    }
}

algo_t *algo_start(road_t *D, node_t *start, char *end, algo_t *R)
{
    append_l(&D->open_list, start);
    while (strlen_l(D->open_list) > 0) {
        get_the_current_node(D);
        pop_l(&D->open_list, D->current_index);
        append_l(&D->closed_list, D->current_node);
        if (found_goal(D, end, &R) != 1) {
            find_new_square(D);
            loop_child(D, start->name, end);
        }
    }
    return (R);
}

void init_road(road_t *r)
{
    r->children = NULL;
    r->open_list = NULL;
    r->closed_list = NULL;
    r->b = malloc(sizeof(char *) * 1);
    r->b[0] = NULL;
}

algo_t *a_star(node_t *start, char *end)
{
    road_t D;
    algo_t *R = NULL;
    int d = 0;
    algo_t *tmp;

    init_road(&D);
    R = algo_start(&D, start, end, R);
    tmp = R;
    return (R);
}