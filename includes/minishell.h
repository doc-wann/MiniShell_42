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



typedef struct s_cmd_lst
{
	char					*cmd;
	char					*parser;
	int						index;
	struct	s_cmd_lst		*next;
}	t_cmd_lst;

typedef struct s_data
{
	char			**env;
	char			*read_line;
	t_cmd_lst		*cmd_lst;
	int				nb_execv;
	int				exit;
}	t_data;


/* init */
void	minishell_init(t_data *data, int argc, char **envp);

/* loop */
void	minishell_loop(t_data *data);

/* cmd */
void	cmd_execv(t_data *data);

/* cmd_list */
void	cmd_lst_create(t_data *data);

/* builtin */
void	builtin_cd(t_data *data);
void	builtin_echo(char **cmd);
void	builtin_env(t_data *data);
void	builtin_exit(char **cmd);
void	builtin_export(char **cmd);
void	builtin_pwd(char **cmd);
void	builtin_unset(char **cmd);
void	builtin_execv(t_data *data, char **cmd);
bool	builtin_check(char **cmd);

/* enviroment aux's (located at cd builtin until somewhere better is found)*/
char 	*get_env(char **envs, char *search);
char	*path_parser(char *path);

/* signal */
void sig_handler(int signum);


/* exit */


/* error */
void	error_msg(char	*msg);

#endif