#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

#define MAX_X 64
#define MAX_Y 64

#define EMPTY_C ' '
#define WALL_C  '#'
#define HEAD_C  'O'
#define BODY_C  'o'
#define FOOD_C  'X'

#define SPAWN_X 10
#define SPAWN_Y 10
#define MAX_LEN 30
#define SNAKE_DED  1
#define SNAKE_LONG 2

typedef enum {INVALID, EMPTY, WALL, HEAD, BODY, FOOD} map_tile_t;
typedef struct {
    map_tile_t tiles[MAX_Y][MAX_X];
    int x_size;
    int y_size;
} map_t;

typedef enum {UP, DOWN, LEFT, RIGHT} direction_t;
typedef struct {
    int x;
    int y;
} snake_segment_t;
typedef struct {
    snake_segment_t segments[MAX_LEN];
    int size;
    direction_t direction;
} snake_t;

typedef struct {
    int x;
    int y;
} food_t;

#define map_at(map_ptr, x, y) map_ptr->tiles[y][x]
#define map_x_size(map_ptr) map_ptr->x_size
#define map_y_size(map_ptr) map_ptr->y_size

#define get_snake_seg(snake_ptr) snake_ptr->segments
#define get_snake_x(snake_ptr, seg) snake_ptr->segments[seg].x
#define get_snake_y(snake_ptr, seg) snake_ptr->segments[seg].y
#define get_snake_size(snake_ptr) snake_ptr->size
#define get_snake_direction(snake_ptr) snake_ptr->direction

#define get_food_x(food_ptr) food_ptr->x
#define get_food_y(food_ptr) food_ptr->y

void clrscr(void);

map_t *create_map(int x_tiles, int y_tiles);
void destroy_map(map_t *map);
void draw_map(const map_t *map);
void save_map_state(const map_t *map, map_t *prev_state);
void restore_map_state(map_t *map, const map_t *prev_state);

snake_t *create_snake(void);
void destroy_snake(snake_t *snake);
int move_snake(snake_t *snake, map_t *map);
void apply_snake(map_t *map, const snake_t *snake);

void spawn_food(map_t *map);
void destroy_food(void);
void apply_food(map_t *map);

#endif // Main
