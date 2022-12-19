/*
** EPITECH PROJECT, 2022
** pnj_spawn_tools
** File description:
** my-hunter, pnj_spawn_tools
*/

#include "res.h"

void propal_spawn_pnj(int *coord)
{
    int x, y;
    x = rand() % 3;
    y = (rand() % (650 - 0 + 1)) + 0;
    if (x == 1) {
        x = (rand() % (1550 - 180 + 1));
        y = settings.height - 200;
    } else
        x = (x == 0) ? 0 : settings.width - 100;
    coord[0] = x;
    coord[1] = y;
}

int *pnj_rand_spawn(pnj_t *pnj)
{
    int nb = 0, *coord = malloc(sizeof(int) * 2);
    propal_spawn_pnj(coord);
    while (!warp_zone(coord[0], coord[1])) {
        if (nb > 10000) {
            pnj_die(pnj);
            return NULL;
        }
        propal_spawn_pnj(coord);
        nb++;
    }
    return coord;
}

void pnj_spawn(pnj_t *pnj)
{
    int *rand;
    if (pnj->is_alive) {
        if (sfSprite_getTextureRect(pnj->health.sprite).width <= 0) {
            game.nb_of_death++;
            pnj_die(pnj);
            return;
        }
        sfRenderWindow_drawSprite(window, pnj->sprite, 0);
        sfRenderWindow_drawSprite(window, pnj->health.sprite, 0);
        return;
    }
    if (pnj->seconds_died <= settings.spawn_speed)
        return;
    rand = pnj_rand_spawn(pnj);
    sfSprite_setPosition(pnj->sprite, (sfVector2f){rand[0], rand[1]});
    pnj->is_alive = 1;
}

void pnj_die(pnj_t *pnj)
{
    pnj->is_alive = 0;
    pnj->seconds_died = 0;
    sfSprite_setColor(pnj->health.sprite, (sfColor){120, 233, 114, 255});
    sfSprite_setTextureRect(pnj->health.sprite, (sfIntRect){0, 0, 700, 60});
    sfClock_restart(pnj->clock_died);
    settings.spawn_speed =
            (settings.spawn_speed > 0.5) ? settings.spawn_speed - 0.1 : 0.5;
    settings.speed += (settings.speed < 50) ? 0.4 : 0;
    settings.health_speed += (settings.health_speed > 2) ? 0.4 : 0;
    sfText_setString(sprite.score, itos(game.score));
}

void ptr_die_pnj(int click_x, int click_y)
{
    if (sprite.anti_spam_click <= 0.1)
        return;
    for (int i = 0; i < settings.nb_pnj; i++) {
        if (get_pnj_hit(pnj[i], click_x, click_y)) {
            sound_play();
            game.score += 2;
            pnj_die(pnj[i]);
            sfClock_restart(sprite.anti_spam_click_clock);
        }
    }
}
