/*
** EPITECH PROJECT, 2019
** lemin.h
** File description:
** tetris.h
*/

#ifndef my_lemin_h_
#define my_lemin_h_
#include "my.h"
#include "chain_list.h"
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