/*
** history.c for  in /home/barret_l/rendu/Systeme_unix/42_labo
** 
** Made by Ludovic BARRETEAU
** Login   <barret_l@epitech.net>
** 
** Started on  Fri May  6 10:17:35 2016 Ludovic BARRETEAU
** Last update Sun Jun  5 21:19:54 2016 Romain Hedouin
*/

#include "history.h"

t_history	*create_history(void)
{
  t_history	*root;

  if ((root = malloc(sizeof(*root))) != NULL)
    {
      root->next = root;
      root->prev = root;
    }
  return (root);
}

void    add_cmd_hist(t_history *elem, char *cmd)
{
  t_history	*new_elem;
  static int	num;

  if ((new_elem = malloc(sizeof(*new_elem))) != NULL)
    {
      num++;
      new_elem->num_cmd = num;
      new_elem->cmd = cmd;
      new_elem->prev = elem->prev;
      new_elem->next = elem;
      elem->prev->next = new_elem;
      elem->prev = new_elem;
      new_elem->select = 0;
    }
}

void	nb_space(int num)
{
  int	i;
  int	j;

  i = 0;
  while (num / 10 > 0)
    {
      i++;
      num /= 10;
    }
  j = 0;
  while (j < (4 - i))
    {
      printf(" ");
      j++;
   }
}

void		history(t_history *my_history)
{
  t_history	*i;

  i = my_history->next;
  while (i != my_history)
    {
      nb_space(i->num_cmd);
      printf("%d  %s\n", i->num_cmd, i->cmd);
      i = i->next;
    }
}

int	free_history(t_history *my_history)
{
  t_history     *i;

  i = my_history->next;
  while (i != my_history)
    {
      free(i->cmd);
      i = i->next;
      free(i->prev);
    }
  free(i);
  return (0);
}
