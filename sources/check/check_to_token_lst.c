/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_to_token_lst.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 21:18:18 by nsutter           #+#    #+#             */
/*   Updated: 2023/10/15 22:02:45 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_token_redir(t_data *data, t_token_lst *token_lst, int token)
{
	if (token == TOKEN_REDIR_INPUT)
		go_to_token_lst(data, token_lst->value, 0, TOKEN_REDIR_INPUT);
	if (token == TOKEN_REDIR_OUTPUT)
		go_to_token_lst(data, token_lst->value, 0, TOKEN_REDIR_OUTPUT);
	if (token == TOKEN_REDIR_OUTPUT_D)
		go_to_token_lst(data, token_lst->value, 0, TOKEN_REDIR_OUTPUT_D);
	if (token == TOKEN_HEREDOC)
		go_to_token_lst(data, token_lst->value, 0, TOKEN_HEREDOC);
	return (0);
}

int	check_redirect_to_token_lst(t_data *data, t_token_lst *token_lst)
{
	if (token_lst->next->token == TOKEN_SPACE)
	{
		check_token_redir(data, token_lst->next->next, token_lst->token);
		token_lst = token_lst->next->next;
	}
	else if (token_lst->next->token != TOKEN_SPACE)
	{
		check_token_redir(data, token_lst->next, token_lst->token);
		token_lst = token_lst->next;
	}
	return (0);
}

int	check_to_token_lst(t_data *data)
{
	t_token_lst		*token_lst;

	data->token_lst_nb = 2;
	token_lst = data->token_lst;
	data->token_lst = NULL;
	while (token_lst)
	{
		if (token_lst->token != TOKEN_CMD && !token_lst->next)
			return (0);
		if (token_lst->token == TOKEN_SPACE)
			token_lst = token_lst->next;
		if (check_syntax_is_redirect(token_lst)
			|| token_lst->token == TOKEN_HEREDOC)
			check_redirect_to_token_lst(data, token_lst);
		if (token_lst->token == TOKEN_PIPE)
			go_to_token_lst(data, token_lst->value, 0, TOKEN_PIPE);
		if (token_lst->token == TOKEN_CMD)
			go_to_token_lst(data, token_lst->value, 0, TOKEN_CMD);
		token_lst = token_lst->next;
	}
	return (0);
}
