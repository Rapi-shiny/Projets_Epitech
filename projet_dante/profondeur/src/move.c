/*
** move.c for  in /home/barret_l/rendu/Initiation_IA/dante
** 
** Made by Ludovic BARRETEAU
** Login   <barret_l@epitech.net>
** 
** Started on  Mon May  2 14:37:30 2016 Ludovic BARRETEAU
** Last update Tue May 10 10:35:47 2016 Ludovic BARRETEAU
*/

#include "dante.h"

int	check_move(t_maze *maze, int x, int y, int i)
{
  if (i != 1 ||
      ((y > 0 && maze->tab_algo[y - 1][x] == '*')
      || (y < maze->lines -1 && maze->tab_algo[y + 1][x] == '*')
      || (x > 0 && maze->tab_algo[y][x - 1] == '*')
       || (x < maze->cols - 1 && maze->tab_algo[y][x + 1] == '*')
       || x == maze->cols - 1
       || y == maze->lines - 1))
    return (1);
  return (0);
}

void	move_up(t_maze *maze, int *x, int *y)
{
  int	i;

  i = 0;
  while (check_dir(maze, *x, *y - 1, 0) == 0
	 && check_dir(maze, *x + 1, *y, 1) != 0)
    {
      maze->tab_algo[*y][*x] = 'o';
      *y = *y - 1;
      maze->tab_algo[*y][*x] = 'o';
      i++;
    }
  if ((*y - 1) <= maze->lines - 1 && check_move(maze, *x, *y, i) == 0)
    {
      maze->tab_algo[*y][*x] = '@';
      *y = *y + 1;
    }
}

void    move_right(t_maze *maze, int *x, int *y)
{
  int	i;

  i = 0;
  while (check_dir(maze, *x + 1, *y, 1) == 0)
    {
      maze->tab_algo[*y][*x] = 'o';
      *x = *x + 1;
      maze->tab_algo[*y][*x] = 'o';
      i++;
    }
  if ((*x + 1) <= maze->cols - 1 && check_move(maze, *x, *y, i) == 0)
    {
      maze->tab_algo[*y][*x] = '#';
      *x = *x - 1;
    }
}

void    move_left(t_maze *maze, int *x, int *y)
{
  int	i;

  i = 0;
  while (check_dir(maze, *x - 1, *y, 3) == 0
	 && check_dir(maze, *x, *y + 1, 2) != 0)
    {
      maze->tab_algo[*y][*x] = 'o';
      *x = *x - 1;
      maze->tab_algo[*y][*x] = 'o';
      i++;
    }
  if ((*x - 1) <= maze->lines - 1 && check_move(maze, *x, *y, i) == 0)
    {
      maze->tab_algo[*y][*x] = '&';
      *x = *x + 1;
    }
}

void    move_down(t_maze *maze, int *x, int *y)
{
  int	i;

  i = 0;
  while (check_dir(maze, *x, *y + 1, 2) == 0
	 && check_dir(maze, *x + 1, *y, 1) != 0)
    {
      maze->tab_algo[*y][*x] = 'o';
      *y = *y + 1;
      maze->tab_algo[*y][*x] = 'o';
      i++;
    }
  if ((*y + 1) <= maze->lines - 1 && check_move(maze, *x, *y, i) == 0)
    {
      maze->tab_algo[*y][*x] = '=';
      *y = *y - 1;
    }
}
