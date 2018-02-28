/*
** my.h for my in /home/barret_l/rendu/Piscine_C_J09/include
** 
** Made by Ludovic BARRETEAU
** Login   <barret_l@epitech.net>
** 
** Started on  Thu Oct  8 18:34:46 2015 Ludovic BARRETEAU
** Last update Tue Oct 20 22:31:50 2015 Ludovic BARRETEAU
*/

#ifndef MY_H_
#define  MY_H_

void	my_putchar(char c);
int	my_isneg(int nb);
int	my_put_nbr(int nb);
int	my_swap(int *a, int *b);
int	my_putstr(char *str);
int	my_strlen(char *str);
int	my_getnbr(char *str);
void	my_sort_int_tab(int, int);
int	my_power_rec(int, int);
int	my_square_root(int nb);
int	my_is_prime(int nombre);
int	my_find_prime_sup(int nb);
char	*my_strcpy(char *dest, char *src);
char	*my_strncpy(char *dest, char *src, int nb);
char	*my_revstr(char *str);
char	*my_strstr(char *str, char *to_find);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int nb);
char	*my_strupcase(char *str);
char	*my_strlowcase(char *str);
char	*my_strcapitalize(char *str);
int	my_str_isalpha(char *str);
int	my_str_isnum(char *str);
int	my_str_islower(char *str);
int	my_str_isupper(char *str);
int	my_str_isprintable(char *str);
int	my_showstr(char *str);
int	my_showmem(char *str, int size);
char	*my_strcat(char *dest, char *src);
char	*my_strncat(char *dest, char *src, int nb);
int	my_char_isnum(char c);
int	my_char_isalpha(char c);
int	my_show_wordtab(char **tab);
char	**my_str_to_wordtab(char *str);

#endif

