/*
** EPITECH PROJECT, 2022
** event_handler
** File description:
** my-hunter, event_handler
*/

#include "res.h"

void handle_events(sfEvent event)
{
    if (event.type == sfEvtClosed)
        close_window(window);
    if (event.type == sfEvtMouseButtonPressed && game.state == 1)
        ptr_die_pnj(event.mouseButton.x, event.mouseButton.y);
    if (event.type == sfEvtMouseButtonPressed && game.state == 0)
        ptr_title_click(event.mouseButton.x, event.mouseButton.y);
}
