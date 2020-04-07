/*
** EPITECH PROJECT, 2020
** recover_room.c
** File description:
** recover_room
*/

#include"../include/my.h"
#include"../include/lemin.h"

char ***recov_room(char **dest, char ***room, int n)
{
    if (n == 3) {
        check_is_nb(dest[1]);
        check_is_nb(dest[2]);
        room = text_malloc_env(room, dest);
        my_putstr(dest[0]);
        my_putstr(" ");
        my_putstr(dest[1]);
        my_putstr(" ");
        my_putstr(dest[2]);
        my_putstr("\n");
    }
    return (room);
}

char ***recov_tunel(char **dest, char ***tunel, int i)
{
    int n = 0;
    static int s = 0;

    if (i == 1) {
        dest = str_new_tab1(dest[0], '-');
        while (dest[n] != NULL)
            n++;
        if (n == 2) {
            if (s == 0)
                my_putstr("#tunnels\n");
            tunel = text_malloc_env(tunel, dest);
            my_putstr(dest[0]);
            my_putstr("-");
            my_putstr(dest[1]);
            my_putstr("\n");
            s = 1;
        }
    }
    return (tunel);
}