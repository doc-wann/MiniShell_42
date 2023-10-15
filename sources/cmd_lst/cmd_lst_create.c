/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lst_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:36:29 by nsutter           #+#    #+#             */
/*   Updated: 2023/10/15 23:16:04 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_cmd_lst	*cmd_lst_find(t_cmd_lst *cmd_lst, int index)
{
	if (!cmd_lst)
		return (NULL);
	while (cmd_lst)
	{
		if (cmd_lst->index == index)
			return (cmd_lst);
		cmd_lst = cmd_lst->next;
	}
	return (NULL);
}

void	cmd_lst_add_back(t_cmd_lst **cmd_lst, t_cmd_lst *cmd)
{
	t_cmd_lst	*back;

	if (*cmd_lst == NULL)
	{
		*cmd_lst = cmd;
		return ;
	}
	back = *cmd_lst;
	while (back->next)
		back = back->next;
	back->next = cmd;
}

t_cmd_lst	*cmd_lst_new(t_data *data)
{
	t_cmd_lst	*new;

	new = malloc(sizeof(t_cmd_lst));
	if (!new)
		exit_minishell(data);
	new->cmd = malloc(sizeof(char *));
	if (!new->cmd)
		exit_minishell(data);
	new->cmd[0] = NULL;
	new->index = -1;
	new->pid = -1;
	new->fd_in = -1;
	new->fd_out = -1;
	new->next = NULL;
	return (new);
}

// Create the command list to execute
// Depends on the "nb_exec" variable which counts the number of commands

t_cmd_lst	*cmd_lst_create(t_data *data)
{
	t_cmd_lst	*cmd_lst;
	t_cmd_lst	*new;
	int			i;

	cmd_lst = NULL;
	new = NULL;
	i = 0;
	while (i < (data->nb_exec))
	{
		new = cmd_lst_new(data);
		new->index = i;
		cmd_lst_add_back(&cmd_lst, new);
		i++;
	}
	return (cmd_lst);
}

int	cmd_lst(t_data *data)
{
	data->nb_exec = cmd_lst_pipe_nb(data);
	data->cmd_lst = cmd_lst_create(data);
/*	printf("cmd_lst_create\n");
	t_cmd_lst 	*cmd_lst;
	cmd_lst = data->cmd_lst;
	while (cmd_lst)
	{
		printf("index      : %d\n", cmd_lst->index);
		printf("fd_in      : %d\n", cmd_lst->fd_in);
		printf("fd_out     : %d\n", cmd_lst->fd_out);
		cmd_lst = cmd_lst->next;
	}*/
	cmd_lst_pipe_create(data);
/*	printf("cmd_lst_create_pipe\n");
	cmd_lst = data->cmd_lst;
	while (cmd_lst)
	{
		printf("index      : %d\n", cmd_lst->index);
		printf("fd_in      : %d\n", cmd_lst->fd_in);
		printf("fd_out     : %d\n", cmd_lst->fd_out);
		cmd_lst = cmd_lst->next;
		i++;
	}*/
	cmd_lst_update(data);
	return (0);
}
