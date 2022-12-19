/*
** EPITECH PROJECT, 2022
** warp_0to600
** File description:
** my-hunter, warp_0to600
*/

#include "res.h"

int warp_0to400(int axe_x, int axe_y)
{
    if (axe_y < 40)
        return 0;
    if (axe_x < -50)
        return 0;
    if (axe_x > settings.width - 100)
        return 0;
    if (axe_x > 370 && axe_x < 1360)
        return 0;
    return 1;
}
