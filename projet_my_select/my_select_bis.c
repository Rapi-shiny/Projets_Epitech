/*
** my_select_bis.c for my_select_bis in /home/barret_l/rendu/Systeme_unix/PSU_2015_my_select
** 
** Made by Ludovic BARRETEAU
** Login   <barret_l@epitech.net>
** 
** Started on  Fri Dec 11 09:55:04 2015 Ludovic BARRETEAU
** Last update Sun Dec 13 16:22:52 2015 Ludovic BARRETEAU
*/

#include "includes/my_select.h"

void	move_cursos_bis(int key, t_list **select, t_pos **pos, int *check)
{
  if (key == KEY_DOWN)
    {
      if ((*select)->next->name == NULL)
	{
	  *select = (*select)->next->next;
	  (*pos)->lines = (*select)->elem_pos.lines;
	  (*pos)->cols = (*select)->elem_pos.cols;
	}
      else
	{
	  *select = (*select)->next;
	  (*pos)->lines = (*select)->elem_pos.lines;
	  (*pos)->cols = (*select)->elem_pos.cols;
	}
    }
  move_cursor_ter(key, select, pos, check);
  if (key == 27)
  *check = 1;
}

int	move_cursor_show(t_list **select, t_pos *pos)
{
  int	key;

  key = 0;
  attron(A_UNDERLINE);
  if ((*select)->check == 1)
    {
      attron(A_STANDOUT);
      printw((*select)->name);
      attroff(A_STANDOUT);
    }
  else
    printw((*select)->name);
  attroff(A_UNDERLINE);
  key = getch();
  return (key);
}

void	select_options()
{
  curs_set(0);
  noecho();
  keypad(stdscr, TRUE);
}

void	my_show_list_bis(t_list *i, t_pos *pos, t_list *list)
{
  if (i->check == 1)
    {
      attron(A_STANDOUT);
      printw(i->name);
      attroff(A_STANDOUT);
    }
  else
    printw(i->name);
  pos->lines++;
  if (pos->lines < LINES)
    move(pos->lines, pos->cols);
  else
    {
      pos->cols = pos->cols + max_size(list) + 1;
      if (pos->cols > COLS)
	{
	  endwin();
	  exit(0);
	}
      pos->lines = 0;
      move(pos->lines, pos->cols);
    }
}

void	my_delete_elem(t_list **list, t_list **select, int key)
{
  if (key == 'v')
    {
      while ((*list)->next != (*select)->next)
	{
	  *list = (*list)->next;
	}
      (*select)->prev->next = (*select)->next;
      (*select)->next->prev = (*select)->prev;
      (*list)->prev->next = (*list)->next;
      (*list)->next->prev = (*list)->prev;
      while ((*list)->name != NULL)
        {
          *list = (*list)->next;
        }
    }
}
