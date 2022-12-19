/*
** EPITECH PROJECT, 2022
** game_state
** File description:
** my-hunter, game_state
*/

#include "res.h"

void in_game_loop(void)
{
    if (game.score >= 500) {
        game.state = 3;
    }
    if (game.nb_of_death >= 3) {
        game.state = 2;
    }
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    game_window();
    clock_game_update();
}

void title_loop(void)
{
    sfRenderWindow_setMouseCursorVisible(window, sfTrue);
    title_window_render();
}

void loose_loop(void)
{
    sfRenderWindow_setMouseCursorVisible(window, sfTrue);
    sfText_setString(title.text, "You Loose");
    sfText_setPosition(title.text, (sfVector2f){650, 490});
    sfRenderWindow_drawText(window, title.text, NULL);
}

void win_loop(void)
{
    sfRenderWindow_setMouseCursorVisible(window, sfTrue);
    sfText_setString(title.text, "You Win");
    sfText_setPosition(title.text, (sfVector2f){700, 490});
    sfRenderWindow_drawText(window, title.text, NULL);

}

void state_do_loop(void)
{
    if (game.state == 0)
        title_loop();
    if (game.state == 1)
        in_game_loop();
    if (game.state == 2)
        loose_loop();
    if (game.state == 3)
        win_loop();
}
