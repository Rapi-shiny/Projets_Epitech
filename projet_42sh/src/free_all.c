/*
** free_all.c for  in /home/crespi_c/labosef/free_all
** 
** Made by Celenzo CRESPIN
** Login   <crespi_c@epitech.net>
** 
** Started on  Mon Apr  4 11:43:37 2016 Celenzo CRESPIN
** Last update Mon Apr  4 12:00:24 2016 Celenzo CRESPIN
*/

#include <stdarg.h>
#include "minishell.h"

void		free_tab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    free(tab[i++]);
  free(tab);
}

void		verif_flags(char *flags)
{
  int		i;

  i = 0;
  while (flags[i])
    {
      if (flags[i] != 's' && flags[i] != 'w')
	exit(my_printf("free_all : Wrong flag %c\n", flags[i]));
      i++;
    }
}

void		free_process(char *flag, va_list ap)
{
  int		i;

  i = 0;
  while (flag[i])
    {
      if (flag[i] == 's')
	free(va_arg(ap, char*));
      if (flag[i] == 'w')
	free_tab(va_arg(ap, char**));
      i++;
    }
}

int		free_all(char *flags, ...)
{
  va_list	ap;

  verif_flags(flags);
  if (flags == NULL || *flags == 0)
    return 1;
  va_start(ap, flags);
  free_process(flags, ap);
  va_end(ap);
  return 0;
}
