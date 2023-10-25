/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaniele <hdaniele@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 21:47:07 by nsutter           #+#    #+#             */
/*   Updated: 2023/10/20 18:57:19 by hdaniele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_arg_read_is_space(char read)
{
	if ((read >= 9 && read <= 13) || read == ' ')
		return (0);
	return (1);
}

int	check_arg_read_is_meta(char read)
{
	if (read == '|')
		return (0);
	//if (read == '<')
	//	return (0);
	//if (read == '>')
	//	return (0);
	return (1);
}

int	check_arg_cmd_size(char *read, int index)
{
	int	size;

	size = 0;
	while (read[index])
	{
		if (check_arg_read_is_meta(read[index]) == 0
			|| check_arg_read_is_space(read[index]) == 0)
			return (size);
		if (read[index] == '\"')
		{
			index++;
			size++;
			while (read[index] != '\"')
			{
				index++;
				size++;
			}
		}
		index++;
		size++;
	}
	return (size);
}

int	check_arg_cmd(t_data *data, int index)
{
	char	*read;

	read = data->read_line;
	if (read[index] == '\'' || read[index] == '\"')
	{
		go_to_token_lst(data, read, index, TOKEN_CMD);
		return (check_arg_cmd_size(read, index));
	}
	if (ft_isprint(read[index]) != 0
		&& check_arg_read_is_meta(read[index]) != 0
		&& check_arg_read_is_space(read[index]) != 0)
	{
		go_to_token_lst(data, read, index, TOKEN_CMD);
		return (check_arg_cmd_size(read, index));
	}
	return (0);
}
