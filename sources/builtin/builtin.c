#include "../includes/minishell.h"

void	builtin_execv(t_data *data, char **cmd)
{
	if (ft_strcmp(cmd[0], "echo") == 0)
		builtin_echo(cmd);
	if (ft_strcmp(cmd[0], "cd") == 0)
		builtin_cd(cmd);
	if (ft_strcmp(cmd[0], "pwd") == 0)
		builtin_pwd(cmd);
	if (ft_strcmp(cmd[0], "export") == 0)
		builtin_export(cmd);
	if (ft_strcmp(cmd[0], "unset") == 0)
		builtin_unset(cmd);
	if (ft_strcmp(cmd[0], "env") == 0)
		builtin_env(data);
	if (ft_strcmp(cmd[0], "exit") == 0)
		builtin_exit(cmd);
}

bool	builtin_check(char **cmd)
{
	if (!cmd)
		return (false);
	if (ft_strcmp(cmd[0], "echo") == 0
		|| ft_strcmp(cmd[0], "cd") == 0
		|| ft_strcmp(cmd[0], "pwd") == 0
		|| ft_strcmp(cmd[0], "export") == 0
		|| ft_strcmp(cmd[0], "unset") == 0
		|| ft_strcmp(cmd[0], "env") == 0
		|| ft_strcmp(cmd[0], "exit") == 0)
		return (true);
	return (false);
}
