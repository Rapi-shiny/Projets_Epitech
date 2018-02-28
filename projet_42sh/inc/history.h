/*
** history.h for  in /home/barret_l/rendu/Systeme_unix/42_labo
** 
** Made by Ludovic BARRETEAU
** Login   <barret_l@epitech.net>
** 
** Started on  Fri May  6 10:24:56 2016 Ludovic BARRETEAU
** Last update Sun Jun  5 20:39:37 2016 Romain Hedouin
*/

#ifndef	_HISTORY_H
#define _HISTORY_H

#include <stdio.h>
#include <stdlib.h>

typedef struct	s_history
{
  int			num_cmd;
  char			*cmd;
  int			select;
  struct s_history	*next;
  struct s_history	*prev;
}	t_history;

t_history	*add_and_keep(char *, int);
t_history       *create_history(void);
void		add_cmd_hist(t_history *elem, char *cmd);
void		history(t_history *my_history);
void		nb_space(int num);
char		*ret_line(t_history *, char *, int);
char		*get_prev_cmd(t_history *my_history);
char		*get_next_cmd(t_history *my_history);
int		free_history(t_history *my_history);

#endif
