/*
** EPITECH PROJECT, 2023
** my
** File description:
** my_str_isnum
*/

#include <stdlib.h>
#include "my.h"

int nb_replace(char *str, char *to_find, int to_findlen)
{
    int nb_replace = 0;
    char *ptr = str;

    ptr = my_strstr(ptr, to_find);
    for (; ptr != NULL;) {
        ptr = my_strstr(ptr, to_find);
        ptr += to_findlen;
        ++nb_replace;
    }
    return (nb_replace);
}

int my_str_replace2(int a, char *replace, char *result)
{
    for (int k = 0; replace[k]; ++k) {
        ++a;
        result[a] = replace[k];
    }
    return a;
}

char *my_str_replace(char *input, char *replace, char *to_find)
{
    int inputlen = my_strlen(input);
    int replacelen = my_strlen(replace);
    int to_findlen = my_strlen(to_find);
    int resultlen = inputlen
        + (replacelen - to_findlen) * nb_replace(input, to_find, to_findlen);
    char *result = malloc(sizeof(char) * (resultlen + 1));
    int n = 0;

    result[resultlen] = '\0';
    for (int a = 0; n < inputlen; a++) {
        if (my_strncmp(input + n, to_find, to_findlen)) {
            n++;
            result[a] = input[n];
            continue;
        }
        a = my_str_replace2(a, replace, result);
        n += to_findlen;
    }
    return (result);
}
