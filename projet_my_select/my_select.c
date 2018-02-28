/*
** my_select.c for my_select in /home/barret_l/rendu/Systeme_unix/PSU_2015_my_select
** 
** Made by Ludovic BARRETEAU
** Login   <barret_l@epitech.net>
** 
** Started on  Wed Dec  2 11:18:06 2015 Ludovic BARRETEAU
** Last update Sun Dec 13 16:21:57 2015 Ludovic BARRETEAU
*/

#include "includes/my_select.h"

int		move_cursor(t_list *list, t_list **select, t_pos *pos, int *check)
{
  int		key;
  char		*str;
  t_list	*list_end;

  if ((list_end = malloc(sizeof(*list_end))) == NULL)
    return (0);
  list_end = list->next;
  key = move_cursor_show(select, pos);
  move_cursos_bis(key, select, &pos, check);
  if (key == 10)
    {
      endwin();
      while (list_end != list)
        {
          if (list_end->check == 1)
            {
              write(1, list_end->name, my_strlen(list_end->name));
              if (list_end->next != list && list_end->next->check == 1)
		write(1, " ", 1);
            }
          list_end = list_end->next;
        }
      exit(0);
    }
  return (0);
}

int	my_select(int argc, char **argv, int i, t_pos pos)
{
  t_list	*list;
  int		check;
  t_list	*select;

  check = 0;
  if ((select = malloc(sizeof(*select))) == NULL)
    return (0);
  if ((list = malloc(sizeof(*list))) == NULL)
    return (0);
  list = create_list();
  while (i < argc)
    add_after(list, argv [i++]);
  select = list->next;
  newterm(getenv("XTERM"), stderr, stdin);
  my_show_list(list);
  select_options();
  while (check == 0)
    {
      clear();
      my_show_list(list);
      move(pos.lines, pos.cols);
      move_cursor(list, &select, &pos, &check);
      refresh();
    }
  endwin();
}

int	main(int argc, char **argv)
{
  int	i;
  t_pos	pos;

  pos.lines = 0;
  pos.cols = 0;
  i = 1;
  if (argc > 1)
    {
      set_escdelay(25);
      my_select(argc, argv, i, pos);
    }
  else
    {
      my_putstr("Wrong number of arguments");
      return (-1);
    }
return (0);
}
