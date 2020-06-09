/*
** EPITECH PROJECT, 2019
** specific
** File description:
** specific
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

void specific(const char *std, int i)
{
    switch (std[i]) {
    case '%':
        my_putchar('%');
        break;
    }
}