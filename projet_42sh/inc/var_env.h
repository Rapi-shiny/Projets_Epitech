/*
** var_env.h for  in /home/barret_l/rendu/Systeme_unix/42_labo/var_env
** 
** Made by Ludovic BARRETEAU
** Login   <barret_l@epitech.net>
** 
** Started on  Fri Jun  3 10:35:42 2016 Ludovic BARRETEAU
** Last update Sun Jun  5 17:46:54 2016 Celenzo CRESPIN
*/

#ifndef _VAR_ENV_H
#define _VAR_ENV_H

int     check_alpha_num(char c);
char    *get_var_env(char **env, char *str, int *k);
void    get_var_env_bis(char *str, int *j, int *check, int *k);
char    *var_env(char *str, char **env, int i, int j);
char    *var_env_bis(char *str, int *i);

#endif
