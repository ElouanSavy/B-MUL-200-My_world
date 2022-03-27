/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-elouan.savy-camaret
** File description:
** my_world
*/

#ifndef MY_WORLD_H_
    #define MY_WORLD_H_
    #define MY_PI 3.14159265358979323846264338327950288
    #include <SFML/Graphics.h>
    #include <SFML/Window/Mouse.h>
    #include <SFML/Window/Types.h>
    #include <SFML/System/Time.h>
    #include <SFML/Audio.h>

typedef char *filepath;

enum gamestate {
    GS_PLAY,
    GS_MENU,
    GS_PAUSE,
    GS_LOAD
};

enum cursor_state {
    POINT,
    LINE,
    SQUARE
};

typedef struct map {
    int **map_3d;
    sfVector2f **vector_map;
    sfVector2f size;
    sfVector2f offset;
} map_t;

typedef struct cursor {
    sfCircleShape *cursor_point_1;
    sfCircleShape *cursor_point_2;
    sfCircleShape *cursor_point_3;
    sfCircleShape *cursor_point_4;
    sfVector2f nearest_point;
    sfVector2f sec_nearest_point;
    sfVector2f third_nearest_point;
    sfVector2f fourth_nearest_point;
    sfVector2f c_point;
    sfVector2f c_sec_point;
    sfVector2f c_third_point;
    sfVector2f c_fourth_point;
    enum cursor_state mode;
    int offset;
    int direction;
} cursor_t;

typedef struct menu_btn {
    sfSprite *flat;
    sfSprite *noise;
    sfSprite *load;
    sfSprite *quit;
    sfIntRect rect_load;
    sfIntRect rect_quit;
    sfIntRect rect_flat;
    sfIntRect rect_noise;
} menu_btn_t;

typedef struct menu {
    sfSprite *bg;
    sfSprite *planet;
    sfIntRect sprite_rect;
    sfClock *planet_clock;
    menu_btn_t menu_btn;
} menu_t;

typedef struct sroller {
    sfSprite *cursor;
    sfSprite *background;
    sfText *text;
} scroller_t;

typedef struct game_tools {
    struct btns *btn_selec;
    struct btns *btn_terra;
    sfSprite *btn_menu;
    sfSprite *btn_save;
    sfSprite *utils_bg;
    sfSprite *selector;
    sfSprite *terraforming;
    scroller_t *scroller;
} g_tools_t;

typedef struct musics {
    sfMusic *hit_sound;
} musics_t;

typedef struct to_load {
    char *name;
    sfSprite *bg;
    sfText *text;
    struct to_load *next;
} to_load_t;

typedef struct load {
    sfSprite *container;
    sfSprite *btn_back;
    sfSprite *btn_load;
    to_load_t *map_list;
    to_load_t *tmp;
} load_t;

typedef struct game {
    char *save_path;
    enum gamestate state;
    sfTexture *texture;
    sfRenderWindow *window;
    sfColor bg_color;
    map_t *map;
    cursor_t *cursor;
    menu_t *menu;
    g_tools_t *tools;
    sfVector2i offset;
    musics_t *musics;
    int tracked;
    int zoom;
    load_t *load;
} game_t;

typedef struct btns {
    sfSprite *sprite;
    void (*btn_action) (struct cursor *cursor, game_t *game);
    int selected;
    sfSprite *help;
    struct btns *next;
} btns_t;

sfRenderWindow *create_window(sfVideoMode md, char *name);
void window_icon(game_t *game);
void draw_2d_map(game_t *game);
musics_t *init_game_musics(void);

map_t *get_map(filepath path);
map_t *create_2d_map(map_t *map);
map_t *init_map(filepath path);

sfVertexArray *create_line(sfVector2f *point1 , sfVector2f *point2);
sfVertexArray *create_triangle(sfVector2f *p1 , sfVector2f *p2, \
sfVector2f *p3, sfColor color);
void event_handler(game_t *game);
int game_loop(game_t *game);

