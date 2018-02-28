/*
** functionc.c for  in /home/barret_l/rendu/Prog_elem/CPE_2015_Allum1/srcs
** 
** Made by Ludovic BARRETEAU
** Login   <barret_l@epitech.net>
** 
** Started on  Wed Feb 10 13:32:56 2016 Ludovic BARRETEAU
** Last update Sat Feb 20 14:49:51 2016 Ludovic BARRETEAU
*/

#include "../includes/allu.h"

int     my_char_isnum(char c)
{
  if (c >= '0' && c <= '9')
    return (1);
  else
    return (0);
}

void    my_putchar(char c)
{
  write(1, &c, 1);
}

void    my_putstr(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    my_putchar(str[i++]);
}

void	my_put_nbr(int  nbr)
{
  int   div;

  div = 1;
  if (nbr < 0)
    my_putchar('-');
  else
    nbr = -nbr;
  while (nbr / div < -9)
    div = div * 10;
  while (div > 0)
    {
      my_putchar(-(nbr / div) + 48);
      nbr = nbr % div;
      div = div / 10;
    }
}

