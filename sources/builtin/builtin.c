#include "../includes/minishell.h"

void	builtin_execv(t_data *data, char **cmd)
{
	if (ft_strncmp(cmd[0], "echo", 4) == 0)
		builtin_echo(cmd);
	if (ft_strncmp(cmd[0], "cd", 2) == 0)
		builtin_cd(data);
	if (ft_strncmp(cmd[0], "pwd", 3) == 0)
		builtin_pwd(cmd);
	if (ft_strncmp(cmd[0], "export", 6) == 0)
		builtin_export(cmd);
	if (ft_strncmp(cmd[0], "unset", 5) == 0)
		builtin_unset(cmd);
	if (ft_strncmp(cmd[0], "env", 3) == 0)
		builtin_env(data);
	if (ft_strncmp(cmd[0], "exit", 4) == 0)
		builtin_exit(cmd);
}

bool	builtin_check(char **cmd)
{
	if (!cmd)
		return (false);
	if (ft_strncmp(cmd[0], "echo", 4) == 0
		|| ft_strncmp(cmd[0], "cd", 2) == 0
		|| ft_strncmp(cmd[0], "pwd", 3) == 0
		|| ft_strncmp(cmd[0], "export", 6) == 0
		|| ft_strncmp(cmd[0], "unset", 5) == 0
		|| ft_strncmp(cmd[0], "env", 3) == 0
		|| ft_strncmp(cmd[0], "exit", 4) == 0)
		return (true);
	return (false);
}
