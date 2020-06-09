/*
** EPITECH PROJECT, 2020
** git
** File description:
** gid
*/
#include "my.h"
#include "my_ls.h"

int total(struct stat fstat, char *av)
{
    int i = 0;
    struct dirent *dirent;
    DIR *dir = opendir(av);

    while ((dirent = readdir(dir)) != NULL) {
        if (dirent->d_name[0] != '.') {
            stat(dirent->d_name, &fstat);
            i = i + fstat.st_blocks;
        }
    }
    my_putstr("total ");
    my_put_nbr(i / 2);
    my_putchar('\n');
    closedir(dir);
    return (0);
}

void times(struct stat fstat)
{
    for (int i = 3; i < 16; i++)
        my_putchar(ctime(&fstat.st_mtime)[i]);
}

void ls_l_next(char *str, struct stat fstat, struct dirent *dirent)
{
    stat(str, &fstat);
    perm(fstat);
    my_put_nbr(fstat.st_nlink);
    gid_uid(fstat);
    my_putchar(' ');
    space(fstat);
    times(fstat);
    my_putchar(' ');
    my_putstr(dirent->d_name);
    my_putstr("\n");
}

void space(struct stat fstat)
{
    if (fstat.st_size < 1000000)
        my_putchar(' ');
    if (fstat.st_size < 100000)
        my_putchar(' ');
    if (fstat.st_size < 10000)
        my_putchar(' ');
    if (fstat.st_size < 1000)
        my_putchar(' ');
    if (fstat.st_size < 100)
        my_putchar(' ');
    if (fstat.st_size < 10)
        my_putchar(' ');
    my_put_nbr(fstat.st_size);
}

int ls_l(char *av)
{
    struct stat fstat;
    DIR *dir = opendir(av);
    if (dir == NULL)
        return (84);
    struct dirent *dirent = readdir(dir);
    char *str = my_strcat(av, dirent->d_name);

    stat(str, &fstat);
    total(fstat, av);
    while ((dirent = readdir(dir)) != NULL) {
        if (dirent->d_name[0] != '.')
            ls_l_next(str, fstat, dirent);
    }
    closedir(dir);
    return (0);
}