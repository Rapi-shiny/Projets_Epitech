/*
** redir2.c for  in /home/crespi_c/rendu/PSU/PSU_2015_minishell2
** 
** Made by Celenzo CRESPIN
** Login   <crespi_c@epitech.net>
** 
** Started on  Mon Apr 11 22:19:16 2016 Celenzo CRESPIN
** Last update Sun Jun  5 15:04:17 2016 Celenzo CRESPIN
*/

#include "minishell.h"

int             fill_open(char *buf, int i, char *opn)
{
  int           j;
  int           fd;
  int		two;

  j = 0;
  two = 0;
  if (buf[i] == '<' && (two = 1) == 1)
    i++;
  if (buf[i] == ' ')
    i++;
  while (buf[i] && buf[i] != ' ')
    opn[j++] = buf[i++];
  opn[j] = 0;
  if (opn == NULL || opn[0] == 0)
    return (dat_keeper(1, 1), fprintf(stderr, MISS_NAME), -2);
  if (two == 0)
    return (check_simple_left(opn));
  else
    fd = fill_double_left(opn);
  return (free(opn), fd);
}

int             fill_right(char *buf, int i, char *opn)
{
  int           j;
  int           fd;
  int           end;

  j = 0;
  end = 0;
  if (buf[i] == '>' && (end = 1) == 1)
    i++;
  if (buf[i] == ' ')
    i++;
  while (buf[i] && buf[i] != ' ')
    opn[j++] = buf[i++];
  opn[j] = 0;
  if (opn == NULL || opn[0] == 0)
    return (dat_keeper(1, 1), fprintf(stderr, MISS_NAME), -2);
  if (end == 0)
    return (check_simple_right(opn));
  else
    fd = check_double_right(opn);
  return (free(opn), fd);
}

int             open_left(char *buf, char c)
{
  int           i;
  int           res;
  char          *to_open;

  i = 0;
  res = -1;
  if ((to_open = malloc(sizeof(*to_open) * my_strlen(buf))) == NULL)
    exit(5);
  while (buf[i])
    {
      if (buf[i++] == c)
        return (res = fill_open(buf, i, to_open), res);
    }
  return res;
}

int             open_right(char *buf, char c)
{
  int           i;
  int           res;
  char          *to_open;

  i = 0;
  res = -1;
  if ((to_open = malloc(sizeof(*to_open) * my_strlen(buf))) == NULL)
    exit(5);
  while (buf[i])
    {
      if (buf[i++] == c)
        return (res = fill_right(buf, i, to_open), res);
    }
  return res;
}

int             verif_sym(char *buf, char c)
{
  int           i;
  int           nb;

  i = 0;
  nb = 0;
  while (buf[i])
    {
      if (buf[i] && buf[i++] == c)
        nb++;
      else
        continue ;
      if (buf[i] && buf[i++] == c)
        nb -= 2;
    }
  return nb;
}

