/*
** my_putstr.c for my_putstr in /home/barret_l/rendu/Piscine_C_J04
** 
** Made by Ludovic BARRETEAU
** Login   <barret_l@epitech.net>
** 
** Started on  Thu Oct  1 14:06:57 2015 Ludovic BARRETEAU
** Last update Wed Oct  7 10:43:43 2015 Ludovic BARRETEAU
*/

int my_putstr(char *str)
{
  int	i;

  i = 0;
  while (*(str  + i) != '\0')
    {
      my_putchar(*(str + i));
      i = i + 1;
    }
}
