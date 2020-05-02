/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** chained_list2
*/

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