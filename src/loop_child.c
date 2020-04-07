/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** loop_child.c
*/

#include "../../include/lemin.h"

int is_child_in2(road_t *D, array_t *tmp)
{
    int a = 0;

    while (tmp != NULL) {
        if (my_strcmp(D->children->S->name, tmp->S->name) == 0 &&
        D->children->S->g < tmp->S->g) {
            pop_l(&D->closed_list, a);
            return (0);
        }
        if (my_strcmp(D->children->S->name, tmp->S->name) == 0) {
            return (1);
        }
        tmp = tmp->next;
        a++;
    }
    return (0);
}

int is_child_in(road_t *D, array_t *tmp)
{
    int a = 0;

    while (tmp != NULL) {
        if (my_strcmp(D->children->S->name, tmp->S->name) == 0) {
            return (1);
        }
        tmp = tmp->next;
        a++;
    }
    return (0);
}

int loop_child2(road_t *D, node_t *end_node)
{
    D->children->S->g = D->current_node->g + 1;
    if (is_child_in2(D, D->open_list) == 0) {
        append_l(&D->open_list, D->children->S);
        return (0);
    }
    else
        return (1);
}

void loop_child(road_t *D, node_t *end_node)
{
    int a = 0;
    array_t *tmp;

    while (D->children != NULL) {
        if (a == 1)
            free_structure(tmp);
        a = 0;
        if (is_child_in(D, D->closed_list) == 0) {
            a = loop_child2(D, end_node);
        }
        else
            a = 1;
        tmp = D->children;
        D->children = D->children->next;
    }
    if (a == 1)
        free_structure(tmp);
}