/*
** EPITECH PROJECT, 2022
** title_window
** File description:
** my-hunter, title_window
*/

#include "res.h"

void ptr_title_click(int x, int y)
{
    if (x >= 700 && x <= 1400 && y >= 580 && y <= 780) {
        game.state = 1;
    }
}

void title_window_text_rend(void)
{
    sfText_setString(title.text, "Play");
    sfText_setPosition(title.text, (sfVector2f){810, 590});
    sfRenderWindow_drawText(window, title.text, NULL);
}

void title_window_render(void)
{
    sfRenderWindow_drawSprite(window, title.background, NULL);
    sfRenderWindow_drawText(window, title.title, NULL);
    sfRenderWindow_drawSprite(window, title.logo, NULL);
    sfSprite_setPosition(title.button, (sfVector2f){700, 580});
    sfRenderWindow_drawSprite(window, title.button, NULL);
    title_window_text_rend();
}
