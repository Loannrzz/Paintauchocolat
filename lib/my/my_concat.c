/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-minishell2-loann.picard-blardone
** File description:
** my_concat
*/

#include "my.h"
#include <stdarg.h>
#include <stdlib.h>

int concat_len(int count, va_list ap)
{
    int len = 0;
    char *str = 0;

    for (int i = 0; i < count; i++){
        str = va_arg(ap, char *);
        if (str){
            len += my_strlen(str);
        }
    }
    return (len);
}

void my_concat_loop(int count, va_list ap, char *c, char *str)
{
    for (int i = 0; i < count; i++) {
        str = va_arg(ap, char *);
        if (!str)
            continue;
        while (*str) {
            *c = *str;
            *c++;
            *str++;
        }
    }
}

char *my_concat(int count, ...)
{
    va_list ap;
    int len = 0;
    char *result = 0;
    char *c = 0;
    char *str = 0;

    va_start(ap, count);
    len = concat_len(count, ap);
    va_end(ap);
    result = malloc(sizeof(char) * (len + 1));
    result[len] = '\0';
    c = result;
    va_start(ap, count);
    my_concat_loop(count, ap, c, str);
    va_end(ap);
    return (result);
}
