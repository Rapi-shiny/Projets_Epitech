/*
** list.c for  in /home/barret_l/rendu/Initiation_IA/dante/solver_larg/src
** 
** Made by Ludovic BARRETEAU
** Login   <barret_l@epitech.net>
** 
** Started on  Tue May 17 11:25:36 2016 Ludovic BARRETEAU
** Last update Fri May 20 16:59:14 2016 Ludovic BARRETEAU
*/

#include "dante.h"

t_graph  *create_list(void)
{
  t_graph        *root;

  if ((root = malloc(sizeof(*root))) != NULL)
    {
      root->prev = root;
      root->next = root;
    }
  return (root);
}

void    add_after(t_graph *elem, int x, int y, t_graph *graph)
{
  t_graph        *new_elem;

  if ((new_elem = malloc(sizeof(*new_elem))) != NULL)
    {
      new_elem->x = x;
      new_elem->y = y;
      new_elem->parent = graph->prev->next;
      new_elem->prev = elem->prev;
      new_elem->next = elem;
      elem->prev->next = new_elem;
      elem->prev = new_elem;
    }
}

int	my_show_list(t_graph *list)
{
  t_graph        *i;

  if ((i = malloc(sizeof(*i))) == NULL)
    return (1);
  i = list->next;
  while (i != list)
    {
      printf("x = %d, y = %d\n", i->x, i->y);
      i = i->next;
    }
  return (0);
}
