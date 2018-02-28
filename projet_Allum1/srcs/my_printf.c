/*
** my_printf.c for my_printf in /home/barret_l/rendu/Systeme_unix/PSU_2015_my_printf
** 
** Made by Ludovic BARRETEAU
** Login   <barret_l@epitech.net>
** 
** Started on  Wed Nov  4 13:56:31 2015 Ludovic BARRETEAU
** Last update Wed Feb 10 13:45:27 2016 Ludovic BARRETEAU
*/
#include "../includes/allu.h"

int	my_printf_flags(const char *format, va_list ap, int i)
{
  if (format[i + 1] == 'c')
    my_putchar(va_arg(ap, int));
  if (format[i + 1] == 's')
    my_putstr(va_arg(ap, char *));
  if (format[i + 1] == 'i' || format[i + 1] == 'd')
    my_put_nbr(va_arg(ap, int));
  return (0);
}

int	my_printf(const char* format, ...)
{
  va_list       ap;
  int           i;
  int		nb_char;

  i = 0;
  nb_char = 0;
  va_start(ap, format);
  while (format[i] != '\0')
    {
      if (format[i] == '%' && format[i - 1] != '%')
	my_printf_flags(format, ap, i++);
      else
	{
	  if (format[i] != '%' && format[i - 1] != '%')
	    my_putchar(format[i]);
	  if (format[i] != '%' && format[i - 1] == '%' && format[i - 1] == '%')
	    my_putchar(format[i]);
	  nb_char++;
	}
      i++;
    }
  va_end(ap);
  return (nb_char);
}
