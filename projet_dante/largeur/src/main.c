/*
** main.c for  in /home/barret_l/rendu/Initiation_IA/dante/solver_larg
** 
** Made by Ludovic BARRETEAU
** Login   <barret_l@epitech.net>
** 
** Started on  Tue May 10 13:36:06 2016 Ludovic BARRETEAU
** Last update Sat May 21 14:52:32 2016 Ludovic BARRETEAU
*/

#include "dante.h"

void    free_tab(char **tab)
{
  int   i;

  i = 0;
  while (tab[i] != 0)
    free(tab[i++]);
  free(tab);
}

int     create_tabs(t_maze *maze, char *str)
{
  char  *laby;

  laby = get_laby(str);
  if (laby == NULL)
    {
      my_putstr("Error: No such file.\n", 2);
      return (1);
    }
  maze->tab = str_to_tab(maze->tab, laby);
  maze->tab_algo = str_to_tab(maze->tab_algo, laby);
  maze->lines = get_nbr_lines(laby);
  maze->cols = get_nbr_cols(laby);
  return (0);
}

int	main(int argc, char **argv)
{
  t_maze maze;

  if (argc > 1)
    {
      if (create_tabs(&maze, argv[1]) == 1)
        return (1);
      start_solver(&maze);
      if (maze.tab[maze.lines - 1][maze.cols - 1] != 'o')
	printf("No solution found\n");
      else
	show_tab(&maze);
      free_tab(maze.tab);
      free_tab(maze.tab_algo);
    }
  return (0);
}
