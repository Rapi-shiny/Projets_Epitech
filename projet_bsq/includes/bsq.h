/*
** bsq.h for bsq in /home/barret_l/rendu/bootstrap/CPE_2015_bsq_bootstrap
**
** Made by Ludovic BARRETEAU
** Login   <barret_l@epitech.net>
**
** Started on  Tue Nov 24 10:08:06 2015 Ludovic BARRETEAU
** Last update Sat Dec 19 18:26:41 2015 Ludovic BARRETEAU
*/

#ifndef BSQ_H_
#define BSQ_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "my.h"

typedef	struct	s_square
{
  int	pos_x;
  int	pos_y;
  int	size;
}	t_square;

typedef struct s_algo
{
  int	max_size;
  int	pos_x;
  int	pos_y;
  int	line;
  int	col;
  int	check;
}	t_algo;

void    add_in_tab(char *str, int nbr_lines, int nbr_col, t_square square);
char    *modify_area(char *str);
int     get_col(char *str);
int     my_bsq(char *buffer);
void    my_aff_tab(int nb_line, int nb_col, char tab[nb_line][nb_col], int len);
void    my_add_square(int nb_line, int nb_col, \
                      char tab[nb_line][nb_col], t_square square);
int     check_line(t_algo *algo, int nb_line\
                   , int nb_col, char tab[nb_line][nb_col]);
int             my_check_square(int nb_line, int nb_col\
                                , char tab[nb_line][nb_col], t_square *square);
int     get_lines(char *str);

#endif
