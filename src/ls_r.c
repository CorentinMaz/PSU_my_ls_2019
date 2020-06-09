/*
** EPITECH PROJECT, 2020
** ls_r
** File description:
** ls_r
*/

#include "my.h"
#include "my_ls.h"

int files(char *str)
{
    DIR *dir = opendir(str);
    struct dirent *dirent = readdir(dir);

    if (opendir(str) == NULL)
        return (84);
    while ((dirent = readdir(dir)) != NULL) {
        if (dirent->d_name[0] != '.') {
            my_putstr(dirent->d_name);
            my_putstr("\n");
        }
    }
    my_putstr("\n");
    closedir(dir);
    return (0);
}

void ls_maj(struct dirent *dirent)
{
    if (dirent->d_name[0] == '.') {
        my_putstr(dirent->d_name);
        my_putstr(":\n");
        open_files(dirent->d_name);
        my_putstr("\n");
    } else if (dirent->d_name[0] != '.' && dirent->d_type == 4) {
        my_putstr(dirent->d_name);
        my_putstr(":\n");
        files(dirent->d_name);
    }
}

int ls_maj_r(char *av)
{
    struct stat fstat;
    DIR *dir = opendir(av);
    struct dirent *dirent = readdir(dir);
    char *str = my_strcat(av, dirent->d_name);

    if (dir == NULL)
        return (84);
    stat(str, &fstat);
    while ((dirent = readdir(dir)) != NULL) {
        stat(str, &fstat);
        if (dirent->d_name[1] != '.' && dirent->d_name[1] != 'g')
            ls_maj(dirent);
    }
    closedir(dir);
    return (0);
}