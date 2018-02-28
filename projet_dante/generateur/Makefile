##
## Makefile for Makefile in /home/joly_q/Colle
## 
## Made by JOLY Alan
## Login   <joly_q@epitech.net>
## 
## Started on  Thu Apr 28 14:09:27 2016 JOLY Alan
## Last update Sun May 29 00:27:10 2016 JOLY Alan
##

NAME	= generateur

INCDIR	= include/

SRCDIR	= srcs/

SRCS	= $(SRCDIR)move.c	\
	  $(SRCDIR)generator.c	\
	  $(SRCDIR)my_strlen.c	\
	  $(SRCDIR)imperfect.c	\


OBJS	= $(SRCS:.c=.o)

CFLAGS	= -Wall -W -Werror -I $(INCDIR)

RM 	= rm -rf

CC	= gcc

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
