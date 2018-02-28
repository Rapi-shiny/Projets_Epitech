/*
** history_bis.c for  in /home/barret_l/rendu/Systeme_unix/42_labo
** 
** Made by Ludovic BARRETEAU
** Login   <barret_l@epitech.net>
** 
** Started on  Tue May 31 10:38:14 2016 Ludovic BARRETEAU
** Last update Sun Jun  5 20:52:48 2016 Romain Hedouin
*/

#include "minishell.h"
#include "history.h"

char    *get_prev_cmd(t_history *my_history)
{
  t_history     *i;

  if ((i = (malloc(sizeof(t_history *) + 1))) == NULL)
    return (NULL);
  i = my_history->prev;
  while (i != my_history)
    {
      if (i->select == 1)
        {
          if (i->prev != my_history)
            {
              i->prev->select = 1;
              i->select = 0;
              return (i->prev->cmd);
            }
          else
            return (i->cmd);
        }
      i = i->prev;
    }
  my_history->prev->select = 1;
  return (my_history->prev->cmd);
}

char    *get_next_cmd(t_history *my_history)
{
  t_history     *i;

  if ((i = malloc(sizeof(t_history))) == NULL)
    return (NULL);
  i = my_history->next;
  while (i != my_history)
    {
      if (i->select == 1)
        {
          if (i->next != my_history)
            {
              i->next->select = 1;
              i->select = 0;
              return (i->next->cmd);
            }
          else
            return (i->cmd);
        }
      i = i->next;
    }
  return (NULL);
}

int     check_exist_hist(t_history *my_history, char *var)
{
  t_history     *i;

  i = my_history->prev;
  if (strcmp(i->cmd, var) == 0)
    return (1);
  return (0);
}

char	*ret2(char *str, t_history *my_history)
{
  t_history     *i;
  char		*result;
  int		j;

  j = 0;
  result = " ";
  result = strcat(my_strdup("history"), my_strdup(result));
  result = strcat(my_strdup(result), my_strdup(str));
  add_cmd_hist(my_history, result);
  i = my_history->prev;
  while (++j < my_getnbr(str) + 1 && i)
    i = i->prev;
  while (j > 0 && i->next && i->next->cmd)
    {
      printf("%s\n", i->cmd);
      i = i->next;
      j--;
    }
  return (NULL);
}

char	*ret_line(t_history *my_history, char *str, int check)
{
  t_history     *i;

  if (check == 0)
    {
      i = my_history->prev;
      while (i != my_history)
	{
	  if (verif_nb(str) == 0 && i->num_cmd == my_getnbr(str))
	    return (my_strdup(i->cmd));
	  else
	    if (my_strncmp(str, i->cmd, my_strlen(str) - 1) == 0)
	      return (my_strdup(i->cmd));
	  i = i->prev;
	}
    }
  else
    ret2(str, my_history);
  return (str);
}

