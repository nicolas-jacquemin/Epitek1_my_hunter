/*
** EPITECH PROJECT, 2022
** window_create
** File description:
** my-hunter, window_create
*/

#include "res.h"

void cursor_add(void)
{
    sfTexture *texture = sfTexture_createFromFile("res/tender.png",0);
    sfSprite *cursor = sfSprite_create();
    sfSprite_setTexture(cursor, texture, sfTrue);
    sfSprite_setPosition(cursor, (sfVector2f){0, 0});
    sfSprite_setScale(cursor, (sfVector2f){0.2, 0.2});
    sprite.cursor = cursor;
}

void score_add(void)
{
    sfText *text = sfText_create();
    sprite.score = text;
    sfFont *font = sfFont_createFromFile("res/mariofont.ttf");
    sfText_setFont(sprite.score, font);
    sfText_setCharacterSize(sprite.score, 70);
    sfText_setPosition(sprite.score, (sfVector2f){1750, 8});
    sfText_setColor(sprite.score, (sfColor){254, 204, 0, 255});
    sfText_setString(sprite.score, "0");
}

void heart_add(void)
{
    sfTexture *texture = sfTexture_createFromFile("res/heart.png",0);
    sfSprite *heart = sfSprite_create();
    sfSprite_setTexture(heart, texture, sfTrue);
    sfSprite_setScale(heart, (sfVector2f){0.06, 0.06});
    sprite.heart = heart;
}

void create_window(void)
{
    sfVideoMode mode = {settings.width, settings.height, 32};
    char name[] = "KFC Hunter";
    sfUint8 const *pixelIcon =
            sfImage_getPixelsPtr(sfImage_createFromFile("res/hunter-icon.png"));
    change_level(settings.nb_level);
    window = sfRenderWindow_create(mode, name, sfResize | sfClose, 0);
    sfRenderWindow_setFramerateLimit(window, settings.fps);
    sfRenderWindow_setIcon(window, 128, 128, pixelIcon);
    title_sprite();
    cursor_add();
    background_add();
    pnj_add();
    sound_add();
    score_add();
    heart_add();
}

void close_window(sfRenderWindow *window)
{
    sfRenderWindow_close(window);
}
