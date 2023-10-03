/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:34:56 by nsutter           #+#    #+#             */
/*   Updated: 2023/09/30 22:50:29 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_single_quote(char *read_line)
{
	(void)read_line;
	return (0);
}

int	check_double_quote(char *read_line)
{
	(void)read_line;
	return (0);
}

int	check_unclose_quotes(char *read_line)
{
	int	quote;
	int	i;

	quote = 0;
	i = 0;
	while (read_line[i])
	{
		if (read_line[i] == '"')
		{
			if (quote == 0)
				quote = 1;
			else if (quote == 1)
				quote = 0;
		}
		if (read_line[i] == '\'')
		{
			if (quote == 0)
				quote = 2;
			else if (quote == 2)
				quote = 0;
		}
		i++;
	}
	return (quote);
}

int	lexer_minishell(t_data *data)
{
	if (check_unclose_quotes(data->read_line) != 0)
		return (ERROR_UNCLOSED_QUOTES);
	if (check_single_quote(data->read_line) != 0)
		printf("error and exit\n");
	if (check_double_quote(data->read_line) != 0)
		printf("error and exit\n");
	return (0);
}
