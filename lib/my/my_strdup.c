/*
** EPITECH PROJECT, 2019
** lib
** File description:
** my_strdup
*/

#include <stdlib.h>

char *my_strdup(char const *src)
{
    char *str;
    int len = 0;
    int i = 0;

    if (src == NULL)
        return (NULL);
    for (; src[len] != '\0'; len++);
    str = malloc(sizeof(char) * (len + 1));
    while (i < len)
    {
        str[i] = src[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}