/*
** str_to_wordtab.c for soutien in /home/crespi_c/rendu/Elementary_C/soutien/session2
** 
** Made by Celenzo CRESPIN
** Login   <crespi_c@epitech.net>
** 
** Started on  Wed Nov 18 16:07:10 2015 Celenzo CRESPIN
** Last update Tue Mar 29 17:55:47 2016 Celenzo CRESPIN
*/

#include "minishell.h"

char	*my_mstrncpy(char *dest, char *src, int n, int size)
{
  int	i;

  i = 0;
  while (n <= size)
    {
      dest[i] = src[n];
      i++;
      n++;
    }
  dest[i] = '\0';
  return (dest);
}

char	**nbr_word(char *str, char d)
{
  int	i;
  int	word_nbr;
  char	**wordtab;

  i = 0;
  word_nbr = 0;
  while (str[i])
      while (str[i++] == d)
	word_nbr++;
  if ((wordtab = malloc(sizeof(char**) * (word_nbr + 2))) == NULL)
    exit(5);
  return (wordtab);
}

char	**set_end(char **wordtab, int i)
{
  if (i != 0)
    if (wordtab[i - 1][0] == ' ' || wordtab[i - 1][0] == '\0')
      wordtab[i - 1] = NULL;
  wordtab[i] = NULL;
  return (wordtab);
}

char	**str_to_wordtab(char *str, char d)
{
  char	**wordtab;
  int	i;
  int	ind1;
  int	ind2;

  ind1 = 0;
  ind2 = 0;
  wordtab = nbr_word(str, d);
  i = 0;
  while (str[ind2])
    {
      if (str[ind1] == d || str[ind1] == '\0')
	{
	  if ((wordtab[i] = malloc(sizeof(char**) * (ind1 - ind2))) == NULL)
	    exit(5);
	  if (i != 0)
	    ind2++;
	  while (str[ind2++] == d);
	  wordtab[i] =  my_mstrncpy(wordtab[i], str, ind2 - 1, ind1 - 1);
	  ind2 = ind1;
	  i++;
	}
      ind1++;
    }
  return (set_end(wordtab, i));
}
