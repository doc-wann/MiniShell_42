/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:35:58 by nsutter           #+#    #+#             */
/*   Updated: 2023/11/29 21:58:04 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int builtin_exit_check_number(char *cmd)
{
	int	i;

	if (!cmd)
		return (0);
	i = 0;
	while ((cmd[i] >= 9 && cmd[i] <= 13) || cmd[i] == 32)
		i++;
	if (cmd[i] == '-' || cmd[i] == '+')
		i++;
	while (cmd[i])
	{
		if (!ft_isdigit(cmd[i]))
			return (0);
		i++;
	}
	return (1);
}

int	builtin_exit_len(char **cmd)
{
	int	len;

	if (!cmd)
		return (0);
	len = 0;
	while (cmd[len] != 0)
		len++;
	return (len);
}

int	builtin_exit(char **cmd, t_data *data)
{
	int	status;

	if (builtin_exit_len(cmd) == 1)
		exit_minishell(data, 0);
	if (builtin_exit_len(cmd) == 2)
	{
		if (!builtin_exit_check_number(cmd[1]))
			status = error_builtin_exit_numeric_arg(data, cmd[1]);
		else
			status = ft_atoi(cmd[1]);
		exit_minishell(data, status);
	}
	else
	{
		if (!builtin_exit_check_number(cmd[1]))
			status = error_builtin_exit_numeric_arg(data, cmd[1]);
		else
			status = error_builtin_exit_too_many_arg(data);
		exit_minishell(data, status);
			
	}
	exit_minishell(data ,1);
	return (1);
}
