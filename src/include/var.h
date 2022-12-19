/*
** EPITECH PROJECT, 2022
** var
** File description:
** my-hunter, var
*/

#ifndef MY_HUNTER_VAR_H
    #define MY_HUNTER_VAR_H
    #include "SFML/Graphics.h"
    #include "res.h"

sfRenderWindow *window;
sprite_t sprite;
pnj_t **pnj;
level_t level[3] = {
        {17, 3, 2, 10},
        {20, 2, 4, 10},
        {30, 1, 6, 10}};
settings_t settings = {1920,
    1080,
    60,
    1,
    0,0,0,0};

game_t game = {0, 0, 0, 0};

title_t title;

#endif //MY_HUNTER_VAR_H
