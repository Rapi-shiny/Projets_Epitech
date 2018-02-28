/*
** game.c for game in /home/barret_l/rendu/Prog_elem/CPE_2015_Allum1
** 
** Made by Ludovic BARRETEAU
** Login   <barret_l@epitech.net>
** 
** Started on  Wed Feb 10 11:29:10 2016 Ludovic BARRETEAU
** Last update Wed Feb 24 17:50:34 2016 Ludovic BARRETEAU
*/

#include "../includes/allu.h"

void    game_ai(t_allu *allu)
{
  int   nb_allu;
  int   check;

  check = 0;
  nb_allu = calc_nb_allu(allu);
  srand(getpid());
  while (check == 0)
    {
      if (nb_allu < (allu->max_allu / 2))
	check = game_ai_one(allu, nb_allu);
      else
	check = game_ai_two(allu);
    }
}

int	game_ai_one(t_allu *allu, int nb_allu)
{
  int	line;
  int	matches;

  line = rand() % 4 + 1;
  if (allu->tab_allu[line -1] > 0)
    matches = allu->tab_allu[line - 1];
  if (allu->tab_allu[line - 1] > 0 \
              && matches <= allu->tab_allu[line - 1]    \
      && matches > 0)
    {
      if (matches == nb_allu && nb_allu > 1)
	matches--;
      my_printf("AI removed %d match(es) from line %d\n"\
		, matches, line);
      print_updated_board_game(line, matches, allu);
      return (1);
    }
  return (0);
}

int	game_ai_two(t_allu *allu)
{
  int	line;
  int	matches;

  line = rand() % 4 + 1;
  if (allu->tab_allu[line -1] > 0)
    matches = rand() % (allu->tab_allu[line - 1]) + 1;
  if (allu->tab_allu[line - 1] > 0 \
              && matches <= allu->tab_allu[line - 1]    \
      && matches > 0)
    {
      my_printf("AI removed %d match(es) from line %d\n"\
		, matches, line);
      print_updated_board_game(line, matches, allu);
      return (1);
    }
  return (0);
}

int    game(t_allu *allu)
{
  int   line;
  char	*my_line;

  print_board(allu);
  allu->turn = 0;
  line  = 0;
  my_line = NULL;
  while (check_end(allu) == 1)
    {
      if (game_bis(allu, my_line, line) == -1)
	return (-1);
    }
  if (allu->turn == 1)
    my_printf("You lost, too bad..\n");
  else
    my_printf("I lost.. snif.. but I'll get you next time!!\n");
  return (0);
}

int	game_bis(t_allu *allu, char *my_line, int line)
{
  if (allu->turn == 0)
    {
      if (allu->error  == 0)
	my_printf("\nYour turn:\nLine: ");
      else
	{
	  allu->error = 0;
	  my_printf("Line: ");
	}
      my_line = get_next_line(0);
      if (my_line == NULL)
	return (-1);
      line = my_getnbr(my_line);
      if (show_errors_line(line, allu) == -1)
	return (-1);
    }
  else
    {
      my_printf("\nAI's turn...\n");
      game_ai(allu);
      allu->turn = 0;
    }
  return (0);
}
