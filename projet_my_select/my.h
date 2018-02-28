/*
** my.h for my in /home/barret_l/rendu/Systeme_unix/PSU_2015_my_printf/include
** 
** Made by Ludovic BARRETEAU
** Login   <barret_l@epitech.net>
** 
** Started on  Thu Nov 12 10:34:04 2015 Ludovic BARRETEAU
** Last update Thu Nov 12 15:33:33 2015 Ludovic BARRETEAU
*/

#ifndef MY_H_
#define MY_H_

int     my_char_isprintable(char c);
int	my_putchar(char c, int *nb_char);
int     my_put_nbr_unsigned(unsigned int  nbr);
int     get_size_result(int nbr, char *base, int base_size);
int     get_check_value(int nbr);
int     get_check_value(int nbr);
int     my_putnbr_base(unsigned int  nbr, char *base);
int     my_put_nbr_unsigned(unsigned int  nbr);
int	my_strlen(char *str);
int     my_putnbr_base_long(long  nbr, char *base);
char    *my_revstr(char *str);
int     my_printf(const char* format, ...);
int     my_put_nbr(int  nbr);
char    *my_strcpy(char *dest, char  *src);
int     my_printf_flags(const char *format, va_list ap, int i, int *nb_char);
int     my_printf_flags_bis(const char *format, va_list ap, int i);

#endif
