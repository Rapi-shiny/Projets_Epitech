/*
** imperfect.c for dante in /home/joly_q/Dante/dante/generateur/srcs
** 
** Made by JOLY Alan
** Login   <joly_q@epitech.net>
** 
** Started on  Sun May 29 00:21:05 2016 JOLY Alan
** Last update Sun May 29 00:32:01 2016 JOLY Alan
*/

#include "generator.h"

void	algo_imp(t_all *all)
{
  int   ran;

  while (all->y != (all->height - 1)  || all->x != (all->width - 1))
    {
      ran = rand() % 100;
      if ((ran >= 0 && ran <= 19) && all->y - 2 >= 0)
        up(all);
      if ((ran >= 20 && ran <= 50)&& all->x + 2 < all->width)
        right(all);
      if ((ran >= 51 && ran <= 80) && all->y + 2 < all->height)
        down(all);
      if ((ran >= 81 && ran <= 99) && all->x - 2 >= 0)
        left(all);
    }
}
