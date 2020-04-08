/*
** EPITECH PROJECT, 2019
** lemin_2019
** File description:
** my_strcat_free.c
*/

#include <stdlib.h>

int my_strlenb(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}

char *my_strcat_free(char *dest, char const *src)
{
    int size1 = my_strlenb(dest);
    int size2 = my_strlenb(src);
    char *final = malloc(sizeof(char *) * size1 + size2 + 1);
    int j = 0;
    int k = 0;

    for (int i = 0; dest[i] != '\0'; i++, k++)
        final[k] = dest[i];
    while (src[j] != '\0') {
        final[k] = src[j];
        j++;
        k++;
    }
    final[k] = '\0';
    free(dest);
    return (final);
}