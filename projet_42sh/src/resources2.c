/*
** resources2.c for  in /home/crespi_c/labosef/my_printf
** 
** Made by Celenzo CRESPIN
** Login   <crespi_c@epitech.net>
** 
** Started on  Wed Mar 30 14:58:16 2016 Celenzo CRESPIN
** Last update Wed Apr  6 16:30:15 2016 Celenzo CRESPIN
*/

#include "minishell.h"

void		my_putunsnbr(unsigned int n)
{
  if (n > 9)
    my_putunsnbr(n / 10);
  n %= 10;
  my_putchar(n + 48);
}

void		my_putlong(long n)
{
  if (n < 0)
    {
      my_putchar('-');
      n *= -1;
    }
  if (n > 9)
    my_putlong(n / 10);
  n %= 10;
  my_putchar(n + 48);
}
