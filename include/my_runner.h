/*
** EPITECH PROJECT, 2021
** my_runner header
** File description:
** contains all my_runner prototypes & structures
*/

#include <SFML/Graphics.h>
#include <SFML/Audio/Sound.h>
#ifndef MY_RUNNER_H_
# define MY_RUNNER_H_

typedef enum {
    car,
    first_bg,
    second_bg,
    third_bg,
    obstacle,
} typeOfObj;

typedef struct obs {
    int i;
    int j;
    int order;
} obstacle_create;

struct game_object {
    typeOfObj type;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect car_rect;
    sfVector2f jump;
    sfVector2f end_pos;
    sfClock *clock;
    sfMusic *music;
    sfMusic *die_effect;
    sfMusic *win_effect;
    int is_cleaned_die;
    int is_cleaned_win;
    int too_far;
    int re_init;
    int speed;
    int size;
    int is_jump;
    int can_jump;
    int rect_count;
    float jump_mult;
    float seconds;
    int menu;
    int end;
    int life;
    int score;
    int verif_score;
};

sfRenderWindow *window_create(int x, int y, int framerate);

void analyse_events(sfRenderWindow *window, sfEvent event,
struct game_object *objects, char *filename);

struct game_object create_bg_object(const char *path_spritesheet,
int *pos, typeOfObj type);

void destroy_object(struct game_object obj);

struct game_object move_background(struct game_object obj);

void object_resize(struct game_object obj, float x, float y);

struct game_object *create_backgrounds(struct game_object *backgrounds);

void display_backgrounds(sfRenderWindow *window,
struct game_object *backgrounds);

void destroy_objects(struct game_object *obj, int nb_of_sprites);

void init_coords(struct game_object *backgrounds);

sfIntRect create_240sx_rect(void);

struct game_object create_car_object(const char *path_spritesheet,
int *pos, sfIntRect rect, typeOfObj type);

struct game_object *create_240sx(struct game_object *cars, sfIntRect rect);

void display_cars(sfRenderWindow *window, struct game_object *cars);

sfIntRect rect_clock(sfIntRect rect, float seconds, struct game_object obj);

sfIntRect bike_clock(sfIntRect rect, float seconds, struct game_object obj);

char *config_to_str(const char *config);

struct game_object *create_map(struct game_object *map, char *buffer);

struct game_object create_obstacle(const char *path_spritesheet,
int *pos, sfIntRect rect, typeOfObj type);

void display_obstacles(sfRenderWindow *window,
struct game_object *maps, int nb_of_sprites);

struct game_object *move_obstacles(struct game_object *obj,
int nb_of_sprites);

void move_objects(struct game_object *objects, int nb_of_sprites);

void display_objects(sfRenderWindow *window, struct game_object *objects,
int nb_of_sprites);

struct game_object *create_objects(struct game_object *objects,
char *config_file);

void move_obstacle_sprite_rect(struct game_object *objects, float seconds,
int nb_of_sprites);

struct game_object move_bike_sprite_rect(struct game_object objects,
float seconds);

sfMusic *play_music(void);

int get_obstacle_number(char const *filename);

void is_collision(struct game_object *obj, int nb_of_sprites);

void display_game(sfRenderWindow *window, struct game_object *objects,
int nb_of_sprites);

void display_menu(sfRenderWindow *window, struct game_object *objects);

void display_end(sfRenderWindow *window, struct game_object *objects,
int nb_of_sprites);

void display_end_menu(sfRenderWindow *window);

void display_beginning_menu(sfRenderWindow *window);

void display_help(void);

void display_score(struct game_object *objects, sfRenderWindow *window);

int obs_create(obstacle_create obs, struct game_object *map,
int sprite_nb, char **map_array);

int more_obs_create(obstacle_create obs, struct game_object *map,
int sprite_nb, char **map_array);

void add_score(struct game_object *objects);

void alloc_map_array(char **map_array, int nb_lines,
int nb_chars_on_line);

void display_win_menu(sfRenderWindow *window, struct game_object *object);

void display_porsche_sprite(sfTexture *texture, sfSprite *sprite);

#endif /* !MY_RUNNER_H_ */
