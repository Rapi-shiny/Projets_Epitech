/*
** my_strlen.c for my_strlen in /home/barret_l/rendu/Piscine_C_J04
** 
** Made by Ludovic BARRETEAU
** Login   <barret_l@epitech.net>
** 
** Started on  Thu Oct  1 23:05:19 2015 Ludovic BARRETEAU
** Last update Tue Oct  6 10:09:40 2015 Ludovic BARRETEAU
*/

int my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}
