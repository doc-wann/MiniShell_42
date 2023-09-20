#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>



typedef struct s_cmd_execv
{
	char			**cmd;
}	t_cmd_execv;

typedef struct s_data
{
	char			**env;
	char			*read_line;
	t_cmd_execv		*cmd_lst;
	int				exit;
}	t_data;


/* init */
void	minishell_init(t_data *data, int argc, char **envp);

/* loop */
void	minishell_loop(t_data *data);

/* cmd */
void	cmd_execv(t_data *data);
bool	cmd_create_list(t_data *data);

/* builtin */
void	builtin_cd(char **cmd);
void	builtin_echo(char **cmd);
void	builtin_env(t_data *data);
void	builtin_exit(char **cmd);
void	builtin_export(char **cmd);
void	builtin_pwd(char **cmd);
void	builtin_unset(char **cmd);
void	builtin_execv(t_data *data, char **cmd);
bool	builtin_check(char **cmd);

/* exit */


/* error */
void	error_msg(char	*msg);

#endif