/*
** EPITECH PROJECT, 2022
** MY_PUT_NBR
** File description:
** displays the number given as a parameter.
*/

#include "my_compile.h"

static int print_nbr(int nbr, int count, int flag)
{
    int i;
    int j;
    int puis;
    int dig;

    for (i = 0; i < count; i++) {
        puis = 1;
        for (j = 1; j < count - i; j++) {
            puis = puis * 10;
        }
        dig = (nbr / puis) % 10;
        my_putchar(dig + 48);
    }
    if (flag == 1) {
        my_putchar(8 + 48);
    }
}

static int check_pos(int nbr, int count, int flag)
{
    if (nbr > 0) {
        print_nbr(nbr, count, flag);
    } else if (nbr == 0) {
        my_putchar(48);
    } else {
        if (nbr == -2147483648) {
            nbr /= 10;
            count--;
            flag = 1;
        }
        my_putchar(45);
        nbr = nbr * -1;
        print_nbr(nbr, count, flag);
    }
}

int my_put_nbr(int nbr)
{
    int count = 0;
    int nbr2 = nbr;
    int flag = 0;
    while (nbr2 != 0) {
        nbr2 /= 10;
        ++count;
    }
    check_pos(nbr, count, flag);
}
