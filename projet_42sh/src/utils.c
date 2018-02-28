/*
** my_show_wordtab.c for  in /home/crespi_c/rendu/Elementary_C/PSU_2015_minishell1/ressources
** 
** Made by Celenzo CRESPIN
** Login   <crespi_c@epitech.net>
** 
** Started on  Fri Jan 15 21:30:20 2016 Celenzo CRESPIN
** Last update Wed May  4 13:56:46 2016 Celenzo CRESPIN
*/

#include "minishell.h"

char		*my_path_strcat(char *s1, char *s2)
{
  int		i;
  int		j;
  char		*out;

  i = 0;
  j = 0;
  if (s2 == NULL)
    return (s1);
  if ((out = malloc(my_strlen(s1) + my_strlen(s2))) == NULL)
    exit(5);
  while (s1[i])
    {
      out[i] = s1[i];
      i++;
    }
  out[i++] = '/';
  while (s2[j])
    out[i++] = s2[j++];
  out[i] = 0;
  return (out);
}

int		my_strlen(char *s)
{
  int		i;

  i = 0;
  while (s[i++]);
  return (i);
}

void		my_show_wordtab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    my_printf("%s\n", tab[i++]);
}

int		check(char *s1, char *s2)
{
  int		i;

  i = 0;
  while ((s1[i] == s2[i]) && s1[i] && s2[i] && (i < (my_strlen(s2) - 2)))
    i++;
  return (s2[i] - s1[i]);
}

int		my_strcmp(char *s1, char *s2)
{
  int		i;

  i = 0;
  if (my_strlen(s1) != my_strlen(s2))
    return (-1);
  while ((s1[i] == s2[i]) && s1[i] && s2[i] && (i < (my_strlen(s2) - 2)))
    i++;
  return (s2[i] - s1[i]);
}
