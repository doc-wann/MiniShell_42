/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:37:01 by nsutter           #+#    #+#             */
/*   Updated: 2023/11/29 21:50:18 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exit_minishell(t_data *data, int error)
{
	(void)data;
/*	int	i;

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
	free(data);*/
	exit(error);
}
