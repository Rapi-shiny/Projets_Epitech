/*
** main.c for main in /home/barret_l/rendu/Prog_elem/CPE_2015_Allum1
** 
** Made by Ludovic BARRETEAU
** Login   <barret_l@epitech.net>
** 
** Started on  Tue Feb  9 11:37:38 2016 Ludovic BARRETEAU
** Last update Sun Feb 21 11:01:52 2016 Ludovic BARRETEAU
*/

#include "../includes/allu.h"

int	check_end(t_allu *allu)
{
  int	i;

  i = 0;
  while (i < 4)
    {
      if (allu->tab_allu[i] != 0)
	return (1);
      i++;
    }
  return (0);
}

int	calc_nb_allu(t_allu *allu)
{
  int	i;
  int	result;

  i = 0;
  result = 0;
  while (i < 4)
    result += allu->tab_allu[i++];
  return (result);
}

int		main()
{
  t_allu        allu;
  int           i;
  int           nb;

  i = 0;
  nb = 1;
  allu.max_allu = 16;
  allu.error = 0;
  while (i < 4)
    {
      allu.tab_allu[i++] = nb;
      nb +=2;
    }
  allu.max_size = 7;
  nb = 0;
  i = 0;
  while (i < 4)
    {
      allu.nb_space_front[i] = (allu.max_size - allu.tab_allu[i]) / 2;
      allu.nb_space_back[i] = allu.nb_space_front[i];
      i++;
    }
  game(&allu);
  return (0);
}
