/*
** EPITECH PROJECT, 2019
** chain_list.h
** File description:
** chain_list.h
*/

#ifndef chain_list_h_
#define chain_list_h_

typedef struct node
{
    struct node *parent;
    char *name;
    int g;
    struct array *tun;
}node_t;

typedef struct array
{
    struct node *S;
    struct array *next;
}array_t;

typedef struct road
{
    array_t *open_list;
    array_t *closed_list;
    node_t *current_node;
    int current_index;
    array_t *children;
    char **b;
}road_t;

array_t *list_arg(char ***arg, array_t *tmp);
void chain_list(char ***way, char *first, array_t *all);
node_t *init(char *name);
void append_l(array_t **D, node_t *L);

char *my_strcat_free(char *fr, char const *src);
void loop_child(road_t *D, node_t *end_node);
int loop_child2(road_t *D, node_t *end_node);
int is_child_in(road_t *D, array_t *tmp);
int is_same_position(node_t *tmp, node_t *compare);
void get_the_current_node(road_t *D);
node_t *init_node(node_t *parent);
void pop_l(array_t **D, int index);
void charge_map(road_t *D, char *filename);
char **create_array(road_t *D, char *buffer);
void get_rows(road_t *D);
int get_nb_cols(char const *arr);
void free_structure2(array_t *tmp);
void free_node(node_t *tmp);
void free_structure(array_t *tmp);
void free_all(road_t *D);
void pop_l(array_t **D, int index);
int strlen_l(array_t *D);
void append_l(array_t **D, node_t *L);
char *my_strcat_slash(char *file, char *name);
char *my_strdup(char *src);

#endif /* chain_list_h_ */