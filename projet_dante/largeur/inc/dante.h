/*
** dante.h for  in /home/barret_l/rendu/Initiation_IA/dante/solver_larg/inc
** 
** Made by Ludovic BARRETEAU
** Login   <barret_l@epitech.net>
** 
** Started on  Tue May 10 13:42:15 2016 Ludovic BARRETEAU
** Last update Sat May 21 11:49:56 2016 Ludovic BARRETEAU
*/

#ifndef _DANTE_H
#define _DANTE_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct  s_maze
{
  char  **tab;
  char  **tab_algo;
  int   lines;
  int   cols;
}       t_maze;

typedef struct		s_graph
{
  int			x;
  int			y;
  struct s_graph	*parent;
  struct s_graph	*next;
  struct s_graph	*prev;
}	t_graph;

void    free_tab(char **tab);
int     create_tabs(t_maze *maze, char *str);
char    *get_laby(char  *name_file);
int     my_strlen(char *str);
void    my_putstr(char *str, int check);
char    *buff_to_str(char *buff);
void    show_tab(t_maze *maze);
int     get_nbr_lines(char *str);
int     get_nbr_cols(char *str);
char    **str_to_tab(char **tab, char *str);
t_graph  *create_list(void);
void    add_after(t_graph *elem, int x, int y, t_graph *graph);
int	my_show_list(t_graph *list);
int     start_solver(t_maze *maze);
int     check_list(t_graph *lane, t_maze *maze);
t_graph *get_end(t_graph *lane, t_maze *maze);
void    solve_laby(t_graph *lane, t_maze *maze);
void    check_up(t_maze *maze, t_graph *lane, t_graph *i);
void    check_right(t_maze *maze, t_graph *lane, t_graph *i);
void    check_left(t_maze *maze, t_graph *lane, t_graph *i);
void    check_down(t_maze *maze, t_graph *lane, t_graph *i);
int     check_dir(t_maze *maze, int x, int y, int check);

#endif
