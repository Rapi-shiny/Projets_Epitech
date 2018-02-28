/*
** mysh.c for  in /home/crespi_c/rendu/Elementary_C/PSU_2015_minishell1
** 
** Made by Celenzo CRESPIN
** Login   <crespi_c@epitech.net>
** 
** Started on  Mon Jan 18 09:44:22 2016 Celenzo CRESPIN
** Last update Sun Jun  5 20:07:42 2016 Romain Hedouin
*/

#include "minishell.h"

int		my_exec(t_pipe *pp, char *file, char **argv, char **ae)
{
  static int	fd_in = 0;
  pid_t		pid;

  if ((pid = fork()) == -1)
    return (0);
  if (pid == 0)
    {
      if (set_dups(pp, fd_in) == -1)
	exit(0);
      do_exec(pp, file, argv, ae);
    }
  else
    {
      close_fds(pp);
      fd_in = pp->fd[0];
      (pp->next->next != NULL) ? shell(pp->next, ae) : (fd_in = 0) == 0;
      set_back(pp, pid);
    }
  return (fd_in);
}

char		*find_prgm(char **path, char *cmd, int btin)
{
  char		*file;
  int		i;

  i = 0;
  if (btin == 0)
    return (my_strdup(cmd));
  while (path[i] != NULL)
    {
      file = my_path_strcat(path[i], cmd);
      if (access(file, F_OK) == 0)
	{
	  if (access(file, X_OK) == 0)
	    return (file);
	  else
	    return (dat_keeper(1, 1), my_printf(RIGHT_ERROR, cmd), NULL);
	}
      i++;
    }
  return (dat_keeper(1, 1), NULL);
}

int		shell(t_pipe *pp, char **ae)
{
  char		**path;
  char		**argv;
  char	        *cmd;
  char		*file;

  dat_keeper(1, 0);
  pp->buf = verif_sd(seek_and_destroy(pp->buf), pp, ae);
  if (pp->buf == NULL || pp->buf[0] == 0)
    return (free(pp->buf), 5);
  if ((pp = check_redir(pp)) == NULL)
    return (0);
  argv = check_stuff(&pp->buf, separate(pp->buf));
  cmd = separate(pp->buf);
  if ((pp->is_blt = check_built(cmd, argv, ae, pp)) == 1)
    return (verif_blt(pp, ae));
  if (verif_dir(pp, cmd, argv, ae) == 0)
    return (free_all("ssw", pp->buf, cmd, argv), 0);
  if ((path = parse_ae(ae, PATH_VAR)) == NULL)
    path = set_urgency_path(my_strdup(EMERG_PATH));
  if ((file = find_prgm(path, cmd, pp->is_blt)) == NULL)
    return (NF(CMD_NF, cmd), free_all("ssww", pp->buf, cmd, path, argv), -1);
  else
    my_exec(pp, file, argv, ae);
  return (free_all("sssww", pp->buf, cmd, file, path, argv), 0);
}

int		main(int ac, char **av, char **ae)
{
  int		i;
  int		sig;
  char		*buf;

  i = 1;
  sig = 0;
  if (av[1] != NULL && ac != 1)
    return (0);
  open_and_stock(my_path_strcat(my_getcwd(), RC_FILE), 1);
  signal(SIGINT, sig_hand);
  while (sig != 1)
    {
      sig = 2;
      if (isatty(0) == 1)
	my_printf(PROMPT, getvar(gtenv(ae, USER_VAR)),
		  getvar(gtenv(ae, HOST_VAR)), i,
		  verif_user(gtenv(ae, USER_VAR)));
      buf = seek_and_destroy(get_next_line(0));
      if (buf == NULL)
	exit(dat_keeper(0, 0));
      if (buf != NULL && buf[0] != 0 && i++)
	sig = separators(buf, ae);
    }
  return (0);
}
