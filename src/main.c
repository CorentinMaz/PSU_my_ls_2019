/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "my.h"
#include "my_ls.h"

int next_main(int ac, char **av)
{
    if (av[1][0] == '-' && av[1][1] == 'R' && av[1][2] == '\0') {
        if (ac > 2) {
            for (int i = 2; i < ac; i++)
                ls_maj_r(av[i]);
        } else
            ls_maj_r(".");
        return (0);
    }
    if (av[1][0] == '-') {
        my_printf("my_ls: invalid option -- '%c'", av[1][1]);
        my_printf("\nTry « ./my_ls --help » for more information.\n");
        return (84);
    }
    else if (open_files(av[1]) == 84) {
        my_printf("my_ls: cannot access '%s': No such file or directory\n",
            av[1]);
        return (84);
    }
    return (0);
}

int continue_main(int ac, char **av)
{
    if (av[1][0] == '-' && av[1][1] == 'F' && av[1][2] == '\0') {
        type();
        return (0);
    }
    if (av[1][0] == '-' && av[1][1] == 'd' && av[1][2] == '\0') {
        ls_d();
        return (0);
    }
    if (next_main(ac, av) == 0)
        return (0);
    else
        return (2);
    return (0);
}

int error_ls_l(char **av, int i)
{
    if (ls_l(av[i]) == 0)
        return (0);
    else {
        my_printf("my_ls: cannot access '%s': No such file or directory\n",
            av[2]);
        return (84);
    }
}

int main(int ac, char **av)
{
    if (ac == 1) {
        my_ls();
        return (0);
    }
    if (ac > 1 && av[1][0] == '-' && av[1][1] == 'l' && av[1][2] == '\0') {
        if (ac > 2) {
            for (int i = 2; i < ac; i++)
                error_ls_l(av, i);
        } else
            ls_l(".");
        return (0);
    }
    if (continue_main(ac, av) == 0)
        return (0);
    else
        return (2);
    return (0);
}