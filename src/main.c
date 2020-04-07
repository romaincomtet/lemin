/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include"my.h"
#include"lemin.h"

void test(void);

int main(int ac, char **av)
{
    args_t args;
    node_t *tmp;
    array_t *all = NULL;
    
    recover_all(&args);
    tmp = init(args.start[0]);
    append_l(&all, tmp);
    all = list_arg(args.room, all);
    tmp = init(args.end[0]);
    append_l(&all, tmp);
    chain_list(args.tunel, args.start[0], all);
    return (0);
}