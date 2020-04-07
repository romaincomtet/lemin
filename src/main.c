/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

<<<<<<< HEAD
#include "my.h"
#include "lemin.h"
=======
#include"my.h"
#include"lemin.h"
>>>>>>> 9ad2b2f84268778d1c118a9c2e7277d38c979476

int main(int ac, char **av)
{
    args_t args;
    node_t *tmp;
<<<<<<< HEAD
    
=======
    array_t *all = NULL;

>>>>>>> 9ad2b2f84268778d1c118a9c2e7277d38c979476
    recover_all(&args);
    tmp = init_all_node_tunnel(args);
    
    return (0);
}