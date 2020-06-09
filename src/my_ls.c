/*
** EPITECH PROJECT, 2020
** ls
** File description:
** ls
*/
#include "my.h"
#include "my_ls.h"

void ls_d(void)
{
    my_putstr(".");
    my_putstr("\n");
}

void type(void)
{
    struct dirent *dirent;
    DIR *dir = opendir(".");

    while ((dirent = readdir(dir)) != NULL) {
        if (dirent->d_name[0] != '.') {
            my_putstr(dirent->d_name);
            if (dirent->d_type == 8)
                my_putstr("*");
            if (dirent->d_type == 4)
                my_putstr("/");
            my_putstr("\n");
        }
    }
    closedir(dir);
}

int open_files(char *av)
{
    struct dirent *dirent;
    DIR *dir = opendir(av);

    if (opendir(av) == NULL)
        return (84);
    while ((dirent = readdir(dir)) != NULL) {
        if (dirent->d_name[0] != '.') {
            my_putstr(dirent->d_name);
            my_putstr("\n");
        }
    }
    closedir(dir);
    return (0);
}

void my_ls(void)
{
    struct dirent *dirent;
    DIR *dir = opendir(".");

    while ((dirent = readdir(dir)) != NULL) {
        if (dirent->d_name[0] != '.') {
            my_putstr(dirent->d_name);
            my_putstr("\n");
        }
    }
    closedir(dir);
}