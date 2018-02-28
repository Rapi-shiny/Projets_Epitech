/*
** get_next_line.h for get_next_line in /home/barret_l/rendu/Prog_elem/CPE_2015_getnextline
** 
** Made by Ludovic BARRETEAU
** Login   <barret_l@epitech.net>
** 
** Started on  Mon Jan  4 10:11:54 2016 Ludovic BARRETEAU
** Last update Sat Feb 20 11:42:18 2016 Ludovic BARRETEAU
*/

#ifndef _GET_NEXT_LINE_H_
#define _GET_NEXT_LINE_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define READ_SIZE (1)

typedef struct	s_nbrs
{
  int		i;
  int		j;
  int		ret;
  int		k;
  char		*buffer;
}	t_nbrs;

char	*get_next_line(const int fd);
char    *check_static(t_nbrs *nbrs, char *save_str, char *str_result);
char    *my_realloc(char *str);
int     check_n(char *str);
char    *get_next_line_bis(t_nbrs *nbrs, char *save_str\
                           , char *str_result, const int fd);

#endif
