/*
** set.c for  in /home/crespi_c/rendu/Elementary_C/PSU_2015_minishell1
** 
** Made by Celenzo CRESPIN
** Login   <crespi_c@epitech.net>
** 
** Started on  Thu Jan 21 11:20:22 2016 Celenzo CRESPIN
** Last update Sat Jun  4 17:25:45 2016 benjamin HENRY
*/

#include "minishell.h"

char		*seek_and_destroy(char *buf)
{
  int		i;
  int		j;
  int		check;
  char		*out;

  i = 0;
  j = 0;
  if (buf == NULL)
    return (buf);
  if ((out = calloc(1, (my_strlen(buf) + 1))) == NULL)
    exit(5);
  while (buf[i] == ' ' || buf[i] == '\t')
    i++;
  while (buf[i] && buf[i] != '\n')
    {
      check = 0;
      while ((buf[i] == ' ' || buf[i] == '\t') && i++)
	{
	  out[j] = ' ';
	  check = 1;
	}
      j += check;
      out[j++] = buf[i++];
    }
  return (free(buf), out[j] = 0, out);
}

char		*separate(char *buf)
{
  int		i;
  char		*out;

  i = 0;
  if ((out = malloc(my_strlen(buf))) == NULL)
    exit(5);
  while (buf[i] != ' ' && buf[i] && buf[i] != '\n')
    {
      out[i] = buf[i];
      i++;
    }
  out[i] = 0;
  return (out);
}

char		*skip_name(char *s)
{
  int		i;
  int		j;
  char		*out;

  i = 0;
  j = 0;
  if ((out = malloc(my_strlen(s))) == NULL)
    exit(5);
  while (s[i++] != '=');
  while (s[i])
    out[j++] = s[i++];
  free(s);
  return (out[j] = 0, out);
}

char		**parse_ae(char **ae, char *find)
{
  int		i;
  char		**path_data;

  i = 0;
  while (ae[i] != NULL && check(ae[i], find) != 0)
    i++;
  if (ae[i] == NULL)
    return (NULL);
  else
    path_data = str_to_wordtab(ae[i], ':');
  path_data[0] = skip_name(path_data[0]);
  return (path_data);
}
