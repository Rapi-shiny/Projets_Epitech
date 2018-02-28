/*
** main.c for main in /home/barret_l/rendu/Prog_elem/CPE_2015_bsq
**
** Made by Ludovic BARRETEAU
** Login   <barret_l@epitech.net>
**
** Started on  Tue Nov 24 09:09:19 2015 Ludovic BARRETEAU
** Last update Sat Dec 19 18:17:56 2015 Ludovic BARRETEAU
*/

#include "includes/bsq.h"

void	add_in_tab(char *str, int nbr_lines, int nbr_col, t_square square)
{
  char	tab[nbr_lines][nbr_col];
  int	i;
  int	line;
  int	col;

  i = 0;
  line = 0;
  col = 0;
  while (str[i] != '\0')
    {
      if (col > nbr_col - 1)
	{
	  col = 0;
	  line++;
	}
      if (str[i] != '\n')
	tab[line][col++] = str[i];
      i++;
    }
  my_add_square(nbr_lines, nbr_col, tab, square);
  my_aff_tab(nbr_lines, nbr_col, tab, my_strlen(str));
}

char	*modify_area(char *str)
{
  char	*result;
  int	i;
  int	j;

  i = 0;
  j = 0;
  if ((result = malloc(sizeof(*result) * my_strlen(str))) == NULL)
    return (0);
  while (str[i] != '\n')
    i++;
  i++;
  while (str[i] != '\0')
    result[j++] = str[i++];
  return (result);
}

int	get_col(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\n')
    i++;
  return (i);
}

int		my_bsq(char *buffer)
{
  char		*str;
  t_square	square;

  str = modify_area(buffer);
  square.pos_x = 0;
  square.pos_y = 0;
  square.size = 0;
  add_in_tab(str, get_lines(str), get_col(str), square);
  return (0);
}

int		main(int argc, char **argv)
{
  int		ret;
  int		fd;
  struct stat	stats;
  char		*buffer;

  if (argc == 2)
    {
      stat(argv[1], &stats);
      if ((buffer = malloc(sizeof(*buffer) * stats.st_size)) == NULL)
	return (1);
      fd = open(argv[1], O_RDONLY);
      ret = read(fd, buffer, (stats.st_size));
      if (ret == -1)
	{
	  my_putstr("Error with the source file\n");
	  return (1);
	}
      buffer[ret] = '\0';
      my_bsq(buffer);
      close(fd);
      free(buffer);
    }
  else
    my_putstr("how to use: ./program file_name\n");
  return (0);
}
