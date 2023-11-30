/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:36:18 by nsutter           #+#    #+#             */
/*   Updated: 2023/10/15 15:32:48 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	builtin_len(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
		i++;
	return (i);
}

void	builtin_exec(t_data *data, char **cmd)
{
	if (ft_strcmp(cmd[0], "echo") == 0)
		builtin_echo(cmd, data);
	if (ft_strcmp(cmd[0], "cd") == 0)
		builtin_cd(cmd, data);
	if (ft_strcmp(cmd[0], "pwd") == 0)
		builtin_pwd(cmd);
	if (ft_strcmp(cmd[0], "export") == 0)
		builtin_export(cmd, data);
	if (ft_strcmp(cmd[0], "unset") == 0)
		builtin_unset(cmd, data);
	if (ft_strcmp(cmd[0], "env") == 0)
		builtin_env(data);
	if (ft_strcmp(cmd[0], "exit") == 0)
		builtin_exit(cmd, data);
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
