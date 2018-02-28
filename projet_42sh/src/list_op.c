/*
** list_op.c for list_op in /home/jahan_a/trashtest/tab_op
** 
** Made by antoine jahan
** Login   <jahan_a@epitech.net>
** 
** Started on  Fri Jun  3 11:04:00 2016 antoine jahan
** Last update Fri Jun  3 13:39:14 2016 Celenzo CRESPIN
*/

#include "minishell.h"

int	my_slen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

char	*list_op(char *str)
{
  char	*new;
  int	j;
  int	i;

  i = 0;
  if ((new = malloc(sizeof(*new) * (nb_pieces(str) + 1))) == NULL)
    exit(0);
  j = 0;
  while (str[i])
    {
      if (str[i] == '&')
        if (i + 1 < my_slen(str) && str[i + 1] == '&')
	  {
	    new[j++] = AND_OPERATOR;
	    i++;
	  }
      if (str[i] == '|')
        if (i + 1 < my_slen(str) && str[i + 1] == '|')
	  {
	    new[j++] = OR_OPERATOR;
	    i++;
	  }
      i++;
    }
  return (new[j] = 0, new);
}
