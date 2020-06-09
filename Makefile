##
## EPITECH PROJECT, 2019
## CPool_bistro-matic_2019
## File description:
## Makefile
##

SRC	=	src/my_ls.c	\
		src/main.c	\
		src/ls_l.c	\
		src/ls_r.c	\
		src/permission.c	\
		lib/my/converting.c	\
		lib/my/my_printf.c	\
		lib/my/specific.c	\
		lib/my/my_putchar.c	\
		lib/my/my_put_nbr.c	\
		lib/my/my_put_pos.c	\
		lib/my/my_strlen.c	\
		lib/my/my_putstr.c	\
		lib/my/my_getnbr.c	\
		lib/my/my_revstr.c

CC	=	gcc  -W -Wall -Wextra -g3 -Os

CFLAGS = -I./include/

AR	=	ar rc

OBJ	=	$(SRC:.c=.o)

NAME	=	my_ls

NAME2	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	$(AR) $(NAME2) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -L. -lncurses

clean:
	rm -f $(OBJ)
	rm -f *~

fclean:	clean
	rm -f $(NAME)
	rm -f $(NAME2)

re:	fclean all

.PHONY: all clean