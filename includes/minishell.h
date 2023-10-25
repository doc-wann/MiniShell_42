/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaniele <hdaniele@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:38:08 by nsutter           #+#    #+#             */
/*   Updated: 2023/10/25 17:38:52 by hdaniele         ###   ########.fr       */
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

/* token */
# define TOKEN_CMD 1
# define TOKEN_PIPE 2
# define TOKEN_REDIR_INPUT 3
# define TOKEN_REDIR_OUTPUT 4
# define TOKEN_REDIR_OUTPUT_D 5
# define TOKEN_HEREDOC 6
# define TOKEN_SPACE 7

/* error init */
# define ERROR_ISATTY 1
# define ERROR_NB_ARGUMENT 2

/* error token */
# define ERROR_UNCLOSED_QUOTES 3
# define ERROR_PIPE 4
# define ERROR_REDIR_INPUT 5
# define ERROR_REDIR_OUTPUT 6
# define ERROR_REDIR_OUTPUT_D 7
# define ERROR_HEREDOC 8
# define ERROR_NO_LINE 9
# define ERROR_START 10

/* error other */
# define ERROR_FORK 11
# define ERROR_CMD_NOT_FOUND 12

typedef struct s_token_lst
{
	int						token;
	char					*value;
	struct s_token_lst		*next;
	
	struct s_token_lst		*last;
	
}	t_token_lst;

typedef struct s_cmd_lst
{
	char					**cmd;
	int						index;
	pid_t					pid;
	int						fd_in;
	int						fd_out;
	struct s_cmd_lst		*next;
}	t_cmd_lst;

typedef struct s_data
{
	char			**env;
	char			*read_line;
	t_token_lst		*token_lst;
	int				token_lst_nb;
	t_cmd_lst		*cmd_lst;
	int				nb_exec;
	int				error;
	int				exit;
}	t_data;

/* main */
void		loop_minishell(t_data *data);
int			check_minishell(t_data *data);

/* init */
void		init_minishell(t_data *data, int argc, char **envp);
void		init_data(t_data *data);
void		init_read_line(t_data *data);
bool		init_env(t_data *data, char **envp);

/* check -> arg */
int			check_arg(t_data *data);
int			check_arg_unclose_quotes(char *read_line);
int			check_arg_cmd(t_data *data, int index);
int			check_arg_cmd_size(char *read, int index);
int			check_arg_operator_is_redirect(t_data *data, char *read, int index);
int			check_arg_operator(t_data *data, int index);
int			check_arg_read_is_space(char read);
int			check_arg_read_is_meta(char read);

/* check -> syntax */
int			check_syntax(t_data *data);
int			check_syntax_start(t_token_lst *token_lst);
int			check_syntax_is_redirect(t_token_lst *token_lst);
int			check_syntax_is_token(int token);
int			check_syntax_pipe_error(t_token_lst *token_lst);
int			check_syntax_heredoc_error(t_token_lst *token_lst);
int			check_syntax_redirect_error(t_token_lst *token_lst);

/* check -> token_lst */
int			check_to_token_lst(t_data *data);
int			check_token_redir(t_data *data, t_token_lst *token_lst, int token);
int			check_redirect_to_token_lst(t_data *data, t_token_lst *token_lst);
int			check_to_token_lst(t_data *data);
t_token_lst	*token_lst_new(char *value, int token);
void		token_lst_add_back(t_token_lst **token_lst, t_token_lst *token);
void		go_to_token_lst(t_data *data, char *value, int index, int token);

/* cmd_fill */
void		cmd_quotes(t_data *data, t_token_lst *token_lst);
void		cmd_expand(t_data *data, t_token_lst *token_lst);

/* cmd_lst */
int			cmd_lst(t_data *data);
int			cmd_lst_pipe_nb(t_data *data);
void		cmd_lst_pipe_create(t_data *data);
int			cmd_lst_update(t_data *data);
void		cmd_lst_update_cmd(t_data *data, t_token_lst *token_lst, int index);
void		cmd_lst_add_back(t_cmd_lst **cmd_lst, t_cmd_lst *cmd);
t_cmd_lst	*cmd_lst_create(t_data *data);
t_cmd_lst	*cmd_lst_new(t_data *data);
t_cmd_lst	*cmd_lst_find(t_cmd_lst *cmd_lst, int index);

/* execution */
void		exec_minishell(t_data *data);
char		*exec_path(char *cmd, char **envp);
void		exec_fd_close(t_data *data, int index);
void		exec_fd_redirect(t_data *data, t_cmd_lst *cmd_lst);
void		exec_fd_waitpid(t_data *data);

/* builtin */
int			builtin_cd(char **cmd, t_data *data);
int			builtin_echo(char **args, t_data *data);
int			builtin_env(t_data *data);							// OK
int			builtin_exit(char **cmd);
int			builtin_export(char **cmd, t_data *data);
int			builtin_pwd(char **cmd);							// OK
int			builtin_unset(char **cmd, t_data *data);
int			builtin_len(char **cmd);
void		builtin_exec(t_data *data, char **cmd);
bool		builtin_check(char **cmd);
char		*get_env(char **envs, char *search);
char		**ft_varfetch(char **args, t_data *data);

/* signal */
void		signal_handler(void);
void		signal_handler_sigint(int signum);
void		signal_handler_sigquit(int signum);

/* redirection */
int			write_file(int fd, char *filename);
int			write_file_append(int fd, char *filename);
int			control_stdout(t_data *data, int flag);

/* error */
void		error_init(t_data *data, int error);
int			error_msg_cmd(t_data *data, char *cmd, int error);
int			error_builtin_cd_no_dir(char *cmd);
int			error_builtin_cd_too_many_arg(void);
int			error_builtin_pwd(void);
int			error_exec_cmd_not_found(char *cmd);
void		error_msg_check(t_data *data);
void		error_pipe(t_data *data);

/* exit */
void		exit_minishell(t_data *data);

#endif