/*
** envbuilts.c for minishell.c in /home/crespi_c/rendu/Elementary_C/PSU_2015_minishell1
** 
** Made by Celenzo CRESPIN
** Login   <crespi_c@epitech.net>
** 
** Started on  Sat Jan 23 16:24:12 2016 Celenzo CRESPIN
** Last update Sun Jun  5 11:58:50 2016 Celenzo CRESPIN
*/

#include "minishell.h"

char		**set_new(char **argv, char **ae)
{
  int		i;
  char		**temp;
  char		*var;

  i = my_arraylen(ae);
  if ((temp = malloc(i + 1)) == NULL)
    exit(5);
  if (argv[2] == NULL)
    var = my_path_strcat(argv[1], "");
  else
    var = my_path_strcat(argv[1], argv[2]);
  var[my_strlen(argv[1]) - 1] = '=';
  temp = ae;
  temp[i - 1] = var;
  temp[i] = NULL;
  dat_keeper(1, 0);
  return (temp);
}

int		set_ovwr(char **argv, char **ae, int i)
{
  char		*var;

  var = my_path_strcat(argv[1], argv[2]);
  var[my_strlen(argv[1]) - 1] = '=';
  ae[i] = var;
  dat_keeper(1, 0);
  return (0);
}

int		my_setenv(char **argv, char **ae)
{
  int		i;

  i = 0;
  if (argv[1] == NULL)
    return (my_env(ae), dat_keeper(1, 0));
  while (ae[i])
    {
      if (check(ae[i], argv[1]) == 0)
	return (set_ovwr(argv, ae, i));
      i++;
    }
  ae = set_new(argv, ae);
  dat_keeper(1, 0);
  return (0);
}

char		**decale(char **ae, int i)
{
  while (ae[i] != NULL)
    {
      if (ae[i + 1] != NULL)
	ae[i] = ae[i + 1];
      else
	ae[i] = NULL;
      i++;
    }
  dat_keeper(1, 0);
  return (ae);
}

int		my_unsetenv(char **argv, char **ae)
{
  int		i;

  i = 0;
  if (argv[1] == NULL)
    return (dat_keeper(1, 1), my_printf(UNSTENV_NEARGS), 0);
  while (ae[i])
    {
      if (check(ae[i], argv[1]) == 0)
	decale(ae, i);
      i++;
    }
  dat_keeper(1, 0);
  return (0);
}
