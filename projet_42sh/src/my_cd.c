/*
** my_cd.c for  in /home/crespi_c/rendu/Elementary_C/PSU_2015_minishell1
** 
** Made by Celenzo CRESPIN
** Login   <crespi_c@epitech.net>
** 
** Started on  Sat Jan 23 00:08:46 2016 Celenzo CRESPIN
** Last update Sun Jun  5 10:53:15 2016 Ludovic BARRETEAU
*/

#include "minishell.h"

int		set_ae(char *cwd, char **ae)
{
  char		*pwd[3];

  pwd[0] = OSEF;
  pwd[1] = PWD_VAR;
  if ((pwd[2] = malloc(MAX_PATH_SIZE)) == NULL)
    exit(5);
  pwd[2] = cwd;
  my_setenv(pwd, ae);
  return (dat_keeper(1, 0));
}

char		*cd_min(char *oldpwd)
{
  char		*temp;

  temp = my_getcwd();
  if (oldpwd == NULL || oldpwd[0] == 0)
    return (free(temp), oldpwd);
  if (chdir(oldpwd) == -1)
    my_printf(DIR_ERROR);
  return (free(oldpwd), temp);
}

int	cd_error(char **argv)
{
  if (argv[2] != NULL)
    {
      if (argv[1][0] == '-')
	return (dat_keeper(1, 1), my_printf(CD_USAGE), 0);
      return (dat_keeper(1, 1), my_printf(CD_T_ARG), 0);
    }
  return (1);
}

int		my_cd(char **argv, char **ae)
{
  static char	*pwd;

  if (cd_error(argv) == 0)
    return (0);
  if (argv[1] != NULL && my_strcmp(argv[1], "-") == 0)
    return (pwd = cd_min(pwd), 0);
  free(pwd);
  pwd = my_getcwd();
  if ((argv[1] == NULL) && (parse_ae(ae, HOME_VAR) != NULL))
    {
      if (chdir(parse_ae(ae, HOME_VAR)[0]) == -1)
	return (dat_keeper(1, 1), my_printf(DIR_ERROR), 0);
      set_ae(parse_ae(ae, HOME_VAR)[0], ae);
    }
  else
    {
      if (access(argv[1], F_OK) == -1)
	return (dat_keeper(1, 1), my_printf(FILE_NOT_FOUND, argv[1]), 0);
      if (access(argv[1], R_OK) == -1)
	return (dat_keeper(1, 1), my_printf(RIGHT_ERROR, argv[1]), 0);
      if (chdir(argv[1]) == -1)
	return (dat_keeper(1, 1), my_printf(DIR_ERROR, argv[1]), 0);
      set_ae(my_getcwd(), ae);
    }
  return (dat_keeper(1, 0));
}

int		my_pwd()
{
  char		*pwd;

  pwd = my_getcwd();
  my_printf("%s\n", pwd);
  free(pwd);
  return (dat_keeper(1, 0));
}
