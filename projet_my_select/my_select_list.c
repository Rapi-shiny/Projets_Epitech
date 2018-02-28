/*
** my_select_list.c for my_select_list in /home/barret_l/rendu/Systeme_unix/PSU_2015_my_select
** 
** Made by Ludovic BARRETEAU
** Login   <barret_l@epitech.net>
** 
** Started on  Wed Dec  2 12:44:33 2015 Ludovic BARRETEAU
** Last update Sun Dec 13 16:24:08 2015 Ludovic BARRETEAU
*/

#include "includes/my_select.h"

int     my_show_list(t_list *list)
{
  t_list        *i;
  t_pos		pos;

  pos.lines = 0;
  pos.cols = 0;
  if ((i = malloc(sizeof(*i))) == NULL)
    return (0);
  i = list->next;
  while (i != list)
    {
      i->elem_pos.lines = pos.lines;
      i->elem_pos.cols = pos.cols;
      my_show_list_bis(i, &pos, list);
      i = i->next;
    }
}

t_list  *create_list(void)
{
  t_list        *root;

  if ((root = malloc(sizeof(*root))) != NULL)
    {
      root->name = NULL;
      root->prev = root;
      root->next = root;
    }
  return (root);
}

void    add_after(t_list *elem, char *name)
{
  t_list        *new_elem;

  if ((new_elem = malloc(sizeof(*new_elem))) != NULL)
    {
      new_elem->name = name;
      new_elem->check = 0;
      new_elem->prev = elem->prev;
      new_elem->next = elem;
      elem->prev->next = new_elem;
      elem->prev = new_elem;
    }
}

int	max_size(t_list *list)
{
  int	size;

  size = 0;
  list = list->next;
  while (list->name != NULL)
    {
      if (my_strlen(list->name) > size)
	size = my_strlen(list->name);
      list = list->next;
    }
  return (size);
}
