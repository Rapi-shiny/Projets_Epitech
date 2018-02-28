##
## Makefile for Makefile in /home/barret_l/rendu/Prog_elem/CPE_2015_Allum1
## 
## Made by Ludovic BARRETEAU
## Login   <barret_l@epitech.net>
## 
## Started on  Tue Feb  9 11:37:20 2016 Ludovic BARRETEAU
## Last update Sat Feb 20 16:02:57 2016 Ludovic BARRETEAU
##

NAME	=	allum1

SRC	=	srcs/main.c		\
		srcs/get_next_line.c	\
		srcs/my_getnbr.c	\
		srcs/my_printf.c	\
		srcs/errors.c	\
		srcs/show_board.c	\
		srcs/game.c		\
		srcs/functions.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

CFLAGS  =       -Wall -Wextra

RM	=	rm -rf

all:		$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)
	$(RM) srcs/*~
	$(RM) srcs/*#

re:	fclean all
