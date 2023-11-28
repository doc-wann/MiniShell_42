/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_quotes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:26:20 by nsutter           #+#    #+#             */
/*   Updated: 2023/11/28 21:47:50 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	cmd_quotes_remove(t_data *data, char **value, int pos)
{
	char	*new_value;
	int		new_size;
	int		i;
	int		j;

	new_size = ft_strlen(*value);
	new_value = malloc(sizeof(char) * (new_size + 1));
	if (!new_value)
		exit_minishell(data);
	if (pos > new_size)	
		pos = new_size;
	i = 0;
	while (i < pos)
	{
		new_value[i] = (*value)[i];
		i++;
	}
	j = i;
	while ((*value)[j] && ((j - i) < 1))
		j++;
	while ((*value)[j])
		new_value[i++] = (*value)[j++];
	new_value[i]='\0';
	*value = new_value;
}

int		cmd_quotes_close_simple(t_data *data, char **value, int *i)
{
	cmd_quotes_remove(data, value, *i);
	(*i)--;
	return (1);
}

int		cmd_quotes_close_double(t_data *data, char **value, int *i)
{
	cmd_quotes_remove(data, value, *i);
	(*i)--;
	return (1);
}

int		cmd_quotes_open_simple(t_data *data, char **value, int *i)
{
	if ((*value)[*i] == '\'')
	{
		cmd_quotes_remove(data, value, *i);
		(*i)--;
		return (0);
	}
	return (1);
}

int		cmd_quotes_open_double(t_data *data, char **value, int *i)
{
	if ((*value)[*i] == '"')
	{
		cmd_quotes_remove(data, value, *i);
		(*i)--;
		return (0);
	}
	return (1);
}

void	cmd_quotes(t_data *data, t_token_lst *token_lst)
{
	int	quote_simple;
	int	quote_double;
	int	i;

	quote_simple = 0;
	quote_double = 0;
	i = 0;
	while (token_lst->value[i])
	{
		if (quote_simple == 1)
		{
			quote_simple = cmd_quotes_open_simple(data, &token_lst->value, &i);
//			printf("test_1\n");
		}
		else if (quote_double == 1)
		{
			quote_double = cmd_quotes_open_double(data, &token_lst->value, &i);
//			printf("test_2\n");
		}
		else
		{
			if (token_lst->value[i] == '\'')
			{
				quote_simple = cmd_quotes_close_simple(data, &token_lst->value, &i);
//				printf("test_3\n");
			}
			else if (token_lst->value[i] == '"')
			{
				quote_double = cmd_quotes_close_double(data, &token_lst->value, &i);
//				printf("test_4\n");
			}
		}
		i++;
	}
//	printf("fin\n");
}
