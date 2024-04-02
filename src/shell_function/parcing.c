/*
** EPITECH PROJECT, 2024
** Created by loann.picard-blardone@epitech.eu on 3/24/24.
** File description:
** parcing.c
*/

#include "../../include/my.h"

list_t *parcing_2(myshell_t *my_shell, char *input)
{
    size_t k = 0;
    list_t *list = create_new_list();
    node_t *node = NULL;
    char **command = NULL;
    char **text = my_str_to_word_array(input, "|", &k);

    printf("Text: %s\n", text[0]);
    for (int i = 0; text[i]; i++) {
        printf("Je suis dans le for %d\n", i);
        command = my_str_to_word_array(text[i], " \t\n", &k);
        printf("je suis un tes de la alallala  1\n");
        if (!command || !command[0])
            continue;
        printf("je suis un tes de la alallala 2\n");
        node = list->new (command, k);
        printf("je suis un tes de la alallala 3\n");
        if (check(my_shell, node)) {
            printf("je suis un tes de la alallala 4\n");
            list->add(list, node);
        } else {
            printf("je suis un tes de la alallala 5\n");
            my_shell->error = 1;
        }
    }
    return list;
}

void parcing(myshell_t *my_shell, char *input)
{
    size_t k = 0;
    list_t *list = NULL;
    char **commands = my_str_to_word_array(input, ";", &k);
    for (int i = 0; commands[i]; ++i) {
        printf("Command %d: %s\n", i, commands[i]);
    }

    printf("Commands parsed\n");

    my_shell->commands = new_command(my_shell);
    my_shell->commands.size = 0;
    for (int i = 0; commands[i]; ++i) {
        printf("je suis un tes de merde saolodijfbcs\n");
        list = parcing_2(my_shell, commands[i]);
        printf("\n\nTexte de debug\n");
        my_shell->commands.add(&my_shell->commands, list);
    }
    printf("Commands added\n");
}