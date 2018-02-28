##
## Makefile for Makefile in /home/barret_l/rendu/Systeme_unix/PSU_2015_my_select
## 
## Made by Ludovic BARRETEAU
## Login   <barret_l@epitech.net>
## 
## Started on  Wed Dec  2 11:15:50 2015 Ludovic BARRETEAU
## Last update Sat Dec 12 15:54:39 2015 Ludovic BARRETEAU
##

NAME	=	my_select

SRC	=	my_select.c		\
		my_select_bis.c		\
		my_select_list.c	\
		my_select_ter.c

OBJ	=	$(SRC:.c=.o)

RM	=	rm -rf

CC	=	gcc

all:		$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) -L./lib/my -lmy -lncurses

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)
	$(RM) *~
	$(RM) *#
re:		fclean all
