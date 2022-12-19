/*
** EPITECH PROJECT, 2022
** MY_STR_ISALPHA
** File description:
** str is alpha
*/

#include "my_compile.h"

int my_str_isprintable(char const *str)
{
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] < 32 || str[i] > 126) {
            return (0);
        }
    }

    return (1);
}
