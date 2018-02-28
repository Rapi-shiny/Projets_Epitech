/*
** job_control.c for  in /home/crespi_c/rendu/PSU/PSU_2015_42sh
** 
** Made by Celenzo CRESPIN
** Login   <crespi_c@epitech.net>
** 
** Started on  Fri Jun  3 17:15:51 2016 Celenzo CRESPIN
** Last update Sun Jun  5 19:21:22 2016 Celenzo CRESPIN
*/

#include "minishell.h"

void		sig_hand(int a)
{
  if (a == SIGINT)
    return;
  else
    return;
}

void		jb_ctrl(t_pipe *pp, pid_t pid)
{
  static int	times = 0;
  static int	ig = 0;

  if (times++ == 0 && pid != 0)
    ig = pid;
  setpgid(pid, ig);
  if (pp->next == NULL)
    {
      times = 0;
      ig = 0;
    }
}

void		set_back(t_pipe *pp, pid_t pid)
{
  int		tmp;
  int		st;

  if (pp->back == -1)
    {
      wait(&st);
      tmp = WTERMSIG(st);
      if (WIFSIGNALED(st))
	print_err(st);
      if (tmp > 0)
	dat_keeper(1, (tmp + 128));
    }
  else
    jb_ctrl(pp, pid);
}
