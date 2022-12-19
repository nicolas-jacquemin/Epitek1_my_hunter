/*
** EPITECH PROJECT, 2022
** res
** File description:
** my-hunter, res
*/

#ifndef MY_HUNTER_RES_H
    #define MY_HUNTER_RES_H
    #include "my.h"
    #include <stdlib.h>
    #include "SFML/Graphics.h"
    #include "SFML/Audio.h"
    #include <time.h>

typedef struct pnj_health_s {
    sfSprite *sprite;
} pnj_health_t;

typedef struct pnj_s {
    int is_alive;
    sfSprite *sprite;
    sfClock *clock_died;
    float seconds_died;
    sfClock *clock_anim;
    float seconds_anim;
    int last_movement_x;
    int last_movement_y;
    pnj_health_t health;
} pnj_t;

typedef struct title_s {
    sfSprite *background;
    sfText *title;
    sfSprite *logo;
    sfSprite *button;
    sfText *text;
} title_t;

typedef struct sprite_s {
    sfSprite *background;
    sfSprite *cursor;
    sfSprite *dollar;
    sfSprite *heart;
    sfText *score;
    pnj_t pnj;
    sfMusic *hit_sound[3];
    int anti_spam_click;
    sfClock *anti_spam_click_clock;
} sprite_t;

typedef struct level_s {
    float speed;
    float spawn_speed;
    int nb_pnj;
    int health_speed;
} level_t;

typedef struct settings_s {
    int width;
    int height;
    int fps;
    int nb_level;
    float speed;
    float spawn_speed;
    int nb_pnj;
    int health_speed;
} settings_t;

typedef struct game_s {
    int state;
    int score;
    int max_score;
    int nb_of_death;
} game_t;

extern title_t title;
extern level_t level[3];
extern pnj_t **pnj;
extern sprite_t sprite;
extern settings_t settings;
extern sfRenderWindow *window;
extern game_t game;
void background_add(void);
void create_window(void);
void handle_events(sfEvent);
void close_window(sfRenderWindow *);
void game_window(void);
void pnj_add(void);
void anim_pnj(void);
void create_clock(void);
void clock_game_update(void);
void pnj_random(pnj_t *);
int warp_0to400(int, int);
int warp_400to1080(int, int);
int warp_zone(int, int);
int get_pnj_pos_x(pnj_t *, int);
void pnj_spawn(pnj_t *);
int get_pnj_hit(pnj_t *, int, int);
void ptr_die_pnj(int, int);
void pnj_die(pnj_t *);
void sound_add(void);
void sound_play(void);
void sound_stop(void);
void change_level(int);
void state_do_loop(void);
void title_sprite(void);
void title_window_render(void);
void ptr_title_click(int, int);
void win_loose_add(void);
#endif //MY_HUNTER_RES_H
