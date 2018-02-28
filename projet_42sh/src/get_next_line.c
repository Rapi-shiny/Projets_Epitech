/*
** get_next_line.c for  in /home/crespi_c/rendu/Elementary_C/CPE_2015_getnextline
** 
** Made by Celenzo CRESPIN
** Login   <crespi_c@epitech.net>
** 
** Started on  Wed Jan 13 19:06:02 2016 Celenzo CRESPIN
** Last update Sat Jun  4 12:23:36 2016 Celenzo CRESPIN
*/

#include "minishell.h"

char		*my_realloc(char *s, int size)
{
  int		i;
  int		j;
  char		*newline;

  i = 0;
  j = 0;
  while (s[j++]);
  if ((newline = malloc((j) + size)) == NULL)
    return (NULL);
  while (s != NULL && s[i])
    {
      newline[i] = s[i];
      i++;
    }
  newline[i] = 0;
  free(s);
  return (newline);
}

char		*choose_what(char *line, int k, int w)
{
  int		i;

  i = 0;
  if (k == -1)
    return (NULL);
  if (w == 0)
    return (NULL);
  line[w] = 0;
  while (line[i])
    i++;
  if (line[i - 1] == '\n')
    return (NULL);
  return (line[i] = 0, line);
}

char		*fill(char *line, int fd, int i)
{
  static int	k = -1;
  static int   	j = 0;
  static char	res[READ_SIZE];

  while (res[j])
    {
      line[i++] = res[j++];
      if ((res[j] == '\n') || (k == 0 && res[j] == 0))
	return (line[i] = 0, line);
    }
  if ((k = read(fd, res, READ_SIZE)) <= 0)
    return (choose_what(line, k, i));
  if ((line[i] = 0) == 0 && (line = my_realloc(line, READ_SIZE + 1)) == NULL)
    return (NULL);
  res[k] = 0;
  j = 0;
  while (j < k)
    {
      if ((res[j] == '\n'))
	return (line[i] = 0, line);
      line[i++] = res[j++];
    }
  return (fill(line, fd, i));
}

char		*get_next_line(const int fd)
{
  int		i;
  char		*line;

  i = 0;
  if ((line = malloc(READ_SIZE + 1)) == NULL)
    return (NULL);
  line[0] = 0;
  if ((line = fill(line, fd, 0)) == NULL)
    return (NULL);
  if (line[0] == 0)
    return (line[0] = 0, line);
  if (line[0] == '\n')
    while (line[i])
      {
	line[i] = line[i + 1];
	i++;
      }
  return (line);
}
