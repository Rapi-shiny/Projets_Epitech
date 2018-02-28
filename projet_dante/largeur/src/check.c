/*
** check.c for  in /home/barret_l/rendu/Initiation_IA/dante/largeur/src
** 
** Made by Ludovic BARRETEAU
** Login   <barret_l@epitech.net>
** 
** Started on  Sat May 21 11:29:55 2016 Ludovic BARRETEAU
** Last update Sat May 21 11:49:07 2016 Ludovic BARRETEAU
*/

#include "dante.h"

void	check_up(t_maze *maze, t_graph *lane, t_graph *i)
{
  if (check_dir(maze, i->x, i->y - 1, 0) == 0)
    {
      add_after(lane, i->x, i->y - 1, i);
      maze->tab_algo[i->y - 1][i->x] = '#';
    }
}

void    check_right(t_maze *maze, t_graph *lane, t_graph *i)
{
  if (check_dir(maze, i->x + 1, i->y, 1) == 0)
    {
      add_after(lane, i->x + 1, i->y, i);
      maze->tab_algo[i->y][i->x + 1] = '#';
    }
}

void    check_down(t_maze *maze, t_graph *lane, t_graph *i)
{
  if (check_dir(maze, i->x, i->y + 1, 2) == 0)
    {
      add_after(lane, i->x, i->y + 1, i);
      maze->tab_algo[i->y + 1][i->x] = '#';
    }
}

void    check_left(t_maze *maze, t_graph *lane, t_graph *i)
{
  if (check_dir(maze, i->x - 1, i->y, 3) == 0)
    {
      add_after(lane, i->x - 1, i->y, i);
      maze->tab_algo[i->y][i->x - 1] = '#';
    }
}
