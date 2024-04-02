/*
** EPITECH PROJECT, 2024
** Created by loann.picard-blardone@epitech.eu on 2/16/24.
** File description:
** my_realloc.c
*/

#include "../../include/my.h"

void *my_realloc(char *str, int size)
{
    char *new_str = malloc(sizeof(char) * (size + 1));
    int i = 0;

    my_putstr(str);
    my_put_nbr(size);
    if (new_str == NULL)
        return NULL;
    while (str[i] != '\0') {
        new_str[i] = str[i];
        i++;
    }
    free(str);
    return new_str;
}
