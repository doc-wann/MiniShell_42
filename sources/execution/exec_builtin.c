/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaniele <hdaniele@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 19:22:58 by nsutter           #+#    #+#             */
/*   Updated: 2023/10/13 16:20:35 by hdaniele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exec_builtin(t_data *data, char **cmd)
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
		builtin_exit(cmd);
}