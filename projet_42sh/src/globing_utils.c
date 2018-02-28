/*
** globing_utils.c for glob_utils in /home/jahan_a/trashtest/globing
** 
** Made by antoine jahan
** Login   <jahan_a@epitech.net>
** 
** Started on  Tue May 31 13:39:44 2016 antoine jahan
** Last update Sat Jun  4 16:28:10 2016 antoine jahan
*/

#include "globing.h"

int     check_crochet(char *str, int i)
{
  while (str[i] != ']')
    {
      if (str[i] == 0 || str[i] == ' ' || str[i] == '\t')
        return (-1);
      i++;
    }
  return (0);
}

char    *cuts(char *str, int x, int y)
{
  char  *new;
  int   j;

  if ((new = malloc(sizeof(*new) * (y - x + 1))) == NULL)
    exit(0);
  j = 0;
  while (x < y)
    {
      new[j] = str[x];
      x++;
      j++;
    }
  new[j] = 0;
  return (new);
}

char	*glob_ret(int ret, t_myglob t)
{
  if (ret == -1)
    return (NULL);
  if (ret == 2)
    return (t.str);
  return (t.new);
}
