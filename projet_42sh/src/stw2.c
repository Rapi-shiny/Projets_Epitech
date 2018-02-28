/*
** stw2.c for stw2.c in /home/jahan_a/PSU/PSU_2015_minishell2
** 
** Made by antoine jahan
** Login   <jahan_a@epitech.net>
** 
** Started on  Sat Apr  9 17:00:34 2016 antoine jahan
** Last update Thu Jun  2 19:02:40 2016 Celenzo CRESPIN
*/

#include "minishell.h"

void	show_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      write(2, tab[i], my_strlen(tab[i]) - 1);
      write(2, "\n", 1);
      i++;
    }
}

int     count_words2(char *str, char d)
{
  int   i;
  int   nb;

  i = 0;
  nb = 0;
  while (str[i] != 0)
    {
      if (str[i] == d)
	nb++;
      i++;
    }
  return (nb + 1);
}

char    *next_word2(char *str, int clear, char d)
{
  static int    i = 0;
  int           j;
  char          *new;

  if (clear == 1)
    i = 0;
  else
    {
      if ((new = malloc(sizeof(*new) * (my_strlen(str) - 1))) == NULL)
	exit(0);
      j = 0;
      while (str[i] != d && str[i] != 0)
        {
          new[j] = str[i];
          i++;
	  j++;
        }
      i++;
      new[j] = 0;
      return (new);
    }
  return NULL;
}

char    **stw2(char *str, char d)
{
  char  **tab;
  int   nb_words;
  int   i;

  nb_words = count_words2(str, d);
  if ((tab = malloc(sizeof(*tab) * (nb_words))) == NULL)
    exit(0);
  i = 0;
  while (i < nb_words)
    {
      tab[i] = next_word2(str, 0, d);
      i++;
    }
  tab[i] = NULL;
  next_word2(str, 1, d);
  return (tab);
}
