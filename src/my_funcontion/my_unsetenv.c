///*
//** EPITECH PROJECT, 2024
//** Created by loann.picard-blardone@epitech.eu on 2/29/24.
//** File description:
//** my_unsetenv.c
//*/
//
//#include "../../include/my.h"
//
//int is_alpha_str(char *str)
//{
//    int i = 0;
//
//    while (str[i] != '\0') {
//        if ((str[i] < 'A' || str[i] > 'Z') && (str[i] < 'a' || str[i] > 'z'))
//            return 0;
//        i++;
//    }
//    return 1;
//}
//
//void list_to_tab(t_shell *my_shell)
//{
//    t_env *tmp = my_shell->env;
//    int i = 0;
//    int list_size = 0;
//
//    while (tmp != NULL) {
//        list_size++;
//        tmp = tmp->next;
//    }
//    my_shell->env_tab = malloc(sizeof(char *) * (list_size + 1));
//    if (my_shell->env_tab == NULL) {
//        return;
//    }
//    tmp = my_shell->env;
//    while (tmp != NULL) {
//        my_shell->env_tab[i] = my_strcat(tmp->name, "=");
//        my_shell->env_tab[i] = my_strcat(my_shell->env_tab[i], tmp->value);
//        tmp = tmp->next;
//        i++;
//    }
//    my_shell->env_tab[i] = NULL;
//}
//
//static void remove_element(t_shell *my_shell, t_env *prev, t_env *tmp)
//{
//    if (prev == NULL)
//        my_shell->env = tmp->next;
//    else
//        prev->next = tmp->next;
//    free(tmp->name);
//    free(tmp->value);
//    free(tmp);
//    list_to_tab(my_shell);
//}
//
//void my_unsetenv_remove_list(
//    char **commande, t_shell *shell, t_env *tmp, t_env *prev)
//{
//    while (tmp != NULL) {
//        if (my_strncmp(tmp->name, commande[1], my_strlen(commande[1])) == 0) {
//            remove_element(shell, prev, tmp);
//            return;
//        }
//        prev = tmp;
//        tmp = tmp->next;
//    }
//}
//
//void my_unsetenv(char **commande, char **env, t_shell *my_shell)
//{
//    t_env *tmp = my_shell->env;
//    t_env *prev = NULL;
//
//    if (commande[1] == NULL) {
//        my_putstr_error("unsetenv: Too few arguments.\n");
//        exit(commande[0] == NULL ? 0 : 1);
//        return;
//    }
//    if (is_alpha_str(commande[1]) == 0) {
//        my_putstr_error("setenv: Variable name must begin with a letter.\n");
//        exit(84);
//        return;
//    }
//    my_unsetenv_remove_list(commande, my_shell, tmp, prev);
//}
