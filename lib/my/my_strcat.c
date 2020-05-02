/*
** EPITECH PROJECT, 2019
** my_strcat.c
** File description:
** my_strcat
*/

#include <stdlib.h>
#include "my.h"

char *my_strcat(char *dest, char *src)
{
    int size1 = my_strlen(dest);
    int size2 = my_strlen(src);
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
    return (final);
}