##
## Makefile for  in /home/barret_l/rendu/Initiation_IA/dante
## 
## Made by Ludovic BARRETEAU
## Login   <barret_l@epitech.net>
## 
## Started on  Mon May  9 15:12:32 2016 Ludovic BARRETEAU
## Last update Sat May 21 13:39:02 2016 Ludovic BARRETEAU
##

NAME	=	solver

SRC	=	src/laby.c		\
		src/main.c		\
		src/tab.c		\
		src/list.c		\
		src/tools.c		\
		src/algo.c		\
		src/check.c		\

OBJ	=	$(SRC:.c=.o)

RM	=	rm -rf

CFLAGS	=	-W -Wall -Werror -Wextra -pedantic -I ./inc

CC	=	gcc

all:		$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
