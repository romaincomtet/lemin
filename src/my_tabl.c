/*
** EPITECH PROJECT, 2020
** my_tabl.c
** File description:
** my_tabl
*/

#include"../include/my.h"
#include"../include/lemin.h"

int my_count_letter1(char const *str, int n, char s)
{
    while (str[n] != s && str[n] != '\0' && str[n] != '\n') {
        n += 1;
    }
    n += 1;
    return (n);
}

int my_count_world1(char const *str, char s)
{
    int n = 1;

    for (int i = 0 ; str[i] != '\0' && str[n] != '\n' ; i++) {
        if (str[i] == s)
            n += 1;
    }
    return (n);
}

char **str_maloc_tab1(char **dest, char *str, char s)
{
    int nb_worl = my_count_world1(str, s);
    int count_lett = 0;


    for (int j = 0 ; j < nb_worl ; j++) {
        count_lett = my_count_letter1(str, count_lett, s);
        dest[j] = malloc(sizeof(char) * count_lett);
    }
    return (dest);
}

char **str_new_tab1(char *str, char s)
{
    int nb_worl = my_count_world1(str, s);
    char **dest = malloc(sizeof(char *) * (nb_worl + 1));
    int count_lett = 0;
    int i = 0;
    int n = 0;
    int j = 0;

    dest = str_maloc_tab1(dest, str, s);
    for (; j != nb_worl ; j++) {
        while (str[n] != s && str[n] != '\0' && str[n] != '\n') {
            dest[j][i] = str[n];
            i++;
            n++;
        }
        n += 1;
        dest[j][i] = '\0';
        i = 0;
    }
    dest[j] = NULL;
    return (dest);
}