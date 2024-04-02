///*
//** EPITECH PROJECT, 2024
//** Created by loann.picard-blardone@epitech.eu on 2/29/24.
//** File description:
//** my_cd.c
//*/
//
//#include "../../include/my.h"
//
//static char *get_env_home(t_shell *my_shell)
//{
//    t_env *current = my_shell->env;
//
//    while (current != NULL) {
//        if (my_strcmp(current->name, "HOME") == 0)
//            return current->value;
//        current = current->next;
//    }
//    return NULL;
//}
//
//void my_cd(char **commande, char **env, t_shell *my_shell)
//{
//    char *path;
//
//    if (commande[1] != NULL) {
//        path = commande[1];
//    } else {
//        path = get_env_home(my_shell);
//        if (path == NULL) {
//            my_putstr_error("cd: No home directory.\n");
//            return;
//        }
//    }
//    if (chdir(path) == -1) {
//        perror(path);
//    }
//}
