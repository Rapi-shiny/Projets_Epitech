/*
** my_putchar.c for my_putchar in /home/barret_l/rendu/tests
** 
** Made by Ludovic BARRETEAU
** Login   <barret_l@epitech.net>
** 
** Started on  Thu Oct  1 10:44:57 2015 Ludovic BARRETEAU
** Last update Tue Oct  6 09:50:49 2015 Ludovic BARRETEAU
*/

void	my_putchar(char c)
{
  write(1, &c, 1);
}
