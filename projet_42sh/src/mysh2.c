/*
** mysh2.c for  in /home/crespi_c/rendu/PSU/PSU_2015_minishell2
** 
** Made by Celenzo CRESPIN
** Login   <crespi_c@epitech.net>
** 
** Started on  Mon Apr  4 11:39:52 2016 Celenzo CRESPIN
** Last update Sat Jun  4 16:20:04 2016 Celenzo CRESPIN
*/

#include "minishell.h"

void		close_all(t_pipe *pp)
{
  while (pp->next != NULL)
    {
      close(pp->fd[0]);
      close(pp->fd[1]);
      pp = pp->next;
    }
}

void		my_putinlist(t_pipe **pp, int fd[2], char *buf)
{
  t_pipe	*elem;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    exit(5);
  elem->buf = buf;
  elem->fd[0] = fd[0];
  elem->fd[1] = fd[1];
  elem->redir[0] = -1;
  elem->redir[1] = -1;
  elem->is_blt = -1;
  elem->back = -1;
  elem->next = *pp;
  *pp = elem;
}

t_pipe          *my_rev_list(t_pipe *pipe)
{
  t_pipe        *out;

  if ((out = malloc(sizeof(*out))) == NULL)
    exit(5);
  out->next = NULL;
  while (pipe->next != NULL)
    {
      my_putinlist(&out, pipe->fd, pipe->buf);
      pipe = pipe->next;
    }
  return (out);
}

t_pipe		*setpp(char **pt)
{
  int		i;
  int		fd[2];
  t_pipe	*out;

  if (((i = 1) == 1) && (out = malloc(sizeof(*out))) == NULL)
    exit(5);
  out->next = NULL;
  while (*pt != NULL)
    {
      if (pipe(fd) == -1)
	{
	  close(fd[0]);
	  close(fd[1]);
	  return out;
	}
      my_putinlist(&out, fd, *pt++);
      i++;
    }
  close(fd[0]);
  close(fd[1]);
  return (out);
}

int		recurs_pipes(char *buf, char **ae)
{
  int		sig;
  t_pipe	*pp;
  t_pipe	*tr;
  char		**pt;

  if (inv_null(buf) == 1)
    return (0);
  pt = strwt(buf, '|');
  if ((pp = setpp(pt)) == NULL)
    {
      dat_keeper(1, 1);
      fprintf(stderr, "Not enough file descriptors\n");
      return 0;
    }
  pp = my_rev_list(pp);
  tr = pp;
  sig = shell(tr, ae);
  close_all(pp);
  return (sig);
}
