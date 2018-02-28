##
## Makefile for Makefile in /home/barret_l/rendu/Prog_elem/CPE_2015_bsq
## 
## Made by Ludovic BARRETEAU
## Login   <barret_l@epitech.net>
## 
## Started on  Tue Nov 24 09:06:14 2015 Ludovic BARRETEAU
## Last update Sat Dec 19 18:19:08 2015 Ludovic BARRETEAU
##

NAME	=	bsq

SRC	=	bsq_bis.c	\
		main.c

OBJ	=	$(SRC:.c=.o)

RM	=	rm -rf

CC	=	gcc

all:		$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) -L ./lib -lmy

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)
	$(RM) *#
	$(RM) *~

re:		fclean all
