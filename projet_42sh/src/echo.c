/*
** echo.c for 42 in /home/henry_k/test/echo2
** 
** Made by benjamin HENRY
** Login   <henry_k@epitech.net>
** 
** Started on  Tue May 31 13:26:32 2016 benjamin HENRY
** Last update Thu Jun  2 18:44:37 2016 benjamin HENRY
*/

#include "minishell.h"

int	my_echo(char **av)
{
  int	n;
  int	i;
  int	a;

  n = 0;
  a = 0;
  i = 1;
  if (av[1] == NULL)
    return (my_printf("\n"));
  if (av[1][a] == ' ')
    while (av[1][a] == ' ')
      a++;
  if (av[1][a++] == '-' && av[1][a] == 'n')
    {
      n++;
      i++;
    }
  while (av[i + 1])
    printf("%s ", av[i++]);
  printf("%s", av[i++]);
  if (n == 0)
    printf("\n");
  return (0);
}
