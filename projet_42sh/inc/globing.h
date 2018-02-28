/*
** globing.h for globing in /home/jahan_a/trashtest/globing
** 
** Made by antoine jahan
** Login   <jahan_a@epitech.net>
** 
** Started on  Tue May 31 13:37:21 2016 antoine jahan
** Last update Sat Jun  4 16:52:39 2016 antoine jahan
*/

#ifndef GLOB_H
# define GLOB_H

#include <unistd.h>
#include <stdlib.h>
#include <glob.h>

typedef struct	s_myglob
{
  char		*str;
  char		*new;
  int		next;
  glob_t	gl;
}		t_myglob;

int	my_strlen(char *s);
void    build_glob_str(t_myglob *t, int i);
void    end_globing(t_myglob *t, int pos);
char    *cuts(char *str, int x, int y);
int	first_match(t_myglob *t, int i);
int    second_match(t_myglob *t, int i);
int     check_crochet(char *str, int i);
char    *globing(char *str);
char	*glob_ret(int ret, t_myglob t);

#endif
