/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** chained_list.c
*/

#include "chain_list.h"
#include "lemin.h"
#include "my.h"

node_t *init(char *name)
{
    node_t *node = malloc(sizeof(node_t));

    if (node == NULL)
        exit_error;
    node->name = name;
    node->parent = NULL;
    node->g = 0;
    node->tun = NULL;
    return node;
}

array_t *list_arg(char ***arg, array_t *tmp)
{
    node_t *tmp1;

    for (int i = 0; arg[i] != NULL; i++) {
        tmp1 = init(arg[i][0]);
        append_l(&tmp, tmp1);
    }
    return (tmp);
}

void add(node_t *start, char *name)
{
    array_t *new = malloc(sizeof(array_t));
    node_t *new_node = malloc(sizeof(node_t));
    array_t *tmp = start->tun;

    if (start == NULL || new == NULL || new_node == NULL)
        exit_error;
    new_node = init(name);
    new->S = new_node;
    new->next = NULL;
    if (tmp == NULL)
        start->tun = new;
    else {
        while (tmp != NULL) {
            tmp = tmp->next;
        }
        tmp = new;
    }
}

void print_list(array_t *start)
{
    array_t *actual = malloc(sizeof(array_t));

    if (start == NULL)
        exit_error;
    actual = start;
    while (actual != NULL) {
        printf("%s -> ", actual->S->name);
        actual = actual->next;
    }
    printf("NULL\n");
}

void chain_list(char ***way, char *first, array_t *all)
{
    char *one, *two;
    node_t *start = init(first);

    print_list(all);
    for (int i = 0; way[i] != NULL; i++) {
        one = way[i][0];
        two = way[i][1];
        if (my_strcmp(first, two) == 0)
            add(start, one);
        if (my_strcmp(first, one) == 0)
            add(start, two);
    }
}