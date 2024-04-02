/*
** EPITECH PROJECT, 2023
** Created by loann.picard-blardone@epitech.eu on 14/11/23.
** File description:
** my_strncpy.c
*/

#include "../../include/my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (i < n) {
        dest[i] = src[i];
        if (src[i] == '\0')
            break;
        i++;
    }
    return dest;
}
