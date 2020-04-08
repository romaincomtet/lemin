##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##


SRC  	=	src/main.c	\
			src/recover_arg.c \
			src/check_arg_err.c \
			src/my_tabl.c \
			src/recover_room.c \
			src/newline_tab.c \
			src/check_error.c		\
			src/chained_list.c	\
			src/create_list.c	\
			src/a_star.c 		\
			src/loop_child.c 	\
			src/free_fonction.c

OBJ     =       $(SRC:.c=.o)

CFLAGS  =       -g3 -I./include

NAME    =   ./lem_in

all:    $(NAME)
$(NAME):	$(OBJ)
	make -C ./lib/my
	gcc -o  $(NAME) $(OBJ) -L./lib -lmy -lm

clean:
	make clean -C ./lib/my
	rm -f $(OBJ)
	rm -rf obj
	rm -f lib/libmy.a

fclean: clean
	make fclean -C ./lib/my
	rm -f $(NAME)

re:     fclean all