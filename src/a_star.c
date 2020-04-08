/*
** EPITECH PROJECT, 2019
** nodeer
** File description:
** main.c
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
int found_goal(road_t *D, char *end_node)
{
    node_t *tmp;
    int len = 0;

    if (my_strcmp(D->current_node->name, end_node) == 0) {
        for (; D->b[len] != NULL; len++);
        tmp = D->current_node;
        D->b = new_line(D->b);
        D->b[len] = my_strcat_free(my_itoa(tmp->g), ";");
        while (tmp != NULL) {
            D->b[len] = my_strcat_free(D->b[len], tmp->name);
            D->b[len] = my_strcat_free(D->b[len], ";");
            tmp = tmp->parent;
        }
        return (1);
    }
    return (0);
}

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

int algo_start(road_t *D, node_t *start, char *end)
{
    append_l(&D->open_list, start);
    while (strlen_l(D->open_list) > 0) {
        get_the_current_node(D);
        pop_l(&D->open_list, D->current_index);
        append_l(&D->closed_list, D->current_node);
        if (found_goal(D, end) != 1) {
            find_new_square(D);
            loop_child(D, start->name, end);
        }
    }
    return (0);
}

void init_road(road_t *r)
{
    r->children = NULL;
    r->open_list = NULL;
    r->closed_list = NULL;
    r->b = malloc(sizeof(char *) * 1);
    r->b[0] = NULL;
}

char **a_star(node_t *start, char *end)
{
    road_t D;
    int d = 0;

    init_road(&D);
    algo_start(&D, start, end);
    for (int i = 0; D.b[i] != NULL; i++) {
        printf("%s\n", D.b[i]);
    }
    return (D.b);
}