/*
** EPITECH PROJECT, 2023
** Created by loann.picard-blardone@epitech.eu on 15/11/23.
** File description:
** my_strdup.c
*/

#include "../../include/my.h"

int my_strlen_2(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}

char *my_strdup(char const *src)
{
    int a = 0;
    size_t l = my_strlen_2(src);
    char *str = malloc(sizeof(char) * (l + 1));

    while (src[a] != '\0') {
        str[a] = src[a];
        a++;
    }
    str[a] = '\0';
    return str;
}
