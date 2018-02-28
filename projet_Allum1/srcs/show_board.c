/*
** show_board.c for sho_board in /home/barret_l/rendu/Prog_elem/CPE_2015_Allum1
** 
** Made by Ludovic BARRETEAU
** Login   <barret_l@epitech.net>
** 
** Started on  Tue Feb  9 15:07:00 2016 Ludovic BARRETEAU
** Last update Fri Feb 19 11:45:44 2016 Ludovic BARRETEAU
*/

#include "../includes/allu.h"

int     print_space(int columns, int check, t_allu *allu)
{
  int   nb_space;

  nb_space = 0;
  if (check == 1)
    {
      write(1, "*", 1);
      while (nb_space++ < allu->nb_space_front[allu->lines])
        {
          write(1, " ", 1);
          columns++;
        }
    }
  if (check == 2)
    {
      while (nb_space++ < allu->nb_space_back[allu->lines])
        write(1, " ", 1);
      write(1, "*", 1);
      write(1, "\n", 1);
    }
  return (columns);
}

void    show_stars()
{
  int   columns;

  columns = 0;
  while (columns++ < (4 * 2 + 1))
    write(1, "*", 1);
  write(1, "\n", 1);
}

void    print_board(t_allu *allu)
{
  allu->lines = 0;
  show_stars();
  while (allu->lines < 4)
    {
      allu->columns = print_space(0, 1, allu);
      allu->nb_space = 0;
      while (allu->nb_space++ < allu->tab_allu[allu->lines])
        {
          write(1, "|", 1);
          allu->columns++;
        }
      print_space(allu->columns, 2, allu);
      allu->lines++;
    }
  show_stars();
}

void            print_updated_board_game(int line\
					 , int nb_matches, t_allu *allu)
{
  allu->tab_allu[line - 1] -= nb_matches;
  allu->nb_space_back[line - 1] += nb_matches;
  print_board(allu);
}

