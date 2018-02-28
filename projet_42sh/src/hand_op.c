/*
** hand_op.c for hand_op in /home/jahan_a/PSU/PSU_2015_42sh
** 
** Made by antoine jahan
** Login   <jahan_a@epitech.net>
** 
** Started on  Fri Jun  3 12:36:06 2016 antoine jahan
** Last update Sun Jun  5 16:44:53 2016 antoine jahan
*/

#include "minishell.h"

int	check_cmd_null(char *str)
{
  int	i;

  i = 0;
  while ((str[i] == ' ' || str[i] == '\t') && str[i] != 0)
    i++;
  if (str[i] == 0)
    return (1);
  return (0);
}

int	hand_op(char *str, char **ae)
{
  int	sig;
  int	i;
  int	j;
  char	**tab;
  char	*ope;

  sig = 2;
  ope = list_op(str);
  tab = tab_operator(str);
  i = 0;
  j = 0;
  while (tab[i])
    {
      if (check_cmd_null(tab[i]) == 1 && ope[j] == OR_OPERATOR)
	return (printf(INV_NULL_CMD), free_all("sw", ope, tab), sig);
      if (check_cmd_null(tab[i]) == 1 && ope[j] == AND_OPERATOR)
	i++;
      sig = recurs_pipes(tab[i], ae);
      if ((dat_keeper(0, 0) != 0 && ope[j] == AND_OPERATOR)
	  || (dat_keeper(0, 0) == 0 && ope[j] == OR_OPERATOR))
	i++;
      i++;
      j++;
    }
  return (free_all("sw", ope, tab), sig);
}
