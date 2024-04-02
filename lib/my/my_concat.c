/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-minishell2-loann.picard-blardone
** File description:
** my_concat
*/

#include <stdarg.h>
#include <stdlib.h>

int concat_len(int count, va_list ap)
{
    int len = 0;
    char *str = 0;

    for (int i = 0; i < count; i++) {
        str = va_arg(ap, char *);
        if (str) {
            len += my_strlen(str);
        }
    }

    return len;
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
    c = result = malloc(sizeof(char) * (len + 1));
    result[len] = '\0';
    va_start(ap, count);
    for (int i = 0; i < count; i++) {
        if (!(str = va_arg(ap, char *))) {
            continue;
        }
        while (*str != '\0') {
            *c = *str;
            c = c + 1;
            str = str + 1;
        }
    }
    va_end(ap);
    return (result);
}
