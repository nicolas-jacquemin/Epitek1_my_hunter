/*
** EPITECH PROJECT, 2022
** MY_PUT_NBR
** File description:
** displays the number given as a parameter.
*/

#include "my_compile.h"

static char *itos_nbr(int nbr, int count, int flag)
{
    int i;
    int j;
    int puis;
    int dig;
    char *str = malloc(sizeof(char) * count + 1 + flag);
    str[0] = (flag == 1) ? '-' : '\0';
    for (i = flag; i < count; i++) {
        puis = 1;
        for (j = 1; j < count - i; j++) {
            puis = puis * 10;
        }
        dig = (nbr / puis) % 10;
        str[i] = dig + 48;
    }
    if (flag == 1) {
        str[i] = 8 + 48;
    }
    str[i + flag] = '\0';
    return (str);
}

static int itos_check_pos(int nbr, int count, int flag)
{
    if (nbr > 0) {
        itos_nbr(nbr, count, flag);
    } else if (nbr == 0) {
        itos_nbr(nbr, 1, flag);
    } else {
        if (nbr == -2147483648) {
            nbr /= 10;
            count--;
            flag = 1;
        }
        nbr = nbr * -1;
        itos_nbr(nbr, count, flag);
    }
}

char *itos(int nbr)
{
    int count = 0;
    int nbr2 = nbr;
    int flag = 0;
    while (nbr2 != 0) {
        nbr2 /= 10;
        ++count;
    }
    itos_check_pos(nbr, count, flag);
}
