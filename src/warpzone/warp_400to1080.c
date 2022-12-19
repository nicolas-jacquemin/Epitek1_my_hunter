/*
** EPITECH PROJECT, 2022
** warp_600to1080
** File description:
** my-hunter, warp_600to1080
*/

#include "res.h"

int warp_table(int axe_x)
{
    if (axe_x < 180)
        return 0;
    if (axe_x > 1550)
        return 0;
    return 1;
}

int warp_400to1080(int axe_x, int axe_y)
{
    if (axe_y > settings.height - 150)
        return 0;
    if (axe_y > 650)
        return warp_table(axe_x);
    if (axe_x < -50)
        return 0;
    if (axe_x > settings.width - 100)
        return 0;
    return 1;
}
