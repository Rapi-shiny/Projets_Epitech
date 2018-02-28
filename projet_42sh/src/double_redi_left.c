/*
** double_redi_left.c for  in /home/crespi_c/rendu/PSU/PSU_2015_42sh
** 
** Made by Celenzo CRESPIN
** Login   <crespi_c@epitech.net>
** 
** Started on  Mon May 30 12:38:03 2016 Celenzo CRESPIN
** Last update Tue May 31 13:50:31 2016 Celenzo CRESPIN
*/

#include "minishell.h"

int		fill_double_left(char *buf)
{
  int		fd[2];
  char		*s;

  if (pipe(fd) == -1)
    return -1;
  fprintf(stderr, PS2);
  while (my_strcmp((s = get_next_line(0)), buf) != 0)
    {
      fprintf(stderr, PS2);
      dprintf(fd[1], "%s\n", s);
    }
  close(fd[1]);
  return (fd[0]);
}
