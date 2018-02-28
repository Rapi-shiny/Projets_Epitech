/*
** my_select_ter.c for my_select_ter in /home/barret_l/rendu/Systeme_unix/PSU_2015_my_select
** 
** Made by Ludovic BARRETEAU
** Login   <barret_l@epitech.net>
** 
** Started on  Sat Dec 12 11:50:08 2015 Ludovic BARRETEAU
** Last update Sat Dec 12 15:51:20 2015 Ludovic BARRETEAU
*/

#include "includes/my_select.h"

void	move_cursor_ter(int key, t_list **select, t_pos **pos, int *check)
{
  if (key == KEY_UP)
    {
      if ((*select)->prev->name == NULL)
        {
          *select = (*select)->prev->prev;
          (*pos)->lines = (*select)->elem_pos.lines;
          (*pos)->cols = (*select)->elem_pos.cols;
        }
      else
        {
          *select = (*select)->prev;
          (*pos)->lines = (*select)->elem_pos.lines;
          (*pos)->cols = (*select)->elem_pos.cols;
        }
    }
  if (key == ' ')
    {
      if ((*select)->check == 0)
        (*select)->check = 1;
      else
        (*select)->check = 0;
    }
}

