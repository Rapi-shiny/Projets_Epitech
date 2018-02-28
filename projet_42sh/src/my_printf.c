/*
** my_printf.c for my_printf in /home/crespi_c/rendu/PSU_2015_my_printf
**
** Made by Celenzo CRESPIN
** Login   <crespi_c@epitech.net>
** 
** Started on  Wed Nov  4 16:07:22 2015 Celenzo CRESPIN
** Last update Wed Apr  6 16:36:02 2016 Celenzo CRESPIN
*/

#include "my_printf.h"

void		parse_flags(char *flags)
{
  int		i;
  int		j;
  char		a[11] = "idosc%bXxpu";

  i = 0;
  while (flags[i])
    if (flags[i++] == '%')
      {
	j = 0;
	while (a[j++] != flags[i]);
	if (j == 11 && flags[i] != 'u')
	  exit(my_printf("my_printf : Invalid flag %c\n", flags[i]));
	i++;
      }
}

void		int_print(char flag, int nbr)
{
  int		i;
  t_ints	lol[6] = {{'i', 10, "0123456789", &my_putnbr_base},
			  {'d', 10, "0123456789", &my_putnbr_base},
			  {'o', 8, "01234567", &my_putnbr_base},
			  {'x', 16, "0123456789abcdef", &my_putnbr_base},
			  {'X', 16, "0123456789ABCDEF", &my_putnbr_base},
			  {'b', 2, "01", &my_putnbr_base}};

  i = 0;
  while (i < 6)
    {
      if (flag == lol[i].f)
	lol[i].fptr(nbr, lol[i].base_size, lol[i].base);
      i++;
    }
}

void	str_print(char flag, char *str)
{
  if (flag == 's')
    my_putstr(str);
  else
    my_putstr_prt(str);
}

void	process(char *flag, va_list ap)
{
  while (*flag)
    {
      if (*flag == '%')
	{
	  flag++;
	  if (*flag == 'd' || *flag == 'i' || *flag == 'o' || *flag == 'x' \
	      || *flag == 'X' || *flag == 'b')
	    int_print(*flag, va_arg(ap, int));
	  if (*flag == 's' || *flag == 'S')
	    str_print(*flag, va_arg(ap, char*));
	  if (*flag == '%')
	    my_putchar('%');
	  if (*flag == 'c')
	    my_putchar(va_arg(ap, int));
	  if (*flag == 'u')
	    my_putunsnbr(va_arg(ap, unsigned int));
	  if (*flag == 'p')
	    my_putlong(va_arg(ap, long));
	}
      else
	my_putchar(*flag);
      flag++;
    }
}

int	my_printf(char *flag, ...)
{
  va_list	ap;

  parse_flags(flag);
  va_start(ap, flag);
  if (*flag == 0)
    return (-1);
  process(flag, ap);
  va_end(ap);
  return (0);
}
