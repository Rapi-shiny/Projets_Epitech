/*
** my_printf.h for  in /home/crespi_c/labosef/my_printf
** 
** Made by Celenzo CRESPIN
** Login   <crespi_c@epitech.net>
** 
** Started on  Wed Mar 30 16:36:39 2016 Celenzo CRESPIN
** Last update Sat Apr  9 16:28:06 2016 Celenzo CRESPIN
*/

#include <stdlib.h>
#include <stdarg.h>

#ifndef __MY_PRINTF
#define __MY_PRINTF

typedef struct	s_ints
{
  char		f;
  int		base_size;
  char		*base;
  void		(*fptr)(int nb, int base_size, char *base);
}		t_ints;

int		my_printf(char *flags, ...);
void		my_putchar(char c);
void		my_putstr(char *s);
void		my_putnbr(int n);
void		my_putnbr_base(int n, int base_size, char *base);
void		my_putstr_prt(char *s);
void		my_putunsnbr(unsigned int n);
void		my_putlong(long n);

#endif /*__MY_PRINTF*/
