/*
** my_getnbr.c for my_getnbr.c in /home/barret_l/makefile/lib/my/WIP
** 
** Made by Ludovic BARRETEAU
** Login   <barret_l@epitech.net>
** 
** Started on  Thu Oct 15 14:28:08 2015 Ludovic BARRETEAU
** Last update Thu Oct 15 18:36:37 2015 Ludovic BARRETEAU
*/

int	my_verif_sign_getnbr(int *result, char *str)
{
  int	i;

  i = 0;
  *result = 0;
  if (str[0] == '-')
    {
      *result = -(str[1] - 48);
      return (i + 2);
    }
  if (my_char_isnum(str[0]) == 1)
    {
      *result = str[0] - 48;
      return (i + 1);
    }
}

int	my_getnbr(char *str)
{
  int	i;
  int	result;
  int	verif;

  result = 0;
  i = my_verif_sign_getnbr(&result, str);
  verif = result;
  while (str[i] != '\0')
    {
      if (my_char_isnum(str[i]) == 0)
	return (0);
      result = result * 10;
      if (result > 0)
	result = result + (str[i++] - 48);
      else
	result = result - (str[i++] - 48);
      if (verif > 0 && result < 0)
        return (0);
      if (verif < 0 && result > 0)
	return (0);
      verif = result;
    }
  return (result);
}
