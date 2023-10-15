/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_quotes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:26:20 by nsutter           #+#    #+#             */
/*   Updated: 2023/10/15 23:27:34 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	cmd_quotes(t_data *data, t_token_lst *token_lst)
{
	int	quote_simple;
	int	quote_double;
	int	i;

	(void)data;
	quote_simple = 0;
	quote_double = 0;
	i = 0;
	while (token_lst->value[i])
	{
		if (token_lst->value[i] == '\'')
		{
		}
		if (token_lst->value[i] == '"')
		{
		}
		if (quote_simple == 1)
		{
		}
		if (quote_double == 1)
		{
		}
		i++;
	}
}
