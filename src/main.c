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
    args_t args;
    node_t *tmp;
    
    recover_all(&args);
    tmp = init_all_node_tunnel(args);
    a_star(tmp, args.end[0]);
    return (0);
}