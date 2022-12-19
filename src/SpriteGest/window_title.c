/*
** EPITECH PROJECT, 2022
** window_title
** File description:
** my-hunter, window_title
*/

#include "res.h"

void game_button(void)
{
    sfTexture *texture = sfTexture_createFromFile("res/button.png",0);
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, (sfVector2f){0.7, 0.7});
    title.button = sprite;
}

void game_logo_add(void)
{
    sfTexture *texture = sfTexture_createFromFile("res/kfc_logo.png",0);
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, (sfVector2f){100, 480});
    sfSprite_setScale(sprite, (sfVector2f){0.7, 0.7});
    sfSprite_setRotation(sprite, 45);
    title.logo = sprite;
}

void game_text_add(void)
{
    sfText *text = sfText_create();
    title.text = text;
    sfFont *font = sfFont_createFromFile("res/mariofont.ttf");
    sfText_setFont(title.text, font);
    sfText_setCharacterSize(title.text, 100);
    sfText_setColor(title.text, (sfColor){179, 28, 47, 255});
}

void game_title_add(void)
{
    sfText *text = sfText_create();
    title.title = text;
    sfFont *font = sfFont_createFromFile("res/mariofont.ttf");
    sfText_setFont(title.title, font);
    sfText_setCharacterSize(title.title, 200);
    sfText_setPosition(title.title, (sfVector2f){320, 100});
    sfText_setColor(title.title, (sfColor){179, 28, 47, 255});
    sfText_setString(title.title, "KFC Hunter");
}

void title_sprite(void)
{
    sfTexture *texture = sfTexture_createFromFile("res/window_title.png",0);
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, (sfVector2f){0, 0});
    sfSprite_setScale(sprite, (sfVector2f){1, 1});
    title.background = sprite;
    game_title_add();
    game_text_add();
    game_logo_add();
    game_button();
}
