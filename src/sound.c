/*
** EPITECH PROJECT, 2022
** sound
** File description:
** my-hunter, sound
*/

#include "res.h"

void sound_stop(void)
{
    sfMusic_stop(sprite.hit_sound[0]);
    sfMusic_stop(sprite.hit_sound[1]);
    sfMusic_stop(sprite.hit_sound[2]);
}

void sound_add(void)
{
    sprite.hit_sound[0] = sfMusic_createFromFile("res/hit.ogg");
    sprite.hit_sound[1] = sfMusic_createFromFile("res/hit2.ogg");
    sprite.hit_sound[2] = sfMusic_createFromFile("res/hit3.ogg");
    sound_stop();
}

void sound_play(void)
{
    int random = (rand() % 3);
    sfMusic_stop(sprite.hit_sound[random]);
    sfMusic_play(sprite.hit_sound[random]);
}
