/*
** EPITECH PROJECT, 2024
** Created by loann.picard-blardone@epitech.eu on 3/24/24.
** File description:
** process_input.c
*/

#include "../../include/my.h"
#include <unistd.h>

#define BUFFER_SIZE 1024

int process_input(myshell_t *my_shell)
{
    char buffer[BUFFER_SIZE];
    int bytes_read;
    int y = 0;

    while (1) {
        if (isatty(0))
            my_putstr("[Change par le nom de l'AER qui passe ta review] ~> ");
        bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE - 1);
        if (bytes_read <= 0) {
            printf("read failed\n");
            return 1;
        }
        buffer[bytes_read] = '\0';
        printf("Calling parcing...\n");
        parcing(my_shell, buffer);
        printf("Parcing done\n");
        for (; y < my_shell->commands.size; y++)
            execute(my_shell, my_shell->commands.array[y]);
        y = 0;
    }
    return 0;
}