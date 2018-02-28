/*
** generator.h for dante in /home/joly_q/Dante
** 
** Made by JOLY Alan
** Login   <joly_q@epitech.net>
** 
** Started on  Fri May 20 23:23:35 2016 JOLY Alan
** Last update Sun May 29 00:28:48 2016 JOLY Alan
*/

#ifndef GENERATOR_H_
# define GENERATOR_H_

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

typedef struct  s_all
{
  int		width;
  int		height;
  int		x;
  int		y;
  int		check;
  char          **lab;
}               t_all;

void	up(t_all *);
void	left(t_all *);
void	right(t_all *);
void	down(t_all *);
int     my_strcmp(char *s1, char *s2);
int     fill(t_all *all);
void    algo2(t_all *all, int ran);
int     algo(t_all *all);
int     my_strlen(char *str);
void	algo_imp(t_all *all);

#endif
