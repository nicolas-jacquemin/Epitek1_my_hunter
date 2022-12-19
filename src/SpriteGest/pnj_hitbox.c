/*
** EPITECH PROJECT, 2022
** pnj_hitbox
** File description:
** my-hunter, pnj_hitbox
*/

#include "res.h"

int *transform_cursor_pos(int x, int y)
{
    int *pos = malloc(sizeof(int) * 2);

    sfVector2u size = sfRenderWindow_getSize(window);
    pos[0] = (x * settings.width) / size.x;
    pos[1] = (y * settings.height) / size.y;
    return (pos);
}

int get_pnj_hit(pnj_t *pnj, int click_x, int click_y)
{
    sfFloatRect pnj_rect = sfSprite_getGlobalBounds(pnj->sprite);
    int *pos = transform_cursor_pos(click_x, click_y);
    click_x = pos[0];
    click_y = pos[1];
    if (click_x > pnj_rect.left - 50 &&
        click_x < pnj_rect.left + 250 && click_y > pnj_rect.top - 50 &&
        click_y < pnj_rect.top + 250)
        return 1;
    return 0;
}
