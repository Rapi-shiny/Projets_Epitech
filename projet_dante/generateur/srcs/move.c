/*
** move.c for move.c in /home/joly_q/Dante/dante/parfait/srcs
** 
** Made by JOLY Alan
** Login   <joly_q@epitech.net>
** 
** Started on  Sun May 22 21:50:05 2016 JOLY Alan
** Last update Sat May 28 12:13:37 2016 Ludovic BARRETEAU
*/

#include "generator.h"

void    up(t_all *all)
{
  all->lab[all->y - 2][all->x] = '*';
  all->lab[all->y - 1][all->x] = '*';
  all->y -= 2;
}

void    right(t_all *all)
{
  all->lab[all->y][all->x + 1] = '*';
  all->lab[all->y][all->x + 2] = '*';
  all->x += 2;
}

void    down(t_all *all)
{
  all->lab[all->y + 1][all->x] = '*';
  all->lab[all->y + 2][all->x] = '*';
  all->y += 2;
}

void    left(t_all *all)
{
  all->lab[all->y][all->x - 1] = '*';
  all->lab[all->y][all->x - 2] = '*';
  all->x -= 2;
}

int     my_strcmp(char *s1, char *s2)
{
  int   i;
  int   result;

  i= 0;
  result = 0;
  while (s1[i] != '\0' && result == 0 && s2[i] != '\0')
    {
      if (s1[i] < s2[i] && result == 0)
        result = -1;
      if (s1[i] > s2[i] && result == 0)
        result = 1;
      i++;
    }
  if (result == 0 && my_strlen(s1) > my_strlen(s2))
    return (1);
  if (result == 0 && my_strlen(s1) < my_strlen(s2))
    return (-1);
  return (result);
}
