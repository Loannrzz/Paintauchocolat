/*
** EPITECH PROJECT, 2024
** Created by loann.picard-blardone@epitech.eu on 3/29/24.
** File description:
** my_itoa.c
*/

#include <stdlib.h>
#include "my.h"

char *my_itoa(int num)
{
    int length = 0;
    int temp = num;
    char *str;
    char *digit_char;

    do {
        length++;
        temp /= 10;
    } while (temp != 0);
    str = malloc(length + 1);
    if (!str)
        return NULL;
    str[length] = '\0';
    do {
        length--;
        digit_char = '0' + (num % 10);
        str[length] = digit_char;
    } while (num != 0);
    return str;
}
