/*
** urgency_path.c for  in /home/crespi_c/rendu/PSU/PSU_2015_42sh
** 
** Made by Celenzo CRESPIN
** Login   <crespi_c@epitech.net>
** 
** Started on  Thu Jun  2 11:25:06 2016 Celenzo CRESPIN
** Last update Thu Jun  2 11:29:21 2016 Celenzo CRESPIN
*/

#include "minishell.h"

char		**set_urgency_path(char *s)
{
  char		**path;

  path = str_to_wordtab(s, ':');
  path[0] = skip_name(path[0]);
  return path;
}
