/*
** EPITECH PROJECT, 2022
** clock
** File description:
** my-hunter, clock
*/

#include "res.h"

void create_clock(void)
{
    for (int i = 0;  i < settings.nb_pnj; i++) {
        pnj[i]->clock_anim = sfClock_create();
        pnj[i]->clock_died = sfClock_create();
    }
    sprite.anti_spam_click_clock = sfClock_create();
}

void clock_game_update(void)
{
    for (int i = 0;  i < settings.nb_pnj; i++) {
        pnj[i]->seconds_anim = sfClock_getElapsedTime(pnj[i]->clock_anim)
                .microseconds / 1000000.0;
        if (sfClock_getElapsedTime(pnj[i]->clock_died)
                    .microseconds / 1000000.0 > settings.spawn_speed)
            pnj[i]->seconds_died = sfClock_getElapsedTime(pnj[i]->clock_died)
                    .microseconds / 1000000.0;
    }
    sprite.anti_spam_click = sfClock_getElapsedTime(
            sprite.anti_spam_click_clock).microseconds / 1000000.0;
}
