/*
** EPITECH PROJECT, 2022
** pnj
** File description:
** my-hunter, pnj
*/

#include "res.h"

int get_pnj_pos_x(pnj_t *pnj, int axe_x)
{
    sfVector2f pos = sfSprite_getPosition(pnj->sprite);
    sfVector2f scale = sfSprite_getScale(pnj->sprite);
    if (scale.x < 0 && axe_x < 0)
        return pos.x - 200 + axe_x;
    if (scale.x < 0 && axe_x > 0)
        return pos.x - 200 + axe_x;
    return pos.x + axe_x;
}

void health_add(pnj_t *pnj)
{
    sfTexture *texture = sfTexture_createFromFile("res/health-bar.png",0);
    pnj->health.sprite = sfSprite_create();
    sfSprite_setTexture(pnj->health.sprite, texture, sfTrue);
    sfSprite_setScale(pnj->health.sprite, (sfVector2f){0.15, 0.15});
    sfSprite_setTextureRect(pnj->health.sprite, (sfIntRect){0, 0, 700, 60});
}

void pnj_add(void)
{
    pnj = malloc(sizeof(pnj_t *) * 6);
    sfTexture *texture;
    for (int i = 0; i < 6; i++) {
        pnj[i] = malloc(sizeof(pnj_t));
        pnj[i]->sprite = sfSprite_create();
        pnj[i]->clock_anim = sfClock_create();
        pnj[i]->seconds_anim = 0;
        pnj[i]->last_movement_x = 0;
        pnj[i]->last_movement_y = 0;
        pnj[i]->is_alive = 0;
        pnj[i]->seconds_died = settings.spawn_speed + 1;
        health_add(pnj[i]);
        texture = sfTexture_createFromFile("res/pnj0.png",0);
        sfSprite_setTexture(pnj[i]->sprite, texture, sfTrue);
        sfSprite_setScale(pnj[i]->sprite, (sfVector2f){1, 1});
        sfSprite_setPosition(pnj[i]->sprite, (sfVector2f){10, 100});
        sfSprite_setTextureRect(pnj[i]->sprite, (sfIntRect){0, 0, 200, 200});
    }
}

void pnj_animated(pnj_t *pnj)
{
    sfIntRect rect = sfSprite_getTextureRect(pnj->sprite),
    health_rect = sfSprite_getTextureRect(pnj->health.sprite);
    sfColor color = sfSprite_getColor(pnj->health.sprite);
    int healS = settings.health_speed;
    if (rect.left == 800)
        rect.left = -200;
    rect.left += 200;
    sfSprite_setTextureRect(pnj->sprite, rect);
    pnj_random(pnj);
    health_rect.width -= healS;
    color.r += (color.r +(healS / 2) < 255) ? (healS / 2) : 0;
    color.g -= (color.g -(healS / 3) > 0) ? (healS / 3) : 0;
    color.b -= (color.b -(healS / 5) > 0) ? (healS / 5) : 0;
    sfSprite_setColor(pnj->health.sprite, color);
    sfSprite_setTextureRect(pnj->health.sprite, health_rect);
    sfClock_restart(pnj->clock_anim);
}

void anim_pnj(void)
{
    for (int i = 0;  i < settings.nb_pnj; i++) {
        pnj_spawn(pnj[i]);
        if (pnj[i]->seconds_anim > 0.07 && pnj[i]->is_alive)
            pnj_animated(pnj[i]);
    }
}
