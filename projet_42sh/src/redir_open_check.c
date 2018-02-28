/*
** redir_open_check.c for  in /home/crespi_c/rendu/PSU/PSU_2015_42sh
** 
** Made by Celenzo CRESPIN
** Login   <crespi_c@epitech.net>
** 
** Started on  Sun Jun  5 14:31:39 2016 Celenzo CRESPIN
** Last update Sun Jun  5 18:49:10 2016 antoine jahan
*/

#include "minishell.h"

int		check_simple_left(char *opn)
{
  int		fd;

  if (access(opn, F_OK) == -1)
    return (dat_keeper(1, 1), fprintf(stderr, FILE_NOT_FOUND, opn), -2);
  if (access(opn, R_OK) == -1)
    return (dat_keeper(1, 1), fprintf(stderr, RIGHT_ERROR, opn), -2);
  if ((fd = open(opn, O_RDONLY)) == -1)
    return (dat_keeper(1, 1),
	    fprintf(stderr, FILE_NOT_FOUND, opn), free(opn), -2);
  return fd;
}

int		check_simple_right(char *opn)
{
  int		fd;

  if (access(opn, F_OK) == 0 && access(opn, W_OK) == -1)
    return (dat_keeper(1, 1), fprintf(stderr, RIGHT_ERROR, opn), -2);
  if ((fd = open(opn, O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
    return (dat_keeper(1, 1), my_printf(FILE_NOT_FOUND, opn), free(opn), fd);
  return fd;
}

int		check_double_right(char *opn)
{
  int		fd;

  if (access(opn, F_OK) == 0 && access(opn, W_OK) == -1)
    return (dat_keeper(1, 1), fprintf(stderr, RIGHT_ERROR, opn), -2);
  if ((fd = open(opn, O_WRONLY | O_CREAT | O_APPEND, 0644)) == -1)
    return (dat_keeper(1, 1), my_printf(FILE_NOT_FOUND, opn), free(opn), fd);
  return fd;
}
