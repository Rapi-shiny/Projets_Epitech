/*
** dante.h for  in /home/barret_l/rendu/Initiation_IA/dante
** 
** Made by Ludovic BARRETEAU
** Login   <barret_l@epitech.net>
** 
** Started on  Wed Apr 27 14:17:49 2016 Ludovic BARRETEAU
** Last update Tue May 10 13:50:03 2016 Ludovic BARRETEAU
*/

#ifndef _DANTE_H
#define _DANTE_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

typedef	struct	s_maze
{
  char	**tab;
  char	**tab_algo;
  int	lines;
  int	cols;
  int	nb_imp;
  int	num_free;
}	t_maze;

char	*get_laby(char *);
int     my_strlen(char *str);
void    my_putstr(char *str, int check);
int     get_nbr_lines(char *str);
int     get_nbr_cols(char *str);
char	**str_to_tab(char **tab, char *str);
void    show_tab(t_maze *maze);
char    *buff_to_str(char *buff);
int	create_tabs(t_maze *maze, char *str);
void    free_tab(char **tab);
int     solver(t_maze *maze);
void	clean_laby(t_maze *maze);
int     check_impossible(int x, int y);
void    show_tab(t_maze *maze);
void    show_tab2(t_maze *maze);
int     check_dir(t_maze *maze, int x, int y, int check);
int     check_imp(t_maze *maze, int x, int y);
int     check_end(t_maze *maze, int x, int y);
void	check_imp_up(t_maze *maze, int x, int y);
void	check_imp_right(t_maze *maze, int x, int y);
void	check_imp_down(t_maze *maze, int x, int y);
void	check_imp_left(t_maze *maze, int x, int y);
int     check_move(t_maze *maze, int x, int y, int i);
void    move_right(t_maze *maze, int *x, int *y);
void    move_left(t_maze *maze, int *x, int *y);
void    move_up(t_maze *maze, int *x, int *y);
void    move_down(t_maze *maze, int *x, int *y);
void    go_back(t_maze *maze, int *x, int *y);

#include <stdio.h>

#endif
