/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:38:08 by nsutter           #+#    #+#             */
/*   Updated: 2023/10/04 00:46:23 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/wait.h>

/* error */
# define ERROR_ISATTY 1
# define ERROR_NB_ARGUMENT 2
# define ERROR_UNCLOSED_QUOTES 3
# define ERROR_FORK 4
# define ERROR_CMD_NOT_FOUND 5

typedef struct s_cmd_lst
{
	char					*cmd;
	char					**process;
	char					*parser;
	int						index;
	pid_t					child;
	int						fd_in;
	int						fd_out;
	struct s_cmd_lst		*next;
}	t_cmd_lst;

typedef struct s_data
{
	char			**env;
	char			*read_line;
	t_cmd_lst		*cmd_lst;
	int				nb_execv;
	int				error;
	int				exit;
}	t_data;

/* main */
void	loop_minishell(t_data *data);
int		check_minishell(t_data *data);

/* init */
void	init_minishell(t_data *data, int argc, char **envp);
void	init_read_line(t_data *data);

/* env */
bool	env_init(t_data *data, char **envp);

/* lexer */
int		lexer_minishell(t_data *data);

/* cmd */
int		cmd_lst_create(t_data *data);
int		cmd_lst(t_data *data);

/* execution */
void	exec_cmd(t_data *data);
void	exec_builtin(t_data *data, char **cmd);
char	*exec_path(char *cmd, char **envp);
void	free_mem(char **path);

/* builtin */
int		builtin_cd(char **cmd, t_data *data);
int		builtin_echo(char **args, t_data *data);
int		builtin_env(t_data *data);
int		builtin_exit(char **cmd);
int		builtin_export(char **cmd, t_data *data);
int		builtin_pwd(char **cmd);
int		builtin_unset(char **cmd, t_data *data);
bool	builtin_check(char **cmd);

/* enviroment aux's (located at cd builtin until somewhere better is found)*/
char	*get_env(char **envs, char *search);
char	*path_parser(char *path);
char	**ft_varfetch(char **args, t_data *data);
int		ft_lstlen(char **s);

/* signal */
void	signal_handler(void);
void	signal_handler_sigint(int signum);
void	signal_handler_sigquit(int signum);

/* redirection */

/* error */
void	error_msg(t_data *data, int error);
int		error_msg_cmd(t_data *data, char *cmd, int error);
int		error_builtin_cd_no_dir(char *cmd);
int		error_builtin_cd_too_many_arg(void);
int		error_exec_cmd_not_found(char *cmd);

/* exit */
void	exit_minishell(t_data *data);
void	free_mem(char **ptr);

#endif