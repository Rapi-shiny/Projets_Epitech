/*
** my_select.h for my_select in /home/barret_l/rendu/Systeme_unix/PSU_2015_my_select
** 
** Made by Ludovic BARRETEAU
** Login   <barret_l@epitech.net>
** 
** Started on  Wed Dec  2 12:50:48 2015 Ludovic BARRETEAU
** Last update Sat Dec 12 15:15:32 2015 Ludovic BARRETEAU
*/

#ifndef MY_SELECT_H_
#define MY_SELECT_H_

#include <ncurses.h>
#include <string.h>
#include <curses.h>
#include <stdlib.h>

typedef struct s_pos
{
  int   lines;
  int   cols;
}       t_pos;

typedef struct s_list
{
  char          *name;
  t_pos		elem_pos;
  int		check;
  struct s_list *next;
  struct s_list *prev;
}       t_list;

int	move_cursor(t_list *list, t_list **select, t_pos *pos, int *check);
int     my_select(int argc, char **argv, int i, t_pos pos);
void    move_cursos_bis(int key, t_list **select, t_pos **pos, int *check);
int     move_cursor_show(t_list **select, t_pos *pos);
void    select_options();
void    my_show_list_bis(t_list *i, t_pos *pos, t_list *list);
void    my_delete_elem(t_list **list, t_list **select, int key);
void    move_cursor_ter(int key, t_list **select, t_pos **pos, int *check);
int     my_show_list(t_list *list);
t_list  *create_list(void);
void    add_after(t_list *elem, char *name);

#endif
