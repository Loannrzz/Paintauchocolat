/*
** EPITECH PROJECT, 2024
** Created by loann.picard-blardone@epitech.eu on 3/29/24.
** File description:
** my_str_isalpha
*/

#include "my.h"

int my_str_isalpha(const char *str)
{
    for (int i = 0; str[i]; ++i) {
        if (!my_isalpha(str[i]) && !my_isdigit(str[i]) && str[i] != '_')
            return (0);
    }
    return (1);
}
