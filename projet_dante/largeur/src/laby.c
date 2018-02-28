/*
** laby.c for  in /home/barret_l/rendu/Initiation_IA/dante/solver_larg/src
** 
** Made by Ludovic BARRETEAU
** Login   <barret_l@epitech.net>
** 
** Started on  Tue May 10 13:50:58 2016 Ludovic BARRETEAU
** Last update Sat May 21 14:29:17 2016 Ludovic BARRETEAU
*/

#include "dante.h"

char    *get_laby(char  *name_file)
{
  int		fd;
  int		ret;
  char		*buff;
  struct stat	stats;

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

int		start_solver(t_maze *maze)
{
  t_graph	*lane;

  lane = create_list();
  if (maze->tab[0][0] != '*')
    return (1);
  add_after(lane, 0, 0, lane);
  check_list(lane, maze);
  solve_laby(lane, maze);
  return (0);
}
