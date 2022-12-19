/*
** EPITECH PROJECT, 2022
** pnj_random
** File description:
** my-hunter, pnj_random
*/

#include "res.h"

void move_pnj_left(pnj_t *pnj, int axe_x)
{
    sfVector2f scale = sfSprite_getScale(pnj->sprite);
    sfVector2f pos = sfSprite_getPosition(pnj->sprite);
    if (axe_x < 0 && scale.x > 0) {
        scale.x *= -1;
        pos.x += 200;
        sfSprite_setPosition(pnj->sprite, pos);
        sfSprite_setScale(pnj->sprite, scale);
    }
}

void move_pnj_right(pnj_t *pnj, int axe_x)
{
    sfVector2f scale = sfSprite_getScale(pnj->sprite);
    sfVector2f pos = sfSprite_getPosition(pnj->sprite);
    if (axe_x > 0 && scale.x < 0) {
        scale.x *= -1;
        pos.x -= 200;
        sfSprite_setPosition(pnj->sprite, pos);
        sfSprite_setScale(pnj->sprite, scale);
    }
}

void move_pnj(pnj_t *pnj, int axe_x, int axe_y)
{
    sfVector2f pos, health_pos, scale;
    move_pnj_left(pnj, axe_x);
    move_pnj_right(pnj, axe_x);
    scale = sfSprite_getScale(pnj->sprite);
    pos = sfSprite_getPosition(pnj->sprite);
    pos.x += axe_x;
    pos.y += axe_y;
    health_pos = pos;
    health_pos.y -= 20;
    health_pos.x += (scale.x < 0) ? - 150 : 40;
    sfSprite_setPosition(pnj->health.sprite, health_pos);
    sfSprite_setPosition(pnj->sprite, pos);
}

int get_random(pnj_t *pnj, char axe)
{
    int nb = (rand() % (5 + 2)) -1;
    if (axe == 'y' && nb > -1)
        return pnj->last_movement_y;
    else if (axe == 'y')
        return pnj->last_movement_y * -1;
    if (axe == 'x' && nb > -1)
        return pnj->last_movement_x;
    return pnj->last_movement_x * -1;
}

void pnj_random(pnj_t *pnj)
{
    sfVector2f pos = sfSprite_getPosition(pnj->sprite);
    int x, y, nb = 0;
    x = settings.speed * get_random(pnj, 'x');
    y = (settings.speed) * get_random(pnj, 'y');
    while (!warp_zone(get_pnj_pos_x(pnj, x), pos.y + y)) {
        if (nb > 10000)
            pnj_die(pnj);
        if (pnj->is_alive == 0)
            return;
        x = settings.speed * get_random(pnj, 'x');
        y = (settings.speed) * get_random(pnj, 'y');
        nb++;
    }
    pnj->last_movement_x = (x > 0) ? 1 : -1;
    pnj->last_movement_y = (y > 0) ? 1 : -1;
    move_pnj(pnj, x, y);
}
