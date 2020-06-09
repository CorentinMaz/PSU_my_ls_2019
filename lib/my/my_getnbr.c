/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** my_getnbr
*/

int my_getnbr(char const *str)
{
    int i = 0;
    long res = 0;

    while (str[i] < 48 || str[i] > 57)
        i++;
    while ((str[i] >= 48) && (str[i] <= 57)) {
        res = res * 10 + (str[i] - 48);
        i++;
    }
    return (res);
}

int my_get_nbr(char const *str)
{
    int i = 0;
    int neg = 0;
    long res = 0;

    while (str[i] < 48 || str[i] > 57)
        i++;
    if (str[i] >= 48 && str[i] <= 57 && str[i - 1] == 45)
        neg = 1;
    while ((str[i] >= 48) && (str[i] <= 57)) {
        res = res * 10 + (str[i] - 48);
        i++;
    }
    if (neg == 1)
        return (res * (-1));
    else
        return (res);
    return (res);
}