/*
** minishell.h for  in /home/crespi_c/rendu/Elementary_C/PSU_2015_minishell1
** 
** Made by Celenzo CRESPIN
** Login   <crespi_c@epitech.net>
** 
** Started on  Fri Jan 15 21:18:47 2016 Celenzo CRESPIN
** Last update Sun Jun  5 20:30:11 2016 Romain Hedouin
*/

#ifndef __MINISHELL_H
#define __MINISHELL_H

#include <fcntl.h>
#include <stdio.h>
#include <dirent.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/resource.h>
#include "history.h"
#include "globing.h"
#include "var_env.h"
#include "my_printf.h"
#include "sig_errors.h"
#include "get_next_line.h"

#define NF(f, s) (my_printf(f, s))

#define READ		0
#define WRITE		1
#define MAX_PATH_SIZE	512
#define AND_OPERATOR	48
#define OR_OPERATOR	49

#define PS2		"> "
#define CD_CMD		"cd"
#define PWD_CMD		"pwd"
#define ENV_CMD		"env"
#define PWD_VAR		"PWD"
#define SEP_CHAR	'='
#define ECHO_CMD	"echo"
#define ALIAS_LABEL	"alias:"
#define HOST_VAR	"HOST"
#define USER_VAR	"USER"
#define EXIT_CMD	"exit"
#define HIST_CMD	"history"
#define HOME_VAR	"HOME"
#define PATH_VAR	"PATH"
#define ROOT_PRIV	"root"
#define RC_FILE		".42shrc"
#define OSEF		"SAMPLETEXT"
#define EMERG_PATH	"PATH=/bin:/usr/bin"
#define OLDPWD_VAR	"OLDPWD"
#define SETENV_CMD	"setenv"
#define UNSETENV_CMD	"unsetenv"
#define PROMPT		"(%s@%s %d) %c> "
#define PLS		"Segmentation fault\n"
#define READ_ERROR	"An error as occured\n"
#define CMD_NF		"%s: Command not found.\n"
#define CANT_EXEC	"%s: Not an executable\n"
#define RIGHT_ERROR	"%s: Permission denied.\n"
#define DIR_ERROR	"%s: Can't open directory\n"
#define FORM_ERROR	"%s: Exec format error. Binary file not executable.\n"
#define FILE_NOT_FOUND	"%s: No such file or directory.\n"
#define MISS_NAME	"Missing name for redirect.\n"
#define AMBIG		"Ambiguous output redirect.\n"
#define EXIT_ERR	"exit: Expression Syntax.\n"
#define INV_NULL_CMD	"Invalid null command.\n"
#define SYNT_ERROR	"Syntax error in %s line %d\n"
#define UNSTENV_NEARGS	"unsetenv: Too few arguments.\n"
#define CD_USAGE	"Usage: cd [-plvn][-|<dir>]..\n"
#define CD_T_ARG	"cd: Too many arguments.\n"

typedef struct		s_pipe
{
  int			fd[2];
  int			redir[2];
  char			*buf;
  int			is_blt;
  int			back;
  struct s_pipe		*next;
}			t_pipe;

int     cd_error(char **argv);
int	check(char *s1, char *s2);
int     check_built(char *cmd, char **argv, char **ae, t_pipe *pp);
int     check_double_right(char *opn);
int     check_cmd_null(char *str);
int     check_simple_left(char *opn);
int     check_simple_right(char *opn);
int     dat_keeper(int to_stock, int to_ret);
int	deb_cmd(char *buf, char c);
int     do_exit(char **argv);
int     fill_double_left(char *buf);
int	find_built(char *cmd, char **argv, char **ae);
int	free_all(char *flags, ...);
int	get_suite(char *buf, int i, char c);
int	hand_op(char *, char **);
int	inv_null(char *buf);
int	jump_to_next(char *, int);
int	my_arraylen(char **tab);
int	my_cd(char **argv, char **ae);
int	my_echo(char **av);
int	my_env(char **ae);
int	my_exec(t_pipe *pp, char *file, char **argv, char **ae);
int	my_getnbr(char *str);
int	my_printf(char *flag, ...);
int	my_pwd();
int	my_setenv(char **argv, char **ae);
int	my_slen(char *);
int	my_strcmp(char *s1, char *s2);
int	my_strlen(char *s);
int	my_strncmp(char *s1, char *s2, int n);
int	my_unsetenv(char **argv, char **ae);
int	nb_pieces(char *);
int	open_left(char *buf, char c);
int	open_right(char *buf, char c);
int	opn_tmp(char *opn);
int	recurs_pipes(char *buf, char **ae);
int	separators(char *buf, char **ae);
int	set_dups(t_pipe *pp, int fd_in);
int	shell(t_pipe *pp, char **ae);
int     verif_blt(t_pipe *pp, char **ae);
int	verif_dir(t_pipe *pp, char *cmd, char **argv, char **ae);
int     verif_nb(char *s);
int	verif_sym(char *buf, char c);
char	verif_user(char *var);
char	*get_aliases(char *cmd);
char	*getvar(char *var);
char	*gtenv(char **ae, char *fnd);
char	*list_op(char *);
char	*my_getcwd();
char	*my_path_strcat(char *s1, char *s2);
char	*my_strcat(char *s1, char *s2);
char	*my_strdup(char *s);
char	*next_pieces(char *str, int);
char    *open_and_stock(char *opn, int st);
char	*seek_and_destroy(char *buf);
char	*separate(char *buf);
char    *skip_name(char *s);
char    *verif_sd(char *buf, t_pipe *pp, char **ae);
char	**check_stuff(char **buf, char *cmd);
char	**cp_ae(char **temp, char **ae);
char	**parse_ae(char **ae, char *find);
char    **set_urgency_path(char *s);
char	**str_to_wordtab(char *str, char d);
char    **stw2(char *str, char d);
char	**strwt(char *buf, char d);
char	**tab_operator(char *);
void	close_fds(t_pipe *pp);
void    do_exec(t_pipe *pp, char *file, char **argv, char **ae);
void	free_tab(char **tab);
void	history(t_history *my_history);
void    jb_ctrl(t_pipe *pp, int pid);
void	my_show_wordtab(char **tab);
void	print_err(int err);
void    set_back(t_pipe *pp, pid_t pid);
void    sig_hand(int a);
t_pipe	*check_redir(t_pipe *pp);

#endif
