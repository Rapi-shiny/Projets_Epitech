/*
** bsq_bis.c for bsq_bis in /home/barret_l/rendu/bootstrap/CPE_2015_bsq_bootstrap
**
** Made by Ludovic BARRETEAU
** Login   <barret_l@epitech.net>
**
** Started on  Tue Nov 24 10:17:59 2015 Ludovic BARRETEAU
** Last update Sat Dec 19 18:18:05 2015 Ludovic BARRETEAU
*/

#include "includes/bsq.h"

void	my_aff_tab(int nb_line, int nb_col, char tab[nb_line][nb_col], int len)
{
  int   i;
  int   col;
  int   line;

  i = 0;
  col = 0;
  line = 0;
  while (col < nb_col || line < nb_line -1)
    {
      if (col >= nb_col)
        {
          col = 0;
          line++;
          my_putchar('\n');
        }
      my_putchar(tab[line][col]);
      i++;
      col++;
    }
  my_putchar('\n');
}

void	my_add_square(int nb_line, int nb_col, \
		      char tab[nb_line][nb_col], t_square square)
{
  int	pos_x_save;
  int	line;
  int	col;

  my_check_square(nb_line, nb_col, tab, &square);
  line = square.pos_y;
  col = square.pos_x;
  square.size--;
  while (line < square.pos_y + square.size)
    {
      col = square.pos_x;
      while (col < square.pos_x + square.size)
	{
	  tab[line][col] = 'x';
	  col++;
	}
      line++;
    }
}

int	check_line(t_algo *algo, int nb_line\
		   , int nb_col, char tab[nb_line][nb_col])
{
  int	i;
  int	j;

  j = algo->line;
  if (tab[algo->line][algo->col] == '.')
    {
      while (j < algo->line + algo->max_size)
	{
	  i = algo->col;
	  while (i < algo->col + algo->max_size)
	    {
	      if (tab[j][i] != '.')
		return (1);
	      i++;
	    }
	  j++;
	}
      return (0);
    }
  return (-1);
}

int		my_check_square(int nb_line, int nb_col\
				, char tab[nb_line][nb_col], t_square *square)
{
  t_algo	algo;

  algo.line = 0;
  algo.max_size = 1;
  algo.check = 0;
  while (algo.line < nb_line - 1)
    {
      algo.col = 0;
      while (algo.col < nb_col)
	{
	  algo.check = check_line(&algo, nb_line, nb_col, tab);
	  if (algo.check == 0)
	    {
	      square->size = algo.max_size;
	      square->pos_x = algo.col;
	      square->pos_y = algo.line;
   	      algo.max_size++;
	    }
	  if (algo.check == 1 || algo.check == -1)
	      algo.col++;
	}
      algo.line++;
    }
  square->size = algo.max_size;
  return (0);
}

int	get_lines(char *str)
{
  int	i;
  int	lines;

  i = 0;
  lines = 0;
  while (str[i])
    {
      if (str[i] == '\n')
	lines++;
      i++;
    }
  return (lines);
}
