/*
** my_getnbr.c for my_getnbr.c in /home/barret_l/makefile/lib/my/WIP
** 
** Made by Ludovic BARRETEAU
** Login   <barret_l@epitech.net>
** 
** Started on  Thu Oct 15 14:28:08 2015 Ludovic BARRETEAU
** Last update Wed Feb 24 17:56:25 2016 Ludovic BARRETEAU
*/

#include "../includes/allu.h"

int	my_verif_sign_getnbr(int *result, char *str)
{
  int	i;

  i = 0;
  *result = 0;
  if (str[0] == '-')
    {
      *result = -(str[1] - 48);
      return (i + 2);
    }
  if (my_char_isnum(str[0]) == 1)
    {
      *result = str[0] - 48;
      return (i + 1);
    }
  return (0);
}

int	my_getnbr(char *str)
{
  int	i;
  int	result;
  int	verif;

  result = 0;
  i = my_verif_sign_getnbr(&result, str);
  verif = result;
  if (my_strlen(str) == 0)
    return (-1);
  while (str[i] != '\0')
    {
      if (my_char_isnum(str[i]) == 0)
	return (-1);
      result = result * 10;
      if (result > -1)
	result = result + (str[i++] - 48);
      else
	result = result - (str[i++] - 48);
      if (verif > 0 && result < 0)
        return (-1);
      if (verif < 0 && result > 0)
	return (1);
      verif = result;
    }
  return (result);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}
