/*
** var_env.c for  in /home/barret_l/rendu/Systeme_unix/42_labo/var_env
** 
** Made by Ludovic BARRETEAU
** Login   <barret_l@epitech.net>
** 
** Started on  Tue May 31 12:41:46 2016 Ludovic BARRETEAU
** Last update Sun Jun  5 19:10:35 2016 Celenzo CRESPIN
*/

#include "minishell.h"

char	*var_env_bis(char *str, int *i)
{
  while (str[*i] != '$')
    *i = *i - 1;
  *i = *i + 1;
  fprintf(stderr, "%s: Undefined variable.\n", str + *i);
  return (NULL);
}

char    *my_varcat(char *dest, char *src)
{
  char	*result;
  int   len_dest;
  int   i;

  i = 0;
  if ((result = malloc(my_slen(dest) + my_slen(src) + 30)) == NULL)
    return (NULL);
  while (dest[i])
    {
      result[i] = dest[i];
      i++;
    }
  result[i] = 0;
  len_dest = my_slen(result);
  i = 0;
  while (src[i] != '\0')
    result[len_dest++] = src[i++];
  result[len_dest] = '\0';
  free(dest);
  return (result);
}

char	*var_env(char *str, char **env, int i, int j)
{
  char	*ret;
  char	*result;

  if ((result = malloc(sizeof(*result) * (my_slen(str)))) == NULL)
    exit(1);
  while (str[i])
    {
      result[j] = 0;
      if (str[i] == '$')
	{
	  ret = get_var_env(env, &str[i + 1], &i);
	  if (ret == NULL)
	    return (var_env_bis(str, &i));
	  else
	    {
	      result = my_varcat(result, ret);
	      j = j + my_slen(ret);
	    }
	}
      else
	result[j++] = str[i];
      i++;
    }
  return (result[j] = 0, result);
}
