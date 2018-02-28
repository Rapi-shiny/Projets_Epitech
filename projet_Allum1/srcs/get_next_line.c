/*
** get_next_line.c for get_next_line in /home/barret_l/rendu/Prog_elem/CPE_2015_getnextline
** 
** Made by Ludovic BARRETEAU
** Login   <barret_l@epitech.net>
** 
** Started on  Mon Jan  4 10:18:31 2016 Ludovic BARRETEAU
** Last update Wed Feb 24 17:51:32 2016 Ludovic BARRETEAU
*/

#include "../includes/allu.h"

char	*my_realloc(char *str)
{
  char	*new_str;
  int	i;
  int	j = 0;

  i = 0;
  while (str[j] != '\0')
    j++;
  if ((new_str = malloc(sizeof(str) * (j + READ_SIZE + 1))) == NULL)
    return (0);
  while (i < j)
    {
      new_str[i] = str[i];
      i++;
    }
  new_str[i] = '\0';
  return (new_str);
}

int	check_n(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '\n')
	return (1);
      i++;
    }
  return (0);
}

char	*check_static(t_nbrs *nbrs, char *save_str, char *str_result)
{
  if (check_n(save_str) == 0)
    {
      while (save_str[nbrs->k] != '\0')
	str_result[nbrs->i++] = save_str[nbrs->k++];
      str_result[nbrs->i] = '\0';
      save_str[0] = '\0';
    }
  else
    {
      while (save_str[nbrs->k] != '\n')
	str_result[nbrs->i++] = save_str[nbrs->k++];
      str_result[nbrs->i] = '\0';
      nbrs->k++;
      while (save_str[nbrs->k] != '\0')
	save_str[nbrs->j++] = save_str[nbrs->k++];
      save_str[nbrs->j] = '\0';
      return (str_result);
    }
  return (str_result);
}

char	*get_next_line_bis(t_nbrs *nbrs, char *save_str\
			   , char *str_result, const int fd)
{
  while ((nbrs->ret = read(fd, nbrs->buffer, READ_SIZE)) \
         && (check_n(nbrs->buffer) == 0))
    {
      nbrs->buffer[nbrs->ret] = '\0';
      nbrs->j = 0;
      while (nbrs->buffer[nbrs->j] != '\0')
        str_result[nbrs->i++] = nbrs->buffer[nbrs->j++];
      str_result = my_realloc(str_result);
    }
  if (nbrs->ret == 0)
    return (NULL);
  nbrs->j = 0;
  nbrs->k = 0;
  if (check_n(nbrs->buffer) == 1)
    {
      while (nbrs->buffer[nbrs->j] != '\n')
        str_result[nbrs->i++] = nbrs->buffer[nbrs->j++];
      nbrs->j++;
      while (nbrs->buffer[nbrs->j] != '\0')
        save_str[nbrs->k++] = nbrs->buffer[nbrs->j++];
      save_str[nbrs->k] = '\0';
    }
  str_result[nbrs->i] = '\0';
  return (str_result);
}

char		*get_next_line(const int fd)
{
  t_nbrs	nbrs;
  static char	save_str[READ_SIZE];
  char		*str_result;

  nbrs.i = 0;
  nbrs.j = 0;
  nbrs.k = 0;
  if ((str_result = malloc(sizeof(str_result) * READ_SIZE + 1)) == NULL)
    return (NULL);
  if ((nbrs.buffer = malloc(sizeof(nbrs.buffer) * READ_SIZE + 1)) == NULL)
    return (NULL);
  if (save_str[0] != '\0')
    {
      if (check_n(save_str) == 0)
	check_static(&nbrs, save_str, str_result);
      else
	return (check_static(&nbrs, save_str, str_result));
    }
  str_result = get_next_line_bis(&nbrs, save_str, str_result, fd);
  return (str_result);
}
