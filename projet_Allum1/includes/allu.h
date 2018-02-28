/*
** allu.h for allu in /home/barret_l/rendu/Prog_elem/CPE_2015_Allum1
** 
** Made by Ludovic BARRETEAU
** Login   <barret_l@epitech.net>
** 
** Started on  Tue Feb  9 11:54:19 2016 Ludovic BARRETEAU
** Last update Wed Feb 24 17:56:15 2016 Ludovic BARRETEAU
*/

#ifndef ALLU_H_
#define ALLU_H_

#include "get_next_line.h"
#include <stdarg.h>

typedef struct  s_allu
{
  int           lines;
  int           columns;
  int           nb_space;
  int           tab_allu[4];
  int           max_size;
  int           nb_space_front[4];
  int           nb_space_back[4];
  int		max_allu;
  int		turn;
  int		error;
}       t_allu;

char	*get_next_line(const int fd);
char	*my_realloc(char *str);
void	my_putstr(char *str);
int     print_space(int columns, int check, t_allu *allu);
void	show_stars();
void	print_board(t_allu *allu);
void	print_updated_board_game(int line\
				 , int nb_matches, t_allu *allu);
void	show_errors_matches(int nb_matches, t_allu *allu, int line);
int	show_errors_line(int line, t_allu *allu);
int	check_end(t_allu *allu);
int	calc_nb_allu(t_allu *allu);
void	game_ai(t_allu *allu);
int	game(t_allu *allu);
int	my_char_isnum(char c);
void    my_putchar(char c);
void    my_putstr(char *str);
void	my_put_nbr(int  nbr);
int     my_printf(const char* format, ...);
int     my_printf_flags(const char *format, va_list ap, int i);
int     my_verif_sign_getnbr(int *result, char *str);
int     my_getnbr(char *str);
int     game_ai_one(t_allu *allu, int nb_allu);
int     game_ai_two(t_allu *allu);
int     game_bis(t_allu *allu, char *my_line, int line);
void    show_errors_line_bis(int line, t_allu *allu);
int     my_strlen(char *str);

#endif
