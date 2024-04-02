/*
** EPITECH PROJECT, 2023
** Created by loann.picard-blardone@epitech.eu on 17/11/23.
** File description:
** my_strcat.c
*/

#include "../../include/my.h"

char *my_strcat(char *dest, const char *src)
{
    int i = 0;
    int j = 0;

    while (dest[i] != '\0') {
        i++;
    }
    while (src[j] != '\0') {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return dest;
}
