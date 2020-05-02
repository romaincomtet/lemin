/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "my.h"
#include "lemin.h"

int main(int ac, char **av)
{
    algo_t *road;
    args_t args;
    node_t *tmp;
    char ***chem;

    recover_all(&args);
    tmp = init_all_node_tunnel(args);
    road = a_star(tmp, args.end[0]);
    chem = parth_chem(road, &args);
    algo(&args, chem);
    return (0);
}