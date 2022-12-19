/*
** EPITECH PROJECT, 2022
** MY_STRLEN
** File description:
** counts and returns the number of characters found in the string
*/

#include "my_compile.h"

int my_strlen(char const *str)
{
    int nb = 0;
    int i = 0;
    while (str[i] != '\0') {
        nb++;
        i++;
    }
    return (nb);
}
