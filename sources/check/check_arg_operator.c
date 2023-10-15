/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_operator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 21:47:02 by nsutter           #+#    #+#             */
/*   Updated: 2023/10/14 21:04:23 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_arg_operator_is_redirect(t_data *data, char *read, int index)
{
	if (read[index] == read[index + 1])
	{
		if (read[index] == '>')
			go_to_token_lst(data, read, index, TOKEN_REDIR_OUTPUT_D);
		else
			go_to_token_lst(data, read, index, TOKEN_HEREDOC);
		return (1);
	}
	else
	{
		if (read[index] == '>')
			go_to_token_lst(data, read, index, TOKEN_REDIR_OUTPUT);
		else
			go_to_token_lst(data, read, index, TOKEN_REDIR_INPUT);
	}
	return (0);
}

int	check_arg_operator(t_data *data, int index)
{
	char	*read;

	read = data->read_line;
	if (check_arg_read_is_space(read[index]) == 0 && index == 0)
		go_to_token_lst(data, read, index, TOKEN_SPACE);
	if (!check_arg_read_is_space(read[index])
		&& check_arg_read_is_space(read[index - 1]))
		go_to_token_lst(data, read, index, TOKEN_SPACE);
	if (read[index] == '|')
		go_to_token_lst(data, read, index, TOKEN_PIPE);
	if (read[index] == '<' || read[index] == '>')
		return (check_arg_operator_is_redirect(data, read, index));
	return (0);
}
