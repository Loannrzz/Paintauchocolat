/*
** EPITECH PROJECT, 2023
** Created by loann.picard-blardone@epitech.eu on 10/11/23.
** File description:
** my_get_nbr.c
*/

#include "../../include/my.h"

static void check_minus(int min_cnt, long *number)
{
    if (min_cnt % 2 == 1) {
        *number = *number * (-1);
    }
}

static bool is_digit(char to_test)
{
    if (to_test >= '0' && to_test <= '9') {
        return true;
    }
    return false;
}

static long on_num(int num_strt, char const *str)
{
    int len = 0;
    int result = 0;
    int mult = 1;

    for (int i = num_strt; str[i] >= 48 && str[i] < 58; i++) {
        len++;
    }
    if (len > 10) {
        return result;
    }
    for (int n = num_strt + len - 1; n >= num_strt; n--) {
        result += (str[n] - 48) * mult;
        mult = mult * 10;
    }
    return result;
}

static void chck_int(long *number)
{
    if (*number > 2147483647 || *number < -2147483648) {
        *number = 0;
    }
}

long my_getnbr(char const *str)
{
    long number;
    int min_cnt = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (is_digit(str[i])) {
            number = on_num(i, str);
            check_minus(min_cnt, &number);
            chck_int(&number);
            return number;
        }
        if (str[i] == 45) {
            min_cnt++;
        }
    }
    return (long) number;
}
