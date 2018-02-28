/*
** built_pipe_hand.c for  in /home/crespi_c/rendu/PSU/PSU_2015_42sh/src
** 
** Made by Celenzo CRESPIN
** Login   <crespi_c@epitech.net>
** 
** Started on  Tue May 31 13:37:46 2016 Celenzo CRESPIN
** Last update Sun Jun  5 21:27:12 2016 Romain Hedouin
*/

#include "minishell.h"

int	do_exit(char **argv)
{
  if (argv == NULL || argv[1] == NULL || my_arraylen(argv) == 1)
    exit(0);
  if (verif_nb(argv[1]) != 0)
    {
      fprintf(stderr, "%s\n", argv[1]);
      fprintf(stderr, EXIT_ERR);
      return 0;
    }
  exit(my_getnbr(argv[1]));
  return 0;
}

int     check_built(char *cmd, char **argv, char **ae, t_pipe *pp)
{
  if (my_strcmp(cmd, EXIT_CMD) == 0 && pp->next->next == NULL)
    return (do_exit(argv));
  if ((my_strcmp(cmd, ENV_CMD) == 0) || (my_strcmp(cmd, ECHO_CMD) == 0)
      || (my_strcmp(cmd, EXIT_CMD) == 0) || (my_strcmp(cmd, HIST_CMD) == 0)
      || ((my_strcmp(cmd, SETENV_CMD) == 0) && argv[1] == NULL))
    return 0;
  if (find_built(cmd, argv, ae) != -1)
    return 1;
  return -1;
}

void	parsing_hist(char **argv, char **ae)
{
  int	i;

  i = 0;
  if (!argv[1])
    history(add_and_keep(NULL, 1));
  if (argv[1] && argv[1][0] == '!')
    {
      while (argv[1][i + 1])
	{
	  argv[1][i] = argv[1][i + 1];
	  i++;
	}
      argv[1][i] = '\0';
      separators(ret_line(add_and_keep(NULL, 1), argv[1], 0), ae);
    }
  else
    if (argv[1])
      {
	if (verif_nb(argv[1]) == 0)
	  ret_line(add_and_keep(NULL, 1), argv[1], 1);
	else
	  printf("Argument is not a valid number.\n");
      }
}

void		do_exec(t_pipe *pp, char *file, char **argv, char **ae)
{
  struct stat	info;

  if (pp->is_blt == 0)
    {
      if (my_strcmp(file, EXIT_CMD) == 0)
	do_exit(argv);
      else if (my_strcmp(file, ECHO_CMD) == 0)
	my_echo(argv);
      else if (my_strcmp(file, HIST_CMD) == 0)
	parsing_hist(argv, ae);
      else
	my_env(ae);
      exit(0);
    }
  else
    execve(file, argv, ae);
  if (stat(file, &info) == -1)
    exit(0);
  if (S_ISDIR(info.st_mode))
    my_printf(RIGHT_ERROR, file);
  else
    my_printf(FORM_ERROR, file);
  exit(0);
}

int		verif_blt(t_pipe *pp, char **ae)
{
  if (pp->next->next != NULL)
    shell(pp->next, ae);
  return (0);
}
