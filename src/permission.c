/*
** EPITECH PROJECT, 2020
** perm
** File description:
** perm
*/
#include "my.h"
#include "my_ls.h"

void gid_uid(struct stat fstat)
{
    struct passwd *pass;
    struct group *grp;

    my_putchar(' ');
    pass = getpwuid(fstat.st_uid);
    my_putstr(pass->pw_name);
    my_putchar(' ');
    grp = getgrgid(fstat.st_gid);
    my_putstr(grp->gr_name);
}

char *my_strcat(char *folder, char *d_name)
{
    char *str = NULL;
    int i = 0;
    int j = 0;

    str = malloc(sizeof(char) * (my_strlen(folder) + my_strlen(d_name) + 2));
    while (folder[i] != '\0') {
        str[i] = folder[i];
        i++;
    }
    str[i] = '/';
    i++;
    while (d_name[j] != '\0') {
        str[i] = d_name[j];
        i++;
        j++;
    }
    str[i] = '\0';
    return str;
}

void permission(struct stat fstat)
{
    my_putstr(fstat.st_mode & S_IROTH ? "r" : "-");
    my_putstr(fstat.st_mode & S_IWOTH ? "w" : "-");
    my_putstr((fstat.st_mode & S_IXOTH) ? ("x") : ("-"));
    if ((fstat.st_mode & S_ISVTX) && !(fstat.st_mode & S_IXOTH))
        my_putstr("T ");
    else if ((fstat.st_mode & S_ISVTX) && (fstat.st_mode & S_IXOTH))
        my_putstr("t ");
    my_putstr(". ");
}

void perm(struct stat fstat)
{
    my_putstr(S_ISDIR(fstat.st_mode) ? "d" : "-");
    my_putstr(fstat.st_mode & S_IRUSR ? "r" : "-");
    my_putstr(fstat.st_mode & S_IWUSR ? "w" : "-");
    my_putstr(fstat.st_mode & S_IXUSR ? "x" : "-");
    my_putstr(fstat.st_mode & S_IRGRP ? "r" : "-");
    my_putstr(fstat.st_mode & S_IWGRP ? "w" : "-");
    if ((fstat.st_mode & S_ISGID) && !(fstat.st_mode & S_IXGRP))
        my_putstr("S");
    else if ((fstat.st_mode & S_ISGID) && (fstat.st_mode & S_IXGRP))
        my_putstr("s");
    else
        my_putstr((fstat.st_mode & S_IXGRP) ? ("x") : ("-"));
    permission(fstat);
}