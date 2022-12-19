/*
** EPITECH PROJECT, 2022
** main
** File description:
** BS-my_hunter, main
*/

#include "include/var.h"
#include "include/res.h"

int check_assets(void)
{
    if (sfTexture_createFromFile("res/pnj0.png",0) == NULL ||
    sfTexture_createFromFile("res/hunter-background_min.png",0) == NULL ||
    sfTexture_createFromFile("res/hunter-icon.png",0) == NULL) {
        write(2, "Error: Missing assets\n", 22);
        return 0;
    }
    return 1;
}

int check_env(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], "DISPLAY", 7) == 0)
            return 1;
    }
    write(2, "Error: No display found\n", 24);
    return 0;
}

int print_help(void)
{
    my_putstr("KFC_Hunter [my_hunter]\nSome body want to eat some KFC ?\n");
    my_putstr("Goal : feed all the customers with some tenders before they ");
    my_putstr("die of hunger.\n\n");
    my_putstr("USAGE\n\t./my_hunter\n\n");
    my_putstr("OPTIONS\n\t-h\tprint the usage and quit.\n\n");
    my_putstr("USER INTERACTIONS\n\tMOUSE_LEFT_CLICK\t\n\n");
    my_putstr("AUTHOR\n\tWritten by Nicolas JACQUEMIN\n\n");
    return 0;
}

int main(int arc, char **arv, char **env)
{
    sfEvent event;
    if (!check_env(env))
        return 84;
    if (arc > 1 && arv[1][0] == '-' && arv[1][1] == 'h')
        return print_help();
    if (!check_assets())
        return 84;
    srand(time(NULL));
    create_window(); create_clock();
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            handle_events(event);
        }
        sfRenderWindow_clear(window, sfBlack);
        state_do_loop();
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    return 0;
}
