/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** create_list.c
*/

#include "lemin.h"

void append_l(array_t **D, node_t *L)
{
    array_t *tmp = *D;
    array_t *new = malloc(sizeof(array_t));

    new->S = L;
    new->next = NULL;
    if (tmp == NULL)
        *D = new;
    else {
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = new;
    }
}

int strlen_l(array_t *D)
{
    array_t *tmp = D;
    int a = 0;

    if (tmp == NULL)
        return (a);
    else {
        while (tmp->next != NULL) {
            tmp = tmp->next;
            a++;
        }
        return (a + 1);
    }
}

void pop_l(array_t **D, int index)
{
    array_t *tmp = *D;
    array_t *tmp2 = tmp;

    if (tmp != NULL && index == 0)
        *D = tmp->next;
    if (tmp != NULL) {
        for (int i = 0; i < index; i++) {
            tmp2 = tmp;
            tmp = tmp->next;
        }
        if (tmp->next != NULL)
            tmp2->next = tmp->next;
        else
            tmp2->next = NULL;
        free(tmp);
    }
}

void get_the_current_node(road_t *D)
{
    array_t *tmp = D->open_list;

    if (tmp == NULL)
        return;
    else {
        D->current_node = tmp->S;
        D->current_index = 0;
    }
}

node_t *init_node(node_t *parent)
{
    node_t *S = malloc(sizeof(node_t));

    S->parent = NULL;
    if (parent != NULL)
        S->parent = parent;
    S->g = 0;
    return (S);
}