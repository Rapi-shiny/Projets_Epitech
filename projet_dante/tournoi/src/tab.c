/*
** tab.c for  in /home/barret_l/rendu/Initiation_IA/dante
** 
** Made by Ludovic BARRETEAU
** Login   <barret_l@epitech.net>
** 
** Started on  Sat Apr 30 11:06:01 2016 Ludovic BARRETEAU
** Last update Wed May 11 10:44:37 2016 Ludovic BARRETEAU
*/

#include "dante.h"

int     get_nbr_lines(char *str)
{
  int   i;
  int   nbr;

  i = 0;
  nbr = 0;
  while (str[i])
    {
      if (str[i] == '\n')
        nbr++;
      i++;
    }
  return (nbr);
}

int     get_nbr_cols(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\n' && str[i])
    i++;
  return (i);
}

char	**str_to_tab(char **tab, char *str)
{
  int   i;
  int   j;
  int   lines;
  int   k;

  lines = get_nbr_lines(str);
  if ((tab = malloc(sizeof(tab) * (lines + 2))) == NULL)
    return (NULL);
  i = 0;
  k = 0;
  while (i <= lines)
    {
      j = 0;
      if ((tab[i] = malloc(sizeof(tab[i]) * (get_nbr_cols(str) + 2))) == NULL)
        return (NULL);
      while (j <= get_nbr_cols(str) && str[k] != '\n')
	tab[i][j++] = str[k++];
      tab[i++][j] = 0;
      k++;
    }
  tab[i] = 0;
  return (tab);
}

void    show_tab(t_maze *maze)
{
  int   i;

  i = 0;
  while (maze->tab[i])
    {
      my_putstr(maze->tab[i++], 1);
      if (maze->tab[i])
	my_putstr("\n", 1);
    }
}

void    show_tab2(t_maze *maze)
{
  int   i;

  i = 0;
  while (maze->tab_algo[i])
    {
      my_putstr(maze->tab_algo[i++], 1);
      if (maze->tab_algo[i])
	my_putstr("\n", 1);
    }
}
