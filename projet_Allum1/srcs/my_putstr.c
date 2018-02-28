/*
** my_putstr.c for my_putstr in /home/barret_l/rendu/Prog_elem/CPE_2015_Allum1
** 
** Made by Ludovic BARRETEAU
** Login   <barret_l@epitech.net>
** 
** Started on  Tue Feb  9 13:38:46 2016 Ludovic BARRETEAU
** Last update Tue Feb  9 13:39:59 2016 Ludovic BARRETEAU
*/

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    my_putchar(str[i++]);
}
