/*
** EPITECH PROJECT, 2023
** my
** File description:
** my_putstr
*/

#include "../../include/my.h"

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}
