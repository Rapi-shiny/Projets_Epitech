/*
** alias.c for  in /home/crespi_c/rendu/PSU/PSU_2015_minishell2
** 
** Made by Celenzo CRESPIN
** Login   <crespi_c@epitech.net>
** 
** Started on  Sun Apr  3 23:18:50 2016 Celenzo CRESPIN
** Last update Sat Jun  4 12:21:32 2016 Celenzo CRESPIN
*/

#include "minishell.h"

char		*open_and_stock(char *opn, int st)
{
  static char	*p;

  if (st == 1)
    p = opn;
  else
    return p;
  return NULL;
}

char		*trans_alias(char *cmd, char *s)
{
  int		i;
  char		*out;

  i = my_strlen(cmd);
  out = my_strdup(s + i);
  free(cmd);
  return (out);
}

int		get_size(char *s)
{
  int		i;

  i = 0;
  while (s[i] != '=' && s[i])
    i++;
  return (i);
}

bool		size_check(char *cmd, char *s)
{
  int		i;
  int		j;

  i = 0;
  j = my_strlen(cmd) - 1;
  while (s[i] && s[i] != '=')
    i++;
  if (i != j)
    return false;
  return true;
}

char		*get_aliases(char *cmd)
{
  char		*s;
  int		fd;

  if ((fd = open(open_and_stock(NULL, 0), O_RDONLY)) == -1)
    return cmd;
  while ((s = get_next_line(fd)) != NULL)
    {
      if (my_strncmp(s, "alias:", 6) == 0)
	if ((size_check(cmd, s + 6) == true) &&
	    my_strncmp(s + 6, cmd, get_size(s + 6)) == 0)
	  {
	    cmd = trans_alias(cmd, s + 6);
	    break ;
	  }
      free(s);
    }
  close(fd);
  return cmd;
}
