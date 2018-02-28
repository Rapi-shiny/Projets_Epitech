/*
** var_env_bis.c for  in /home/barret_l/rendu/Systeme_unix/42_labo/var_env
** 
** Made by Ludovic BARRETEAU
** Login   <barret_l@epitech.net>
** 
** Started on  Fri Jun  3 13:46:53 2016 Ludovic BARRETEAU
** Last update Sun Jun  5 17:50:19 2016 Celenzo CRESPIN
*/

#include "minishell.h"

int     check_alpha_num(char c)
{
  if (c >= '0' && c <= '9')
    return (1);
  if (c >= 'A' && c <= 'Z')
    return (1);
  if (c >= 'a' && c <= 'z')
    return (1);
  return (0);
}

void    get_var_env_bis(char *str, int *j, int *check, int *k)
{
  if (check_alpha_num(str[*j - 1]) == 0 && *check == 0)
    {
      *check = 1;
      *j = *j - 1;
      *k = *k - 1;
    }
}

char    *get_var_env(char **env, char *str, int *k)
{
  int   i;
  int   j;
  int   save_k;
  int   check;

  i = 0;
  save_k = *k;
  while (env[i])
    {
      *k = save_k;
      j = 0;
      check = 1;
      while ((str[j] != ' ' && str[j] && str[j] != '\n') && check != 0)
        {
          if (str[j] != env[i][j])
            check = 0;
          *k = *k + 1;
          j++;
        }
      get_var_env_bis(str, &j, &check, k);
      if (check == 1 && env[i][j] == '=')
        return (&env[i][j + 1]);
      i++;
    }
  return (NULL);
}
