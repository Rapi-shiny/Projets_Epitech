/*
** resources.c for  in /home/crespi_c/labosef/my_printf
** 
** Made by Celenzo CRESPIN
** Login   <crespi_c@epitech.net>
** 
** Started on  Wed Mar 30 14:45:03 2016 Celenzo CRESPIN
** Last update Wed Apr  6 16:25:38 2016 Celenzo CRESPIN
*/

#include "minishell.h"

void		my_putchar(char c)
{
  write(1, &c, 1);
}

void		my_putstr(char *s)
{
  if (s == NULL)
    return ;
  while (*s)
    write(1, s++, 1);
}

void		my_putnbr(int n)
{
  if (n < 0)
    {
      my_putchar('-');
      n *= -1;
    }
  if (n < 9)
    my_putnbr(n / 10);
  n %= 10;
  my_putchar(n + 48);
}

void		my_putnbr_base(int n, int base_size, char *base)
{
  if (n < 0)
    {
      my_putchar('-');
      n *= -1;
    }
  if (n > base_size - 1)
    my_putnbr_base(n / base_size, base_size, base);
  n %= base_size;
  my_putchar(base[n]);
}

void		my_putstr_prt(char *s)
{
  if (s == NULL)
    return ;
  while (*s)
    {
      if (*s < 32 || *s > 126)
	{
	  my_putchar('\\');
	  if (*s <= 7)
	    my_putchar('0');
	  if (*s <= 126)
	    my_putchar('0');
	  my_putnbr_base(*s, 8, "01234567");
	}
      else
	write(1, s, 1);
      (*s)++;
    }
}
