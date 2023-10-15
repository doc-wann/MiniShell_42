/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 21:44:11 by nsutter           #+#    #+#             */
/*   Updated: 2023/10/15 00:34:24 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exec_fd_waitpid(t_data *data)
{
	t_cmd_lst	*cmd_lst;
	int			status;

	cmd_lst = data->cmd_lst;
	status = 1;
	while (cmd_lst)
	{
		waitpid(cmd_lst->pid, &status, 0);
		cmd_lst = cmd_lst->next;
	}
}

void	exec_fd_redirect(t_data *data, t_cmd_lst *cmd_lst)
{
	if (cmd_lst->fd_in != STDIN_FILENO)
	{
		if (dup2(cmd_lst->fd_in, STDIN_FILENO) < 0)
			error_pipe(data);
		if (close(cmd_lst->fd_in) < 0)
			exit_minishell(data);
		cmd_lst->fd_in = -1;
	}
	if (cmd_lst->fd_out != STDOUT_FILENO)
	{
		if (dup2(cmd_lst->fd_out, STDOUT_FILENO) < 0)
			error_pipe(data);
		if (close(cmd_lst->fd_out) < 0)
			exit_minishell(data);
		cmd_lst->fd_out = -1;
	}
}

void	exec_fd_close(t_data *data, int index)
{
	t_cmd_lst	*cmd_lst;

	cmd_lst = data->cmd_lst;
	while (cmd_lst)
	{
		if (cmd_lst->index != index)
		{
			if (cmd_lst->fd_in != STDIN_FILENO && cmd_lst->fd_in >= 0)
			{
				if (close(cmd_lst->fd_in) < 0)
					exit_minishell(data);
				cmd_lst->fd_in = -1;
			}
			if (cmd_lst->fd_out != STDOUT_FILENO && cmd_lst->fd_out >= 0)
			{
				if (close(cmd_lst->fd_out) < 0)
					exit_minishell(data);
				cmd_lst->fd_out = -1;
			}
		}
		cmd_lst = cmd_lst->next;
	}
}
