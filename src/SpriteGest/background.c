/*
** EPITECH PROJECT, 2022
** background
** File description:
** my-hunter, background
*/

#include "res.h"

void dollar_add(void)
{
    sfTexture *texture;
    sprite.dollar = sfSprite_create();
    texture = sfTexture_createFromFile("res/dollar.png",0);
    sfSprite_setTexture(sprite.dollar, texture, sfTrue);
    sfSprite_setPosition(sprite.dollar, (sfVector2f){1680, 20});
    sfSprite_setScale(sprite.dollar, (sfVector2f){0.1, 0.1});
}

void background_add(void)
{
    sfTexture *texture;
    sprite.background = sfSprite_create();
    texture = sfTexture_createFromFile("res/hunter-background_min.png",0);
    sfSprite_setTexture(sprite.background, texture, sfTrue);
    sfSprite_setScale(sprite.background, (sfVector2f){1, 1});
    dollar_add();
}
