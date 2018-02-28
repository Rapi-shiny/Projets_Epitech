/*
** my_char_isnum.c for my_char_isnum in /home/barret_l/rendu/tests/lib
** 
** Made by Ludovic BARRETEAU
** Login   <barret_l@epitech.net>
** 
** Started on  Fri Oct  9 11:12:07 2015 Ludovic BARRETEAU
** Last update Fri Oct  9 11:13:12 2015 Ludovic BARRETEAU
*/

int	my_char_isnum(char c)
{
  if (c >= '0' && c <= '9')
    return (1);
  else
    return (0);
}
