/*
** directions.c for  in /home/barret_l/rendu/Initiation_IA/dante
** 
** Made by Ludovic BARRETEAU
** Login   <barret_l@epitech.net>
** 
** Started on  Mon May  2 11:10:40 2016 Ludovic BARRETEAU
** Last update Mon May  9 15:12:23 2016 Ludovic BARRETEAU
*/

#include "dante.h"

int	check_dir(t_maze *maze, int x, int y, int check)
{
  if (y < 0 || x >= maze->cols || y >= maze->lines || x < 0)
    return (2);
  if (maze->tab_algo[y][x] != '*' && check == 0)
    return (1);
  if (maze->tab_algo[y][x] != '*' && check == 1)
    return (1);
  if (maze->tab_algo[y][x] != '*' && check == 2)
    return (1);
  if (maze->tab_algo[y][x] != '*' && check == 3)
    return (1);
  return (0);
}

int	check_imp(t_maze *maze, int x, int y)
{
  maze->num_free = -1;
  maze->nb_imp = 0;
  check_imp_up(maze, x, y);
  check_imp_right(maze, x, y);
  check_imp_down(maze, x, y);
  check_imp_left(maze, x, y);
  return (0);
}

int	check_end(t_maze *maze, int x, int y)
{
  if (x == maze->cols - 1 && y == maze->lines - 1)
    return (0);
  return (1);
}
