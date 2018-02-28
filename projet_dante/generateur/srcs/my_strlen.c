/*
** my_strlen.c for  in /home/barret_l/rendu/Initiation_IA/dante/generateur/srcs
** 
** Made by Ludovic BARRETEAU
** Login   <barret_l@epitech.net>
** 
** Started on  Sat May 28 12:14:12 2016 Ludovic BARRETEAU
** Last update Sat May 28 12:14:49 2016 Ludovic BARRETEAU
*/

#include "generator.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}
