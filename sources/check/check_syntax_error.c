/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:24:25 by nsutter           #+#    #+#             */
/*   Updated: 2023/10/15 22:02:30 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_syntax_is_token(int token)
{
	if (token == TOKEN_PIPE)
		return (ERROR_PIPE);
	if (token == TOKEN_HEREDOC)
		return (ERROR_HEREDOC);
	if (token == TOKEN_REDIR_INPUT)
		return (ERROR_REDIR_INPUT);
	if (token == TOKEN_REDIR_OUTPUT)
		return (ERROR_REDIR_OUTPUT);
	if (token == TOKEN_REDIR_OUTPUT_D)
		return (ERROR_REDIR_OUTPUT_D);
	return (0);
}

int	check_syntax_pipe_error(t_token_lst *token_lst)
{
	if (!token_lst)
		return (ERROR_PIPE);
	if (token_lst->token == TOKEN_PIPE)
		return (ERROR_PIPE);
	if (!token_lst->next && token_lst->token != TOKEN_CMD)
		return (ERROR_PIPE);
	return (0);
}

int	check_syntax_heredoc_error(t_token_lst *token_lst)
{
	if (!token_lst)
		return (ERROR_NO_LINE);
	if (token_lst->token == TOKEN_SPACE)
	{
		if (!token_lst->next)
			return (ERROR_NO_LINE);
		if (token_lst->next->token == TOKEN_PIPE)
			return (ERROR_PIPE);
		if (token_lst->next->token == TOKEN_HEREDOC)
			return (ERROR_HEREDOC);
	}
	if (token_lst->token != TOKEN_SPACE)
	{
		if (token_lst->token != TOKEN_CMD)
			return (ERROR_HEREDOC);
	}
	return (0);
}

int	check_syntax_redirect_error(t_token_lst *token_lst)
{
	if (!token_lst)
		return (ERROR_NO_LINE);
	if (token_lst->token == TOKEN_SPACE)
	{
		if (!token_lst->next)
			return (ERROR_NO_LINE);
		if (check_syntax_is_token(token_lst->next->token) != 0)
			return (check_syntax_is_token(token_lst->next->token));
	}
	else
	{
		if (check_syntax_is_token(token_lst->next->token) != 0)
			return (check_syntax_is_token(token_lst->next->token));
	}
	return (0);
}
