/*
** EPITECH PROJECT, 2022
** my_compile
** File description:
** libmy, my_compile
*/

#ifndef LIBMY_MY_COMPILE_H
    #define LIBMY_MY_COMPILE_H
    #include "my.h"
    #include <stdlib.h>
static int overflow(char const *str, int firstnb, int lastnb, int sign);
static int my_construct_int(char const *str, int sign, int firstnb, int lastnb);
static int my_getnbr_isop(char c, int *i, int *sign);
static int my_getnbr_scan(char c, int *sign, int *i, int *isnb);
static int print_nbr(int nbr, int count, int flag);
static int check_pos(int nbr, int count, int flag);
static int isalphanum(char s);
static int countchar(char const *str, int i, int *counted_word, char **arr);
static int check_is_same(char *str, char const *to_find, int *flag, int i);
#endif //LIBMY_MY_COMPILE_H
