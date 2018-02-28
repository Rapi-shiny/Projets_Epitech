/*
** directions_bis.c for  in /home/barret_l/rendu/Initiation_IA/dante
** 
** Made by Ludovic BARRETEAU
** Login   <barret_l@epitech.net>
** 
** Started on  Mon May  9 14:22:07 2016 Ludovic BARRETEAU
** Last update Tue May 10 10:35:38 2016 Ludovic BARRETEAU
*/

#include "dante.h"

void	check_imp_up(t_maze *maze, int x, int y)
{
  if (check_dir(maze, x, y - 1, 0) == 2
      || (check_dir(maze, x, y - 1, 0) == 1
          && maze->tab_algo[y - 1][x] != 'o'))
    maze->nb_imp++;
  else
    maze->num_free = 0;
}

void	check_imp_right(t_maze *maze, int x, int y)
{
  if (check_dir(maze, x + 1, y, 1) == 2
      || (check_dir(maze, x + 1, y, 1) == 1
          && maze->tab_algo[y][x + 1] != 'o'))
    maze->nb_imp++;
  else
    maze->num_free = 1;
}

void	check_imp_down(t_maze *maze, int x, int y)
{
  if (check_dir(maze, x, y + 1, 2) == 2
      || (check_dir(maze, x, y + 1, 2) == 1
          && maze->tab_algo[y + 1][x] != 'o'))
    maze->nb_imp++;
  else
    maze->num_free = 2;
}

void	check_imp_left(t_maze *maze, int x, int y)
{
  if (check_dir(maze, x - 1, y, 3) == 2
      || (check_dir(maze, x - 1, y, 3) == 1
          && maze->tab_algo[y][x - 1] != 'o'))
    maze->nb_imp++;
  else
    maze->num_free = 3;
}

void    go_back(t_maze *maze, int *x, int *y)
{
  if (maze->num_free != -1)
    {
      maze->tab_algo[*y][*x] = '+';
    }
  if (maze->num_free == 0)
    {
      move_up(maze, x, y);
      *y = *y - 1;
    }
  if (maze->num_free == 1)
    {
      move_right(maze, x, y);
      *x = *x + 1;
    }
  if (maze->num_free == 2)
    {
      move_down(maze, x, y);
      *y = *y + 1;
    }
  if (maze->num_free == 3)
    {
      move_left(maze, x, y);
      *x = *x - 1;
    }
}
