/*
** errors.c for errors in /home/barret_l/rendu/Prog_elem/CPE_2015_Allum1
** 
** Made by Ludovic BARRETEAU
** Login   <barret_l@epitech.net>
** 
** Started on  Tue Feb  9 15:05:37 2016 Ludovic BARRETEAU
** Last update Wed Feb 24 17:43:51 2016 Ludovic BARRETEAU
*/

#include "../includes/allu.h"

void    show_errors_matches(int nb_matches, t_allu *allu, int line)
{
  if (nb_matches >= 1 && nb_matches <= allu->tab_allu[line - 1])
    {
      my_printf("Player removed %i match(es) from line %i\n"\
		, nb_matches, line);
      print_updated_board_game(line, nb_matches, allu);
      allu->turn = 1;
    }
  else
    {
      if (nb_matches < 0)
        my_printf("Error: invalid input (positive number expected)\n");
      if (nb_matches == 0)
        my_printf("Error: you have to remove at least one match\n");
      if (nb_matches > allu->tab_allu[line - 1])
        my_printf("Error: not enough matches on this line\n");
      allu->error = 1;
    }
}

int	show_errors_line(int line, t_allu *allu)
{
  int   nb_matches;
  char	*matches;

  if (line >= 1 && line <= 4)
    {
      if (allu->tab_allu[line - 1] != 0)
        {
          my_printf("Matches: ");
	  matches = get_next_line(0);
	  if (matches == NULL)
	    return (-1);
	  nb_matches = my_getnbr(matches);
          show_errors_matches(nb_matches, allu, line);
	}
      else
	{
	  my_printf("Error: this line is empty\n");
	  allu->error = 1;
	}
    }
  else
    show_errors_line_bis(line, allu);
  return (0);
}

void	show_errors_line_bis(int line, t_allu *allu)
{
  if (line == 0 || line > 4)
    my_printf("Error: this line is out of range\n");
  else
    my_printf("Error: invalid input (positive number expected)\n");
  allu->error = 1;
}
