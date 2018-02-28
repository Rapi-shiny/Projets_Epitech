/*
** redir.c for  in /home/crespi_c/rendu/PSU/PSU_2015_minishell2
** 
** Made by Celenzo CRESPIN
** Login   <crespi_c@epitech.net>
** 
** Started on  Sat Apr  9 16:58:32 2016 Celenzo CRESPIN
** Last update Sun Jun  5 14:47:55 2016 Celenzo CRESPIN
*/

#include "minishell.h"

int		deb_cmd(char *buf, char c)
{
  int		i;

  if (buf[0] != c)
    return 0;
  i = 1;
  if (buf[1] == c || buf[1] == ' ')
    i++;
  if (buf[2] == ' ')
    i++;
  while (buf[i++] != ' ' && buf[i]);
  return i;
}

char            *trunc_cmd(char *buf, char c)
{
  int           i;
  int           j;
  char          *out;

  j = 0;
  i = deb_cmd(buf, c);
  if ((out = malloc(sizeof(*out) * my_strlen(buf))) == NULL)
    exit(5);
  while (buf[i])
    {
      out[j++] = buf[i++];
      if (buf[i] == c)
	i = get_suite(buf, i, c);
    }
  out[j] = 0;
  if (out[j - 1] == ' ')
    out[j - 1] = 0;
  free(buf);
  if (out == NULL || out[0] == 0)
    return NULL;
  if (j == 0)
    return (NULL);
  return out;
}

int		check_left(t_pipe *pp)
{
  int		fd;
  int		nb;

  nb = verif_sym(pp->buf, '<');
  if (nb != 1 && nb != -1)
    return (-1);
  if ((my_slen(pp->buf) == 1 && nb == 1) ||
      (my_slen(pp->buf) == 2 && nb == -1))
    return -1;
  fd = open_left(pp->buf, '<');
  pp->buf = trunc_cmd(pp->buf, '<');
  return (fd);
}

int		check_right(t_pipe *pp)
{
  int		fd;
  int		nb;

  nb = verif_sym(pp->buf, '>');
  if (nb != 1 && nb != -1)
    {
      if (nb != 0 && (dat_keeper(1, 1) == 0))
	my_printf(AMBIG);
      return (-1);
    }
  if ((my_slen(pp->buf) == 1 && nb == 1) ||
      (my_slen(pp->buf) == 2 && nb == -1))
    return -1;
  fd = open_right(pp->buf, '>');
  pp->buf = trunc_cmd(pp->buf, '>');
  return (fd);
}

t_pipe		*check_redir(t_pipe *pp)
{
  int		*redir;

  if ((redir = malloc(sizeof(*redir) * 2)) == NULL)
    exit(5);
  pp->redir[0] = check_left(pp);
  pp->redir[1] = check_right(pp);
  if (((pp->redir[1] == -2 || pp->redir[0] == -2) ||
      (pp->buf == NULL || pp->buf[0] == 0)) && (dat_keeper(1, 1) == 0))
    return NULL;
  return pp;
}
