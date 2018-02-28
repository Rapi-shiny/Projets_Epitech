/*
** tab_operators.c for tab_operators in /home/jahan_a/PSU/PSU_2015_42sh/src
** 
** Made by antoine jahan
** Login   <jahan_a@epitech.net>
** 
** Started on  Thu Jun  2 18:36:35 2016 antoine jahan
** Last update Fri Jun  3 12:22:06 2016 antoine jahan
*/

#include "minishell.h"

int		jump_to_next(char *str, int i)
{
  while (str[i])
    {
      if (str[i] == '&')
	if (i + 1 < my_slen(str) && str[i + 1] == '&')
	  return (i);
      if (str[i] == '|')
	if (i + 1 < my_slen(str) && str[i + 1] == '|')
	  return (i);
      i++;
    }
  return (i);
}

int		nb_pieces(char *str)
{
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  while (str[i])
    {
      if (str[i] == '&')
	if (i + 1 < my_slen(str) && str[i + 1] == '&')
	  {
	    nb++;
	    i++;
	  }
      if (str[i] == '|')
	if (i + 1 < my_slen(str) && str[i + 1] == '|')
	  {
	    nb++;
	    i++;
	  }
      i++;
    }
  return (nb);
}

char		*next_pieces(char *str, int res)
{
  static int	i;
  int		j;
  int		k;
  char		*new;

  k = 0;
  if (res == 1)
    i = 0;
  else
    {
      j = jump_to_next(str, i);
      if ((new = malloc(sizeof(*new) * (j - i + 1))) == NULL)
	exit(0);
      while (i < j)
	{
	  new[k] = str[i];
	  k++;
	  i++;
	}
      new[k] = 0;
      i += 2;
      return (new);
    }
  return (NULL);
}

char		**tab_operator(char *str)
{
  int	nb;
  int	i;
  char	**tab;

  nb = nb_pieces(str) + 1;
  if ((tab = malloc(sizeof(*tab) * (nb + 1))) == NULL)
    exit(0);
  i = 0;
  while (i < nb)
    {
      tab[i] = next_pieces(str, 0);
      i++;
    }
  tab[i] = NULL;
  next_pieces(str, 1);
  return (tab);
}
