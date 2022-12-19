/*
** EPITECH PROJECT, 2022
** MY_PUTCHAR
** File description:
** my putchar
*/

#include "my_compile.h"

void my_putchar(char s)
{
    write(1, &s, 1);
}
