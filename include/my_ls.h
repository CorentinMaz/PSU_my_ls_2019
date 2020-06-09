/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** my_ls
*/
#ifndef LS_H_
#define LS_H_
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <linux/types.h>

typedef struct count
{
    int count;
}count_t;

void my_ls(void);
void type(void);
int ls_l(char *av);
void ls_d(void);
int open_files(char *av);
void times(struct stat fstat);
void gid_uid(struct stat fstat);
int ls_maj_r(char *av);
int files(char *av);
void ls_min_r(void);
void perm(struct stat fstat);
char *my_strcat(char *folder, char *d_name);
void space(struct stat fstat);

#endif