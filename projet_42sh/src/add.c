/*
** add.c for add in /home/hedoui_r/PSU_2015_42sh
** 
** Made by Romain Hedouin
** Login   <hedoui_r@epitech.net>
** 
** Started on  Sun Jun  5 20:12:09 2016 Romain Hedouin
** Last update Sun Jun  5 20:31:47 2016 Romain Hedouin
*/

#include "minishell.h"

t_history		*add_and_keep(char *buf, int choice)
{
  static t_history      *my_history = NULL;

  if (choice == 0)
    {
      if (my_history == NULL)
	my_history = create_history();
      add_cmd_hist(my_history, buf);
    }
  if (choice == 1)
    return (my_history);
  return (NULL);
}
