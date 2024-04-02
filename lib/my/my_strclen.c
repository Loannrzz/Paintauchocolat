/*
** EPITECH PROJECT, 2024
** Created by loann.picard-blardone@epitech.eu on 3/29/24.
** File description:
** my_strclen
*/

#include "../../include/my.h"

int my_strclen(const char *str, const char *delimiters)
{
    int k = 0;

    while (str[k] && !my_strchr(str[k], delimiters)) {
        k++;
    }
    return k;
}
