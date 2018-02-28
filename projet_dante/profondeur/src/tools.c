/*
** tools.c for  in /home/barret_l/rendu/Initiation_IA/dante
** 
** Made by Ludovic BARRETEAU
** Login   <barret_l@epitech.net>
** 
** Started on  Sat Apr 30 10:29:12 2016 Ludovic BARRETEAU
** Last update Sat May  7 10:46:33 2016 Ludovic BARRETEAU
*/

#include "dante.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    i++;
  return (i);
}

void	my_putstr(char *str, int check)
{
  if (check == 1)
    write(1, str, my_strlen(str));
  if (check == 2)
    write(2, str, my_strlen(str));
}

char	*buff_to_str(char *buff)
{
  int	i;
  char	*str;

  i = 0;
  if ((str = malloc(sizeof(str) * my_strlen(buff))) == NULL)
    return (NULL);
  while (buff[i])
    {
      str[i] = buff[i];
      i++;
    }
  str[i] = 0;
  free(buff);
  return (str);
}
