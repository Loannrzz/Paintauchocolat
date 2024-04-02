/*
** EPITECH PROJECT, 2024
** Created by loann.picard-blardone@epitech.eu on 3/29/24.
** File description:
** my_atoi
*/

#include <stdlib.h>
#include "my.h"

#include <stdlib.h>
#include "my.h"

int my_atoi(const char *str)
{
    int sign = 1;
    int result = 0;
    int digit = 0;

    while (*str && *str == ' ')
        ++str;
    if (*str == '-' || *str == '+') {
        sign = (*str == '-') ? -1 : 1;
        ++str;
    }
    while (*str && my_isdigit(*str)) {
        digit = *str - '0';
        if (result > INT_MAX / 10 ||
            (result == INT_MAX / 10 && digit > INT_MAX % 10))
            return (sign == -1) ? INT_MIN : INT_MAX;
        result = result * 10 + digit;
        ++str;
    }
    result *= sign;
    return result;
}
