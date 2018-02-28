##
## Makefile for  in /home/crespi_c/rendu/Elementary_C/PSU_2015_minishell1
## 
## Made by Celenzo CRESPIN
## Login   <crespi_c@epitech.net>
## 
## Started on  Fri Jan 15 21:20:41 2016 Celenzo CRESPIN
## Last update Sun Jun  5 21:21:32 2016 Romain Hedouin
##

NAME		=	42sh

SRCS		=	./src/add.c			\
			./src/mysh.c			\
			./src/set.c			\
			./src/echo.c			\
			./src/stw2.c			\
			./src/mysh2.c			\
			./src/my_cd.c			\
			./src/alias.c			\
			./src/redir.c			\
			./src/parse.c			\
			./src/strwt.c			\
			./src/utils.c			\
			./src/redir2.c			\
			./src/utils2.c			\
			./src/utils3.c			\
			./src/utils4.c			\
			./src/hand_op.c			\
			./src/history.c			\
			./src/list_op.c			\
			./src/globing.c			\
			./src/var_env.c			\
			./src/free_all.c		\
			./src/my_printf.c		\
			./src/resources.c		\
			./src/envbuilts.c		\
			./src/my_getnbr.c		\
			./src/check_dir.c		\
			./src/resources2.c		\
			./src/job_control.c		\
			./src/var_env_bis.c		\
			./src/history_bis.c		\
			./src/urgency_path.c		\
			./src/tab_operators.c		\
			./src/globing_utils.c		\
			./src/get_next_line.c		\
			./src/str_to_wordtab.c		\
			./src/built_pipe_hand.c		\
			./src/redir_open_check.c	\
			./src/double_redi_left.c	\

OBJS		=	$(SRCS:.c=.o)

CC		=	gcc -g

RM		=	rm -rf

TEMP		=	./src/*~ ./*~ ./inc/*~

CFLAGS		=	-W -Wall -Wextra -pedantic -I ./inc

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS)

clean:
		@$(RM) $(OBJS)

fclean:		clean
		@$(RM) $(NAME)

cleaner:	fclean
		@$(RM) $(TEMP)

re:		fclean all

.PHONY:		all clean fclean re
