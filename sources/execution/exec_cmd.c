/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaniele <hdaniele@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 21:44:06 by nsutter           #+#    #+#             */
/*   Updated: 2023/10/25 19:40:37 by hdaniele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exec_cmd_multi(t_data *data);

void	exec_cmd_alonex(char **cmd, t_data *data)
{
	int i;

	i = 0;
	while (i < ft_arrlen(cmd))
	{
		if (ft_strcmp(cmd[i], "<") == 0
			|| ft_strcmp(cmd[i], "<<") == 0
			|| ft_strcmp(cmd[i], ">") == 0
			|| ft_strcmp(cmd[i], ">>") == 0)
			break;
		i++;
	}
	
	if (cmd == NULL || cmd[0] == NULL)
	{
		return ;
	}
	else if (builtin_check(cmd))
	{
		builtin_exec(data, cmd);
	}
	else
	{
		exec_cmd_multi(data);
	}
}

char **ft_arrcut(char **list, int start, int end)
{
	char	**arr = malloc(sizeof(char *));
	int i;

	i = 0;
	while(end - i != start)
	{
		arr[i] = list[start + i];
		i++;
	}
	arr[i] = NULL;
	
	return arr;
}

void	exec_redirection(t_data *data, t_cmd_lst *cmd_lst)
{
	(void)data;

	//char **cmd_backup;
	
	int i = 0;
	while (i < ft_arrlen(cmd_lst->cmd))
	{
		if (ft_strcmp(cmd_lst->cmd[i], "<") == 0
			|| ft_strcmp(cmd_lst->cmd[i], "<<") == 0
			|| ft_strcmp(cmd_lst->cmd[i], ">") == 0
			|| ft_strcmp(cmd_lst->cmd[i], ">>") == 0)
			break;

		i++;
	}

	if (cmd_lst->cmd[i][0] == '>' && cmd_lst->cmd[i][1] == '>')
	{
		control_stdout(data, 0);
		exec_cmd_alonex(ft_arrcut(cmd_lst->cmd, 0, i), data);
		control_stdout(data, 1);
		write_file_append(control_stdout(data, 2), cmd_lst->cmd[i + 1]);
	}
	else if (cmd_lst->cmd[i][0] == '>')
	{
		control_stdout(data, 0);
		exec_cmd_alonex(ft_arrcut(cmd_lst->cmd, 0, i), data);
		control_stdout(data, 1);
		write_file(control_stdout(data, 2), cmd_lst->cmd[i + 1]);
	}
	// else if (cmd_lst->cmd[i][0] == '<')
	// {
	// 	control_stdout(data, 0);
	// 	exec_cmd_alonex(ft_arrcut(cmd_lst->cmd, i + 1, (ft_arrlen(cmd_lst->cmd) - i) + 1), data);
	// 	control_stdout(data, 1);
	// 	write_file(control_stdout(data, 2), cmd_lst->cmd[i - 1]);
	// }

	//ft_printf("\n\nThis was executed second!\n\n");
	//for (int show = 0; show < ft_arrlen(cmd_lst->cmd); show++)
	//{
	//	ft_printf("%s\n", cmd_lst->cmd[show]);
	//}

	//exec_cmd_alonex(cmd_lst->cmd, data);
}

bool	redirection_check(char **cmd)
{
	int i = 0;
	
	if (!cmd)
		return (false);
	while (i < ft_arrlen(cmd))
	{
		if (ft_strcmp(cmd[i], "<") == 0
			|| ft_strcmp(cmd[i], "<<") == 0
			|| ft_strcmp(cmd[i], ">") == 0
			|| ft_strcmp(cmd[i], ">>") == 0)
			return (true);

		i++;
	}
	return (false);
}

void	exec_cmd_simple(t_data *data, t_cmd_lst *cmd_lst)
{
	char	*path;

	if (cmd_lst->cmd == NULL)
		exit_minishell(data);
	else if (redirection_check(cmd_lst->cmd))
	{
		exec_redirection(data, cmd_lst);
	}
	else if (builtin_check(cmd_lst->cmd))
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
	
	if (redirection_check(cmd_lst->cmd))
		exec_redirection(data, cmd_lst);
	else if (builtin_check(cmd_lst->cmd))
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
