/*
** stuff3.c for  in /home/crespi_c/rendu/Elementary_C/PSU_2015_minishell1/src
** 
** Made by Celenzo CRESPIN
** Login   <crespi_c@epitech.net>
** 
** Started on  Tue Mar 29 14:47:55 2016 Celenzo CRESPIN
** Last update Sun Jun  5 21:21:14 2016 Romain Hedouin
*/

#include "minishell.h"

char		*my_strcat(char *s1, char *s2)
{
  int		i;
  int		j;
  char		*out;

  i = 0;
  j = 0;
  if ((out = malloc(my_strlen(s1) + my_strlen(s2) + 1)) == NULL)
    exit(5);
  while (s1[i])
    {
      out[i] = s1[i];
      i++;
    }
  while (s2[j])
    out[i++] = s2[j++];
  return (out[i] = 0, out);
}

void		print_err(int err)
{
  int		sig;
  char		*ers[31] = {E_SIGHUP, E_SIGINT, E_SIGQUIT, E_SIGILL, E_SIGTRAP,
			    E_SIGABRT, E_SIGIOT, E_SIGBUS, E_SIGFPE, E_SIGKILL,
			    E_SIGUSR1, E_SIGSEGV, E_SIGUSR2, E_SIGPIPE,
			    E_SIGALRM, E_SIGTERM, E_SIGSTKFLT, E_SIGCHLD,
			    E_SIGCONT, E_SIGSTOP, E_SIGTSTP, E_SIGTTIN,
			    E_SIGTTOU, E_SIGURG, E_SIGXCPU, E_SIGXFSZ,
			    E_SIGVTARLM, E_SIGIO, E_SIGPOLL, E_SIGPWR, E_SIGSYS};

  sig = WTERMSIG(err);
  if (sig <= 0 || sig > 30)
    return ;
  write(2, ers[sig], my_strlen(ers[sig]));
}

char		*my_getcwd()
{
  char		*out;

  if ((out = malloc(MAX_PATH_SIZE)) == NULL)
    exit(5);
  getcwd(out, MAX_PATH_SIZE);
  return (out);
}

int		get_suite(char *buf, int i, char c)
{
  i += deb_cmd(buf + i, c);
  if (buf[i] == ' ')
    i++;
  return i;
}

char		*my_strdup(char *s)
{
  int		i;
  char		*out;

  i = -1;
  if ((out = malloc(sizeof(*out) * (my_strlen(s) + 1))) == NULL)
    exit(5);
  while (s[++i])
    out[i] = s[i];
  out[i] = 0;
  return out;
}
