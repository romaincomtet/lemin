/*
** EPITECH PROJECT, 2019
** lemin.h
** File description:
** tetris.h
*/

#ifndef my_lemin_h_
#define my_lemin_h_
#include "my.h"
#define exit_error __asm__("movq $60, %rax\nmovq $84, %rdi\nsyscall");
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <getopt.h>
#include <fcntl.h>
#include <string.h>
#include <getopt.h>
#include <signal.h>
#include <ncurses.h>
#include <termios.h>
#include <ncurses.h>
#include <term.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>

typedef struct args
{
    int ants_nb;
    char **start;
    char **end;
    char ***room;
    char ***tunel;
}args_t;

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

char *my_strcat_free(char *dest, char const *src);
void loop_child(road_t *D, char *start, char *end);
char **a_star(node_t *start, char *end);
int check_word(char *str, char *str1);
int check_with_name_room(args_t *a, char *str);
int check_tunnel_name(args_t *a);
void chain_list(char ***way, array_t **all);
array_t *list_arg(char ***arg, array_t *tmp);
node_t *init(char *name);
void append_l(array_t **D, node_t *L);
int loop_child2(road_t *D, char *end);
int is_child_in(road_t *D, array_t *tmp, char *start, char *end);
int is_same_position(node_t *tmp, node_t *compare);
void get_the_current_node(road_t *D);
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

node_t *init_all_node_tunnel(args_t args);
int check_name_ex(args_t *arg);
int check_coord(args_t *arg);
void recover_all(args_t *arg);
int check_same_word(char *str, char *str1);
int check_is_nb(char *str);
int check_comment(char **dest);
char **str_new_tab1(char *str, char s);
char ***recov_room(char **dest, char ***room, int n);
char ***text_malloc_env(char ***env, char **nest);
char ***recov_tunel(char **dest, char ***tunel, int i);

#endif /* my_lemin_h_ */