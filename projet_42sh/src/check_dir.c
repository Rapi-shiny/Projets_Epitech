/*
** check_dir.c for  in /home/crespi_c/rendu/Elementary_C/PSU_2015_minishell1
** 
** Made by Celenzo CRESPIN
** Login   <crespi_c@epitech.net>
** 
** Started on  Fri Jan 22 19:21:41 2016 Celenzo CRESPIN
** Last update Sun Jun  5 18:57:00 2016 Celenzo CRESPIN
*/

#include "minishell.h"

int		my_env(char **ae)
{
  my_show_wordtab(ae);
  dat_keeper(1, 0);
  return (0);
}

int             find_built(char *cmd, char **argv, char **ae)
{
  if (my_strcmp(cmd, CD_CMD) == 0)
    return (my_cd(argv, ae));
  if (my_strcmp(cmd, PWD_CMD) == 0)
    return (my_pwd());
  if (my_strcmp(cmd, SETENV_CMD) == 0)
    return (my_setenv(argv, ae), 0);
  if (my_strcmp(cmd, UNSETENV_CMD) == 0)
    return (my_unsetenv(argv, ae));
  if (my_strcmp(cmd, ECHO_CMD) == 0)
    return (my_echo(argv));
  return (-1);
}

int		verif_dir(t_pipe *pp, char *cmd, char **argv, char **ae)
{
  if (cmd[0] != '/' && cmd[0] != '.' &&
      access(my_strcat("./", cmd), F_OK) == 0)
    cmd = my_strcat("./", cmd);
  if (cmd[0] != '/' && cmd[0] != '.')
    return (1);
  if (access(cmd, F_OK) == 0)
    if (access(cmd, X_OK) == 0)
      my_exec(pp, cmd, argv, ae);
    else
      return (dat_keeper(1, 1), my_printf(RIGHT_ERROR, cmd), 0);
  else
    my_printf(CMD_NF, cmd);
  return (0);
}

char		**check_stuff(char **buf, char *cmd)
{
  int		i;
  char		**argv;

  i = my_strlen(cmd) - 1;
  cmd = get_aliases(cmd);
  *buf = my_strcat(cmd, *buf + i);
  argv = strwt(*buf, ' ');
  argv[0] = cmd;
  return (argv);
}
