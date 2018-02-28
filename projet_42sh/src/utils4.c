/*
** utils4.c for  in /home/crespi_c/rendu/PSU/PSU_2015_42sh/src
** 
** Made by Celenzo CRESPIN
** Login   <crespi_c@epitech.net>
** 
** Started on  Tue May 31 18:43:00 2016 Celenzo CRESPIN
** Last update Sun Jun  5 21:20:22 2016 Romain Hedouin
*/

#include "minishell.h"

int		dat_keeper(int to_stock, int to_ret)
{
  static int	i = 0;

  if (to_stock == 1)
    i = to_ret;
  else
    return i;
  return 0;
}

char		*verif_sd(char *buf, t_pipe *pp, char **ae)
{
  char		*out;

  if (buf[my_strlen(buf) - 2] == ' ')
    buf[my_strlen(buf) - 2] = 0;
  if (buf[my_strlen(buf) - 2] == '&')
    {
      buf[my_strlen(buf) - 2] = 0;
      pp->back = 0;
    }
  if (buf[my_strlen(buf) - 2] == ' ')
    buf[my_strlen(buf) - 2] = 0;
  if (buf[0] == '!')
    buf = my_strcat("history ", buf);
  if ((out = var_env(buf, ae, 0, 0)) != NULL)
    buf = out;
  else
    return NULL;
  out = globing(buf);
  if (out == NULL)
    return buf;
  return out;
}

int		my_strncmp(char *s1, char *s2, int n)
{
  int		i;

  i = 0;
  while (s1[i] && s2[i] && i < n)
    {
      if (s1[i] != s2[i])
	return -1;
      i++;
    }
  if (i < n)
    return -1;
  return 0;
}

int		verif_nb(char *s)
{
  int		i;

  i = 0;
  if (s[i] == '-')
    i++;
  while (s[i])
    if (s[i] >= '0' && s[i] <= '9')
      i++;
    else
      return -1;
  return 0;
}
