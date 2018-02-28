/*
** algo.c for  in /home/barret_l/rendu/Initiation_IA/dante/solver_larg/src
** 
** Made by Ludovic BARRETEAU
** Login   <barret_l@epitech.net>
** 
** Started on  Wed May 18 13:42:10 2016 Ludovic BARRETEAU
** Last update Sat May 21 11:49:35 2016 Ludovic BARRETEAU
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

int	check_list(t_graph *lane, t_maze *maze)
{
  t_graph     *i;

  if ((i = malloc(sizeof(*i))) == NULL)
    return (1);
  i = lane->next;
  while (i != lane)
    {
      if (maze->tab_algo[i->y][i->x] == '*' || maze->tab_algo[i->y][i->x] == '#')
	maze->tab_algo[i->y][i->x] = 'o';
      check_up(maze, lane, i);
      check_right(maze, lane, i);
      check_left(maze, lane, i);
      check_down(maze, lane, i);
      if (i->x == maze->cols -1 && i->y == maze->lines -1)
	{
	  maze->tab_algo[i->y][i->x] = 'o';
	  return (0);
	}
      i = i->next;
    }
  return (0);
}

t_graph	*get_end(t_graph *lane, t_maze *maze)
{
  t_graph     *i;

  if ((i = malloc(sizeof(*i))) == NULL)
    return (NULL);
  i = lane->prev;
  while (i != lane)
    {
      if (i->x == maze->cols - 1 && i->y == maze->lines - 1)
	return (i);
      i = i->prev;
    }
  return (i);
}

void	solve_laby(t_graph *lane, t_maze *maze)
{
  t_graph *end;

  end = get_end(lane, maze);
  while (end->x != 0 || end->y != 0)
    {
      maze->tab[end->y][end->x] = 'o';
      end = end->parent;
    }
  maze->tab[0][0] = 'o';
}
