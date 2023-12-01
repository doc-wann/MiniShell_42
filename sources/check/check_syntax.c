/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 21:43:40 by nsutter           #+#    #+#             */
/*   Updated: 2023/10/15 20:38:28 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_syntax_is_redirect(t_token_lst *token_lst)
{
	if (token_lst->token == TOKEN_REDIR_INPUT)
		return (1);
	if (token_lst->token == TOKEN_REDIR_OUTPUT)
		return (1);
	if (token_lst->token == TOKEN_REDIR_OUTPUT_D)
		return (1);
	return (0);
}

int	check_syntax_start(t_token_lst *token_lst)
{
	int	error;

	if (token_lst == NULL)
		return (0);
	if (token_lst->token == TOKEN_PIPE)
		return (ERROR_PIPE);
	if (token_lst->token == TOKEN_SPACE && token_lst->next->token == TOKEN_PIPE)
		return (ERROR_PIPE);
	error = 0;
	while (token_lst)
	{
		if (token_lst->token != TOKEN_SPACE)
			error = 1;
		token_lst = token_lst->next;
	}
	if (error == 0)
		return (ERROR_START);
	return (0);
}

int	check_syntax(t_data *data)
{
	t_token_lst	*token_lst;

	token_lst = data->token_lst;
	data->error = check_syntax_start(token_lst);
	if (data->error != 0)
		return (data->error);
	while (token_lst)
	{
		if (token_lst->token == TOKEN_PIPE)
			data->error = check_syntax_pipe_error(token_lst->next);
		if (check_syntax_is_redirect(token_lst))
			data->error = check_syntax_redirect_error(token_lst->next);
		if (token_lst->token == TOKEN_HEREDOC)
			data->error = check_syntax_heredoc_error(token_lst->next);
		if (data->error != 0)
			return (data->error);
		token_lst = token_lst->next;
	}
	return (0);
}
