/*
** EPITECH PROJECT, 2022
** warp
** File description:
** my-hunter, warp
*/

#include "res.h"

int warp_zone(int axe_x, int axe_y)
{
    if (axe_y < 400)
        return warp_0to400(axe_x, axe_y);
    else
        return warp_400to1080(axe_x, axe_y);
}
