/*
** laby.c for  in /home/barret_l/rendu/Initiation_IA/dante
** 
** Made by Ludovic BARRETEAU
** Login   <barret_l@epitech.net>
** 
** Started on  Sat Apr 30 11:02:06 2016 Ludovic BARRETEAU
** Last update Sat May 21 16:07:40 2016 Ludovic BARRETEAU
*/

#include "dante.h"

char    *get_laby(char  *name_file)
{
  int fd;
  int ret;
  char  *buff;
  struct stat stats;

  if (stat(name_file, &stats) == -1)
    return (NULL);
  if ((buff = malloc(sizeof(buff) * stats.st_size + 1)) == NULL)
    return (NULL);
  fd = open(name_file, O_RDONLY);
  if (fd == -1)
    return (NULL);
  if ((ret = read(fd, buff, (stats.st_size))) == -1)
    return (NULL);
  buff[ret] = 0;
  close(fd);
  return (buff_to_str(buff));
}

int	solver(t_maze *maze)
{
  void (*tab_move[])(t_maze*, int*, int*) =
    {move_right, move_left, move_down, move_up};
  int	x;
  int	y;
  int	i;

  x = 0;
  y = 0;
  while (x < maze->cols - 1 || y < maze->lines - 1)
    {
      i = 0;
      while (i < 4)
	{
	  tab_move[i](maze, &x, &y);
	  if (check_end(maze, x, y) == 0)
	    return (0);
	  i++;
	}
      check_imp(maze, x, y);
      if (maze->nb_imp == 3)
	go_back(maze, &x, &y);
      if (check_impossible(x, y) == 1)
	return (1);
    }
  return (0);
}

void	clean_laby(t_maze *maze)
{
  int	x;
  int	y;

  y = 0;
  while (y <= maze->lines)
    {
      x = 0;
      while (x <= maze->cols)
	{
	  if (maze->tab_algo[y][x] == 'o')
	    maze->tab[y][x] = 'o';
	  x++;
	}
      y++;
    }
}

int	check_impossible(int x, int y)
{
  static int	save_x;
  static int	save_y;
  static int	i;

  if (save_x == 0 && i == 0)
    {
      i = 1;
      save_x = x;
      save_y = y;
    }
  else
    {
      i++;
      if (save_x != x || save_y != y)
	{
	  i = 0;
	  save_x = 0;
	  save_y = 0;
	}
      else
	if (i == 4)
	  return (1);
    }
  return (0);
}
