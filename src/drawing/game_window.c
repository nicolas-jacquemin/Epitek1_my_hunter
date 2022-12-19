/*
** EPITECH PROJECT, 2022
** game_window
** File description:
** my-hunter, game_window
*/

#include "res.h"

void change_level(int leveln)
{
    settings.nb_level = leveln;
    settings.speed = level[leveln].speed;
    settings.spawn_speed = level[leveln].spawn_speed;
    settings.nb_pnj = level[leveln].nb_pnj;
    settings.health_speed = level[leveln].health_speed;
}

void cursor_move(void)
{
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    sfVector2f pos = {mouse.x * settings.width / window_size.x,
        mouse.y * settings.height / window_size.y};
    pos.x -= 30;
    pos.y -= 30;
    sfSprite_setPosition(sprite.cursor, pos);
}

void heart_disp(void)
{
    sfVector2f pos = {30, 25};
    for (int i = 0; i < 3 - game.nb_of_death; i++) {
        sfSprite_setPosition(sprite.heart, pos);
        sfRenderWindow_drawSprite(window, sprite.heart, 0);
        pos.x += 70;
    }
}

void game_window(void)
{
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    sfRenderWindow_drawSprite(window, sprite.background, 0);
    sfRenderWindow_drawSprite(window, sprite.dollar, 0);
    sfRenderWindow_drawText(window, sprite.score, 0);
    heart_disp();
    anim_pnj();
    cursor_move();
    sfRenderWindow_drawSprite(window, sprite.cursor, 0);
}
