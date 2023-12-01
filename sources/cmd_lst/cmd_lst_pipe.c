/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lst_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:49:28 by nsutter           #+#    #+#             */
/*   Updated: 2023/10/15 14:55:20 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	cmd_lst_pipe_create(t_data *data)
{
	int		index;
	int		*fd_pipe;

	cmd_lst_find(data->cmd_lst, 0)->fd_in = 0;
	cmd_lst_find(data->cmd_lst, data->nb_exec - 1)->fd_out = 1;
	index = 0;
	while (index < (data->nb_exec - 1))
	{
		fd_pipe = malloc(sizeof(int) * 2);
		if (!fd_pipe)
			exit_minishell(data, 0);
		if (pipe(fd_pipe) < 0)
			error_pipe(data);
		cmd_lst_find(data->cmd_lst, index)->fd_out = fd_pipe[1];
		index++;
		cmd_lst_find(data->cmd_lst, index)->fd_in = fd_pipe[0];
	}
}

int	cmd_lst_pipe_nb(t_data *data)
{
	t_token_lst		*token_lst;
	int				i;

	token_lst = data->token_lst;
	i = 0;
	while (token_lst)
	{
		if (token_lst->token == TOKEN_PIPE)
			i++;
		token_lst = token_lst->next;
	}
	i++;
	return (i);
}
