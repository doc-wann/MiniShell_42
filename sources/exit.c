/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaniele <hdaniele@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:37:01 by nsutter           #+#    #+#             */
/*   Updated: 2023/10/25 18:08:04 by hdaniele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exit_minishell(t_data *data)
{
	int	i;

	(void)data;
	i = 0;
	while (i < 1000)
	{
		close(i);
		i++;
	}
	while (data->token_lst->next)
	{
		data->token_lst = data->token_lst->next;
		free(data->token_lst->last);
	}
	free(data);
	exit(0);
}
