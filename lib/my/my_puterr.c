/*
** EPITECH PROJECT, 2023
** my
** File description:
** my_puterr
*/

#include "../../include/my.h"

void my_puterr(const char *str)
{
    write(2, str, my_strlen(str));
}
