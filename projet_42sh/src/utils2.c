/*
** stuff2.c for  in /home/crespi_c/rendu/Elementary_C/PSU_2015_minishell1
** 
** Made by Celenzo CRESPIN
** Login   <crespi_c@epitech.net>
** 
** Started on  Sun Jan 24 11:56:18 2016 Celenzo CRESPIN
** Last update Thu Apr 14 20:53:43 2016 Celenzo CRESPIN
*/

#include "minishell.h"

int		my_arraylen(char **tab)
{
  int		i;

  i = 0;
  while (tab[i++] != NULL);
  return (i);
}

char		*gtenv(char **ae, char *fnd)
{
  int		i;

  i = 0;
  while (ae[i])
    {
      if (check(ae[i], fnd) == 0)
	return (ae[i]);
      i++;
    }
  return (NULL);
}

char		*getvar(char *var)
{
  int		i;

  i = 0;
  if (var == NULL)
    return (NULL);
  while (var[i++] != '=');
  return (var + i);
}

char		verif_user(char *var)
{
  if (var == NULL)
    return ('$');
  if (my_strcmp(var + 5, ROOT_PRIV) == 0)
    return ('#');
  return ('$');
}
