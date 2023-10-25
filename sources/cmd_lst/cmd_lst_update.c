/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lst_update.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaniele <hdaniele@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:33:21 by nsutter           #+#    #+#             */
/*   Updated: 2023/10/24 15:56:59 by hdaniele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

#include <fcntl.h>

int	cmd_lst_token_is_redirect(int token)
{
	if (token == TOKEN_REDIR_INPUT)
		return (1);
	if (token == TOKEN_REDIR_OUTPUT)
		return (1);
	if (token == TOKEN_REDIR_OUTPUT_D)
		return (1);
	return (0);
}

void	cmd_lst_update_heredoc(t_data *data, t_token_lst *token_lst, int index)
{
	(void)data;
	(void)token_lst;
	(void)index;
}

void	cmd_lst_update_redir(t_data *data, t_token_lst *token_lst, int index)
{
	(void) index;
	(void) token_lst;
	(void) data;
	// char		**cmd_lst;
	// char		**cmd_lst_new;
	// int			i;

	// cmd_lst = cmd_lst_find(data->cmd_lst, index)->cmd;
	// i = 0;
	// while (cmd_lst[i])
	// 	i++;
	// cmd_lst_new = malloc(sizeof(char *) * (i + 2));
	// i = 0;
	// while (cmd_lst[i])
	// {
	// 	cmd_lst_new[i] = cmd_lst[i];
	// 	i++;
	// }
	// cmd_lst_new[i] = token_lst->value;
	// i++;
	// cmd_lst_new[i] = NULL;
	// cmd_lst_find(data->cmd_lst, index)->cmd = cmd_lst_new;
}

void	cmd_lst_update_cmd(t_data *data, t_token_lst *token_lst, int index)
{
	char		**cmd_lst;
	char		**cmd_lst_new;
	int			i;

	cmd_lst = cmd_lst_find(data->cmd_lst, index)->cmd;
	i = 0;
	while (cmd_lst[i])
		i++;
	cmd_lst_new = malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (cmd_lst[i])
	{
		cmd_lst_new[i] = cmd_lst[i];
		i++;
	}
	cmd_lst_new[i] = token_lst->value;
	i++;
	cmd_lst_new[i] = NULL;
	cmd_lst_find(data->cmd_lst, index)->cmd = cmd_lst_new;
}

// Filling the command list with the arguments originally passed

int	cmd_lst_update(t_data *data)
{
	t_token_lst		*token_lst;
	int				index;

	token_lst = data->token_lst;
	index = 0;
	while (token_lst)
	{
		if (token_lst->token == TOKEN_PIPE)
			index++;
		else if (token_lst->token == TOKEN_HEREDOC)
			cmd_lst_update_heredoc(data, token_lst, index);
		else if (token_lst->token == TOKEN_CMD)
			cmd_lst_update_cmd(data, token_lst, index);
		else if (cmd_lst_token_is_redirect(token_lst->token))
			cmd_lst_update_redir(data, token_lst, index);

		token_lst = token_lst->next;
	}
	return (0);
}