sfVector2f project_iso_point(int x, int y, int z);
void update_vector_map(game_t *game);
void update_map(game_t *game, sfVector2i cursor_pos);
int update_map_line(map_t *map, \
sfVector2i cursor_pos, int i, cursor_t *cursor);
float calc_distances_2p(sfVector2f p1, sfVector2i c);

menu_t *init_menu(game_t *game);
void display_menu(game_t *game);
void anim_planet(game_t *game);
int menu_loop(game_t *game);
void event_menu_handler(game_t *game);
void change_menu_btn_state(game_t *game, sfMouseMoveEvent mouse);
void anime_menu_btn_click(sfSprite *sprite);
void display_container_tool(game_t *game);

sfCircleShape *create_cursor_point(void);
cursor_t *create_cursor(void);
int update_cursor(game_t *game);
void replace_nearest_point(cursor_t *cursor, sfVector2f point);
void replace_sec_nearest_point(cursor_t *cursor, sfVector2f point);
void replace_third_nearest_point(cursor_t *cursor, sfVector2f point);
void replace_fourth_nearest_point(cursor_t *cursor, sfVector2f point);
void replace_nearest_point_curs(cursor_t *cursor, sfVector2f point);
void replace_sec_nearest_point_curs(cursor_t *cursor, sfVector2f point);
void replace_third_nearest_point_curs(cursor_t *cursor, sfVector2f point);
void replace_fourth_nearest_point_curs(cursor_t *cursor, sfVector2f point);
int check_simil(float new_distance, sfVector2i curs, sfVector2f c_point);

g_tools_t *init_game_tools(game_t *game);
btns_t *init_list_selec(game_t *game);
btns_t *init_list_terra(game_t *game);
void display_game_tools(btns_t *list, sfRenderWindow *window);
int check_terra_btn(game_t *game, sfMouseButtonEvent mouse);
int check_selec_btn(game_t *game, sfMouseButtonEvent mouse);
void check_tools_hover(btns_t *list, sfRenderWindow *window);
sfSprite *create_menu_btn(game_t *game, sfIntRect rect, int x, int y);
void point_select(cursor_t *cursor, __attribute__((unused)) game_t *game);
void line_select(cursor_t *cursor, __attribute__((unused)) game_t *game);
void tile_select(cursor_t *cursor, __attribute__((unused)) game_t *game);
void up_terra(cursor_t *cursor, __attribute__((unused)) game_t *game);
void down_terra(cursor_t *cursor, __attribute__((unused)) game_t *game);
void reset_terra(cursor_t *cursor, __attribute__((unused)) game_t *game);

scroller_t *init_scroller(game_t *game);
void update_offset(game_t *game);
void update_text(game_t *game);

void quit_game(game_t *game);
int check_collision(float x, float y, sfSprite* sprite);
sfColor get_color(game_t *game, int x, int y);
sfColor get_color_reverse(game_t *game, int x, int y);

char *get_random_name(game_t *game);
int save_file(game_t *game, char *path);
char *nb_to_str(long int nb);
char *get_path(game_t *game);
int free_map_ressources(game_t *game);

int display_usage(void);

to_load_t *add_to_map_list(char *name, to_load_t *list, game_t *game);
load_t *init_load(game_t *game);
to_load_t *init_to_load(game_t *game);
void display_load(game_t *game);
void load_loop(game_t *game);
void change_load_btn_state(game_t *game, sfMouseMoveEvent mouse);
map_t *load_save_map(game_t *game);
to_load_t *free_map_list(game_t *game);
void event_load_handler(game_t *game);
void reset_load_btn_state(game_t *game);
game_t *check_map_collision(game_t *game, sfMouseButtonEvent mouse);
int check_utils_click(sfEvent ev, game_t *game);
void check_utils_hover(g_tools_t *utils, sfRenderWindow *window);
void display_game_utilities(g_tools_t *tools, sfRenderWindow *window);
game_t *check_shortcut(sfEvent event, game_t *game);

float my_perlin(int x, int y, int seed, int *hash);
map_t *init_rand_map(game_t *game);

void zoom_around(sfEvent event, game_t *game);

int free_all_ressources(game_t *game);
int check_map(char *path);

#endif /* !MY_WORLD_H_ */
