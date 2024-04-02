/*
** EPITECH PROJECT, 2024
** Created by loann.picard-blardone@epitech.eu on 3/29/24.
** File description:
** count_sentences
*/

#include "../../include/my.h"
#include <string.h>

int count_words(const char *str, const char *delimiters)
{
    int nb = 0;
    int in_word = 0;

    for (int i = 0; str[i]; ++i) {
        if (my_strchr(str[i], delimiters)) {
            in_word = 0;
            continue;
        }
        if (!in_word) {
            ++nb;
            in_word = 1;
        }
    }
    return nb;
}
