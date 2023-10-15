/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:34:56 by nsutter           #+#    #+#             */
/*   Updated: 2023/10/15 22:05:44 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_arg_unclose_quotes(char *read_line)
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

int	check_arg(t_data *data)
{
	size_t	index;

	if (check_arg_unclose_quotes(data->read_line) != 0)
		return (ERROR_UNCLOSED_QUOTES);
	index = 0;
	while (index < ft_strlen(data->read_line))
	{
		index = index + check_arg_cmd(data, index);
		index = index + check_arg_operator(data, index);
		index++;
	}
	return (0);
}
