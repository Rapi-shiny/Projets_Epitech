/*
** my_getnbr.c for LOL in /home/crespi_c/rendu
** 
** Made by Celenzo CRESPIN
** Login   <crespi_c@epitech.net>
** 
** Started on  Thu Oct 15 14:32:56 2015 Celenzo CRESPIN
** Last update Sun Jan 24 17:00:10 2016 Celenzo CRESPIN
*/

#include "minishell.h"

int	processnbr(char *str, int n, int a)
{
  int	nbr;

  nbr = 0;
  while (str[n] && ((str[n] <= '9') && (str[n] >= '0')))
    {
      nbr = (10 * nbr) + (str[n++] - 48);
    }
  if (n < my_strlen(str) - 1)
    return (0);
  nbr = nbr * a;
  return (nbr);
}

int	verif(char *str, int n)
{
  char	lim[10] = "2147483647";
  int	i;

  i = 0;
  lim[9] = lim[9] + n;
  if (my_strlen(str) > 10)
    return (1);
  if (my_strlen(str) == 10)
    while (lim[i])
      {
	if (str[n++] > lim[i++])
	  return (1);
	else
	  return (0);
      }
  if (my_strlen(str) < 10)
    return (0);
  return (0);
}

int	my_getnbr(char *str)
{
  int	a;
  int	n;
  int	i;

  a = 1;
  n = 0;
  if (str[0] == '-')
    {
      a = -1;
      n = 1;
    }
  i = verif(str, n);
  if (i == 1)
    return (1);
  return (processnbr(str, n, a));
}
