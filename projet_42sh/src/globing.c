/*
** globing.c for globing in /home/jahan_a/trashtest/globing
** 
** Made by antoine jahan
** Login   <jahan_a@epitech.net>
** 
** Started on  Fri May 20 09:54:35 2016 antoine jahan
** Last update Sun Jun  5 18:46:42 2016 antoine jahan
*/

#include "globing.h"

void	build_glob_str(t_myglob *t, int i)
{
  int	savei;
  int	j;
  int	k;

  savei = i;
  j = 0;
  while ((unsigned)j < t->gl.gl_pathc)
    {
      k = 0;
      while (t->gl.gl_pathv[j][k])
	t->new[i++] = t->gl.gl_pathv[j][k++];
      j++;
      if ((unsigned)j < t->gl.gl_pathc)
	t->new[i++] = ' ';
    }
  t->next = i;
  while (t->str[savei] != ' ' && t->str[savei] != '\t' && t->str[savei] != 0)
    savei++;
  while (t->str[savei])
    t->new[i++] = t->str[savei++];
  t->new[i] = 0;
}

void	end_globing(t_myglob *t, int pos)
{
  int	i;
  int	total;

  i = 0;
  total = my_strlen(t->str);
  while ((unsigned)i < t->gl.gl_pathc)
    total += my_strlen(t->gl.gl_pathv[i++]) + 1;
  if ((t->new = malloc(sizeof(*t->new) * total)) == NULL)
    exit(0);
  i = -1;
  while (pos > 0 && t->str[pos - 1] != ' ' && t->str[pos - 1] != '\t')
    pos--;
  while (++i < pos)
    t->new[i] = t->str[i];
  build_glob_str(t, i);
}

int	first_match(t_myglob *t, int i)
{
  int		x;
  int		y;
  char		*temp;

  x = i;
  y = i;
  while (x > 0 && t->str[x - 1] != ' ' && t->str[x - 1] != '\t')
    x--;
  while (t->str[y] != ' ' && t->str[y] != '\t' && t->str[y] != 0)
    y++;
  temp = cuts(t->str, x, y);
  if (glob(temp, 0, NULL, &t->gl) == GLOB_NOMATCH)
    return (free(temp), -1);
  end_globing(t, i);
  free(temp);
  globfree(&t->gl);
  return (0);
}

int	second_match(t_myglob *t, int i)
{
  int		x;
  int		y;
  char		*temp;

  x = i;
  y = i;
  if (check_crochet(t->str, i) == -1)
    return (-1);
  while (x > 0 && t->str[x - 1] != ' ' && t->str[x - 1] != '\t')
    x--;
  while (t->str[y] != ' ' && t->str[y] != '\t' && t->str[y] != 0)
    y++;
  temp = cuts(t->str, x, y);
  if (glob(temp, 0, NULL, &t->gl) == GLOB_NOMATCH)
    return (free(temp), -1);
  end_globing(t, i);
  free(temp);
  globfree(&t->gl);
  return (0);
}

char	*globing(char *str)
{
  t_myglob	t;
  int		i;
  int		ret;

  i = 0;
  t.str = str;
  ret = 2;
  while (i < my_strlen(str) && str[i])
    {
      if (str[i] == '*' || str[i] == '?')
	{
	  t.next = i + 1;
	  ret = first_match(&t, i);
	  i = t.next;
	}
      if (i <= my_strlen(str) && str[i] && str[i] == '[')
        {
	  t.next = i + 1;
          ret = second_match(&t, i);
          i = t.next;
        }
      i++;
    }
  return (glob_ret(ret, t));
}
