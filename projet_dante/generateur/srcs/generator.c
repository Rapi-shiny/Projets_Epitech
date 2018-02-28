/*
** generator.c for dante in /home/joly_q/Dante
** 
** Made by JOLY Alan
** Login   <joly_q@epitech.net>
** 
** Started on  Fri May 20 23:23:10 2016 JOLY Alan
** Last update Sun May 29 00:35:16 2016 JOLY Alan
*/

#include "generator.h"

int	fill(t_all *all)
{
  if ((all->lab = malloc(sizeof(char*) * all->height + 1)) == NULL)
    return (-1);
  all->y = 0;
  while (all->y < all->height)
    {
      if ((all->lab[all->y] = malloc(sizeof(char) * all->width + 2)) == NULL)
	return (-1);
      all->x = 0;
      while (all->x < all->width)
	{
	  all->lab[all->y][all->x] = 'X';
	  all->x++;
	}
      all->lab[all->y][all->x] = '\n';
      all->lab[all->y][all->x + 1] = 0;
      all->y++;
    }
  all->lab[all->y - 1][all->x] = 0;
  all->lab[all->y] = NULL;
  return (0);
}

void	algo2(t_all *all, int ran)
{
      if ((ran >= 51 && ran <= 80) && all->y + 2 < all->height
	  && (all->lab[all->y + 1][all->x] != 'X'
              || all->lab[all->y + 2][all->x] == 'X'))
	down(all);
      if ((ran >= 81 && ran <= 99) && all->x - 2 >= 0
	  && (all->lab[all->y][all->x - 1] != 'X'
              || all->lab[all->y][all->x - 2] == 'X'))
	left(all);
}

int	algo(t_all *all)
{
  int	ran;
  int	i;

  i = 0;
  while (all->y != (all->height - 1)  || all->x != (all->width - 1))
    {
      i++;
      if (i == 1000000)
	return (-1);
      ran = rand() % 100;
      if ((ran >= 0 && ran <= 19) && all->y - 2 >= 0 &&
	  (all->lab[all->y - 1][all->x] != 'X'
	   || all->lab[all->y - 2][all->x] == 'X'))
	up(all);
      if ((ran >= 20 && ran <= 50)&& all->x + 2 < all->width
	  && (all->lab[all->y][all->x + 1] != 'X'
	      || all->lab[all->y][all->x + 2] == 'X'))
	right(all);
      algo2(all, ran);
    }
  return (0);
}

int	make(t_all *all, int check)
{
  fill(all);
  all->y = 0;
  all->x = 0;
  all->lab[all->y][all->x] = '*';
  if (all->width % 2 != 1)
    all->lab[all->y][++all->x] = '*';
  if (all->height % 2 != 1)
    all->lab[++all->y][all->x] = '*';
  if (check == 1)
    algo_imp(all);
  else
    {
      if (algo(all) == -1)
	make(all, 0);
    }
  all->y = 0;
  while (all->y < all->height)
    printf("%s", all->lab[all->y++]);
  return (0);
}

int	main(int ac, char **av)
{
  t_all	*all;

  srand(getpid());
  if (ac < 3 || ac > 4)
    printf("Usage: ./generateur width height [parfait]");
  else
    {
      if ((all = malloc(sizeof(t_all))) == NULL)
	return (-1);
      if ((all->width = atoi(av[1])) <= 0)
	return (-1);
      if ((all->height = atoi(av[2])) <= 0)
	return (-1);
	if (ac == 3)
	  make(all, 1);
	else
	  if ((my_strcmp(av[3], "parfait") == 0) && ac == 4)
	    make(all, 0);
	  else if ((my_strcmp(av[3], "imparfait") == 0) && ac == 4)
            make(all, 0);
    }
  printf("\n");
  return (0);
}
