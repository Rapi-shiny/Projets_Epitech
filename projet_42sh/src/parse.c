/*
** parse.c for  in /home/crespi_c/rendu/PSU/PSU_2015_minishell2
** 
** Made by Celenzo CRESPIN
** Login   <crespi_c@epitech.net>
** 
** Started on  Wed Apr  6 21:37:46 2016 Celenzo CRESPIN
** Last update Sun Jun  5 20:21:06 2016 Romain Hedouin
*/

#include "minishell.h"

int		set_dups(t_pipe *pp, int fd_in)
{
  if (pp->buf == NULL)
    return (dat_keeper(1, 1), my_printf(INV_NULL_CMD), -1);
  if (pp->redir[0] != -1)
    dup2(pp->redir[0], READ);
  else
    dup2(fd_in, READ);
  if (pp->redir[1] != -1)
    dup2(pp->redir[1], WRITE);
  else
    if (pp->next->next != NULL)
      dup2(pp->fd[1], WRITE);
  close(pp->fd[0]);
  if (pp->redir[0] != -1)
    close(pp->redir[0]);
  return (0);
}

void		close_fds(t_pipe *pp)
{
  close(pp->fd[1]);
  if (pp->redir[1] != -1)
    close(pp->redir[1]);
}

int		separators(char *buf, char **ae)
{
  int		i;
  int		sig;
  char		**wt;

  add_and_keep(buf, 0);
  wt = strwt(buf, ';');
  i = 0;
  while (wt[i])
    {
      if (check_cmd_null(wt[i]) != 1)
	sig = hand_op(wt[i], ae);
      i++;
    }
  free_all("w", wt);
  return (sig);
}

int		get_next_pipe(char *buf)
{
  static int	i = 0;
  int		total;

  total = -1;
  if (buf[i] == 0)
    return (i = 0, 0);
  if (buf[my_strlen(buf) - 2] == '|')
    return (i = 0, -1);
  while (buf[i] && buf[i] != '|')
    {
      if (buf[i] != ' ' && buf[i] != '\t')
	total += buf[i];
      i++;
    }
  if (total == -1)
    i = 0;
  if (buf[i] == '|')
    return (i++, total);
  return (total);
}

int		inv_null(char *buf)
{
  int		i;

  while ((i = get_next_pipe(buf)) != 0)
    if (i == -1)
      return (dat_keeper(1, 1), my_printf(INV_NULL_CMD), 1);
  return (0);
}
