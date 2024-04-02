/*
** EPITECH PROJECT, 2024
** Created by loann.picard-blardone@epitech.eu on 3/29/24.
** File description:
** tools.c
*/

#include "my.h"

void erase(char **text, size_t n)
{
    for (size_t j = 0; j < n; ++j) {
        for (int i = 0; text[i]; ++i) {
            text[i] = text[i + 1];
        }
    }
}
