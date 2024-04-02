/*
** EPITECH PROJECT, 2024
** Created by loann.picard-blardone@epitech.eu on 3/29/24.
** File description:
** parsing.c
*/

#include "my.h"

list_t *parsing2(mysh_t *mysh, char *input)
{
    char **command = NULL;
    node_t *node = NULL;
    size_t size = 0;
    char **text = my_str_to_word_array(input, "|", &size);
    list_t *list = new_liked_list();

    for (int i = 0; text[i]; ++i) {
        command = my_str_to_word_array(text[i], " \t\n", &size);
        if (!command || !command[0])
            continue;
        node = list->new (command, size);
        if (entree_valide(mysh, node)) {
            list->add(list, node);
        } else {
            mysh->error = 1;
        }
    }
    return list;
}

void parsing(mysh_t *mysh, char *input)
{
    list_t *list = NULL;
    size_t size = 0;
    char **commands = my_str_to_word_array(input, ";", &size);
    int i = 0;

    mysh->commands = new_heap(size);
    while (commands[i]) {
        list = parsing2(mysh, commands[i]);
        mysh->commands.add(&mysh->commands, list);
        i++;
    }
}
