/*
** EPITECH PROJECT, 2024
** Created by loann.picard-blardone@epitech.eu on 3/29/24.
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    int k = 0;

    if (!str)
        return (0);
    while (str[k])
        ++k;
    return k;
}
