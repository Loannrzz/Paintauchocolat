/*
** EPITECH PROJECT, 2024
** Created by loann.picard-blardone@epitech.eu on 3/29/24.
** File description:
** my_strccpy
*/

#include "../../include/my.h"

char *my_strccpy(const char *str, const char *delimiters)
{
    int len = my_strclen(str, delimiters);
    char *cpy = malloc(sizeof(char) * len + 1);

    cpy[len] = '\0';
    for (int i = 0; i < len; ++i)
        cpy[i] = str[i];
    return (cpy);
}
