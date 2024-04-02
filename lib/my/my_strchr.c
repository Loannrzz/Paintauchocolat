/*
** EPITECH PROJECT, 2024
** Created by loann.picard-blardone@epitech.eu on 3/29/24.
** File description:
** my_strchr
*/

#include "../../include/my.h"

int my_strchr(const char c, const char *delimiters)
{
    if (c == '\0')
        return (0);
    for (int k = 0; delimiters[k]; ++k)
        if (delimiters[k] == c)
            return (1);
    return (0);
}
