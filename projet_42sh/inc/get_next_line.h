/*
** get_next_line.h for  in /home/crespi_c/rendu/Elementary_C/CPE_2015_getnextline
** 
** Made by Celenzo CRESPIN
** Login   <crespi_c@epitech.net>
** 
** Started on  Wed Jan 13 20:05:27 2016 Celenzo CRESPIN
** Last update Sat Jun  4 12:20:44 2016 Celenzo CRESPIN
*/

#include <stdlib.h>
#include <unistd.h>

#ifndef READ_SIZE
# define READ_SIZE (1)
#endif

#ifndef _GET_NEXT_LINE
# define _GET_NEXT_LINE

char	*get_next_line(const int fd);

#endif
