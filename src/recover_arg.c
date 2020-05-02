/*
** EPITECH PROJECT, 2020
** check_cmd.c
** File description:
** check_cmd
*/

#include "my.h"
#include "lemin.h"

void recov_end(int e, char **dest, args_t *arg)
{
    char *str = NULL;
    size_t l = 0;
    int i = 0;
    int d = 0;

    if (getline(&str, &l, stdin) != -1) {
        str = clean_str(str);
        dest = str_new_tab1(str, ' ');
    }
    if (check_comment(dest) == 3) {
        check_is_nb(dest[1]);
        check_is_nb(dest[2]);
        my_putstr("##end\n");
        print_start_end(dest);
        arg->end = dest;
        arg->ed += 1;
    }
}

void recov_start(int e, char **dest, args_t *arg)
{
    char *str = NULL;
    size_t l = 0;
    int d = 0;

    if (getline(&str, &l, stdin) != -1) {
        str = clean_str(str);
        dest = str_new_tab1(str, ' ');
    }
    if (check_comment(dest) == 3) {
        check_is_nb(dest[1]);
        check_is_nb(dest[2]);
        my_putstr("##start\n");
        print_start_end(dest);
        arg->start = dest;
        arg->sta += 1;
    }
}

void recover_ant(char **dest, int n, args_t *arg)
{
    static int i = 0;
    int d = 0;

    if (i == 0 && n == 1 && check_is_nb(dest[0]) == 0) {
        check_is_nb(dest[0]);
        d = my_getnbr(dest[0]);
        my_putstr("#number_of_ants\n");
        my_put_nbr(d);
        my_putstr("\n#rooms\n");
        arg->ants_nb = d;
        i += 1;
    }
}

void check_condi(args_t *arg, char **dest, char *str, int nb)
{
    str = my_strdup(str);
    str = clean_str(str);
    dest = str_new_tab1(str, ' ');
    nb = check_comment(dest);
    recover_ant(dest, nb, arg), arg;
    if (my_strcmp(dest[0], "##start") == 0)
        recov_start(nb, dest, arg);
    if (my_strcmp(dest[0], "##end") == 0)
        recov_end(nb, dest, arg);
    arg->room = recov_room(dest, arg->room, nb);
    arg->tunel = recov_tunel(dest, arg->tunel, nb);
    return;
}

void recover_all(args_t *arg)
{
    char *str = NULL;
    char **dest = NULL;
    size_t l = 0;
    arg->room = malloc(sizeof(char **) * 1);
    arg->tunel = malloc(sizeof(char **) * 1);
    arg->sta = 0;
    arg->ed = 0;

    arg->room[0] = NULL;
    arg->tunel[0] = NULL;
    for (int n = 0; getline(&str, &l, stdin) != -1;)
        check_condi(arg, dest, str, n);
    if (arg->sta != 1 || arg->ed != 1)
        exit_error;
    check_name_ex(arg);
    return;
}