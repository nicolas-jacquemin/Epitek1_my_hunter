/*
** EPITECH PROJECT, 2022
** MY_STRCMP
** File description:
** strcmp
*/

#include "my_compile.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i;
    int les1 = my_strlen(s1);
    int les2 = my_strlen(s2);
    for (i = 0; i < n; i++) {
        if (les2 == i) {
            return (s1[les2]);
        }
        if (les1 == i) {
            return (s2[les1] * -1);
        }
        if (s1[i] > s2[i])
            return (s1[i] - s2[i]);
        if (s1[i] < s2[i])
            return (s1[i] - s2[i]);
    }
    return (0);
}
