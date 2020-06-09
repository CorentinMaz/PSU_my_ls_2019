/*
** EPITECH PROJECT, 2020
** str_two_word_array
** File description:
** str_two_word_array
*/

#include "my.h"
#include "minishell.h"

int nb_charact(var_t var, int i)
{
    int curs = 0;

    while (var.str[i] != '\0') {
        if (var.str[i] == ':')
            return (curs);
        curs++;
        i++;
    }
    var.str[i] = '\0';
    return (curs);
}

int nb_line(var_t var)
{
    int i = 0;
    int curs = 0;

    while (var.str[i] != '\0') {
        if (var.str[i] == ':')
            curs++;
        i++;
    }
    var.str[i] = '\0';
    return (curs + 1);
}

char **str_two_word_array(var_t var)
{
    int j = 0;
    int x = 5;
    int i = 0;

    var.path_to_array = malloc(sizeof(char * ) * (nb_line(var) + 1));
    for (; j < nb_line(var); x++, j++) {
        var.path_to_array[j] = malloc(sizeof(char) * (nb_charact(var, x) + 4));
        for (i = 0; var.str[x] != ':' && var.str[x] != '\0'; i++, x++)
            var.path_to_array[j][i] = var.str[x];
        var.path_to_array[j][i] = '/';
        var.path_to_array[j][i + 1] = '\0';
    }
    var.path_to_array[j] = NULL;
    return (var.path_to_array);
}