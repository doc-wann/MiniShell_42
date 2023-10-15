/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 21:44:06 by nsutter           #+#    #+#             */
/*   Updated: 2023/10/15 14:35:35 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exec_cmd_simple(t_data *data, t_cmd_lst *cmd_lst)
{
	char	*path;

	if (cmd_lst->cmd == NULL)
		exit_minishell(data);
	if (builtin_check(cmd_lst->cmd))
	{
		builtin_exec(data, cmd_lst->cmd);
		exit_minishell(data);
	}
	path = exec_path(cmd_lst->cmd[0], data->env);
	if (path != NULL)
		execve(path, cmd_lst->cmd, data->env);
	else
		error_exec_cmd_not_found(cmd_lst->cmd[0]);
}

void	exec_cmd_multi(t_data *data)
{
	t_cmd_lst	*cmd_lst;
	int			index;
	pid_t		pid;

	cmd_lst = data->cmd_lst;
	index = 0;
	while (cmd_lst)
	{
		pid = fork();
		if (pid < 0)
			error_pipe(data);
		if (pid == 0)
		{
			exec_fd_close(data, index);
			exec_fd_redirect(data, cmd_lst);
			exec_cmd_simple(data, cmd_lst);
		}
		else
			cmd_lst->pid = pid;
		cmd_lst = cmd_lst->next;
		index++;
	}
	exec_fd_close(data, -1);
	exec_fd_waitpid(data);
}

void	exec_cmd_alone(t_data *data)
{
	t_cmd_lst	*cmd_lst;

	cmd_lst = data->cmd_lst;
	if (cmd_lst->cmd == NULL || cmd_lst->cmd[0] == NULL)
		return ;
	if (builtin_check(cmd_lst->cmd))
		builtin_exec(data, cmd_lst->cmd);
	else
		exec_cmd_multi(data);
}

void	exec_minishell(t_data *data)
{
	if (data->nb_exec > 1)
		exec_cmd_multi(data);
	else
		exec_cmd_alone(data);
}
