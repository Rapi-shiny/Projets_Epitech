/*
** strwt.c for  in /home/crespi_c/labosef/strwt
** 
** Made by Celenzo CRESPIN
** Login   <crespi_c@epitech.net>
** 
** Started on  Thu Mar 24 17:01:23 2016 Celenzo CRESPIN
** Last update Sat Jun  4 17:19:56 2016 benjamin HENRY
*/

#include "minishell.h"

int		nb_words(char *s, char d)
{
  int		i;
  int		nb;

  i = 0;
  nb = 0;
  while (s[i])
    {
      if (s[i] == '"' && i++)
	while (s[i] && s[i++] != '"');
      if (s[i] == d)
	nb++;
      i++;
    }
  return (nb);
}

char		*next_line(char *s, char d)
{
  static int	i = 0;
  char		*out;
  int		j;

  j = 0;
  out = NULL;
  if (i >= my_strlen(s))
    return (i = 0, NULL);
  if ((out = calloc(1, (my_strlen(s) * sizeof(out)))) == NULL)
    exit(1);
  if (s[i] == '"')
    {
      i++;
      while (s[i] && s[i] != '"')
	out[j++] = s[i++];
      return (i++, out[j] = 0, out);
    }
  while (s[i] != 0 && s[i] != d)
    out[j++] = s[i++];
  return (i++, out[j] = 0, out);
}

char		**strwt(char *s, char d)
{
  int		i;
  char		*temp;
  char		**wt;

  i = 0;
  if ((wt = malloc((nb_words(s, d) + 2) * sizeof(wt))) == NULL)
    exit(1);
  while ((temp = next_line(s, d)) != NULL)
    if (temp[0] != 0)
      wt[i++] = temp;
  wt[i] = NULL;
  return (wt);
}
