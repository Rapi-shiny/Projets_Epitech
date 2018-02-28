/*
** my_put_nbr.c for my_put_nbr in /home/barret_l/rendu/Piscine_C_J03
** 
** Made by Ludovic BARRETEAU
** Login   <barret_l@epitech.net>
** 
** Started on  Thu Oct  1 09:33:20 2015 Ludovic BARRETEAU
** Last update Mon Nov 16 12:28:22 2015 Ludovic BARRETEAU
*/

int	my_put_nbr(int  nbr)
{
  int	div;

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
