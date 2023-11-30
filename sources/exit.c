/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:37:01 by nsutter           #+#    #+#             */
<<<<<<< Updated upstream
/*   Updated: 2023/10/15 14:41:00 by nsutter          ###   ########.fr       */
=======
/*   Updated: 2023/11/29 21:50:18 by nsutter          ###   ########.fr       */
>>>>>>> Stashed changes
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exit_minishell(t_data *data, int error)
{
<<<<<<< HEAD
=======
	int	i;

	ft_printf("test0\n");
>>>>>>> 716b7ac2c103957df76441c3330130b99d777c34
	(void)data;
/*	int	i;

	i = 0;
	while (i < 1000)
	{
		close(i);
		i++;
	}
<<<<<<< Updated upstream
=======
	while (data->token_lst->next)
	{
		data->token_lst = data->token_lst->next;
		free(data->token_lst->last);
	}
<<<<<<< HEAD
	free(data);*/
	exit(error);
=======
	free(data);
	ft_printf("test\n");
>>>>>>> Stashed changes
	exit(0);
>>>>>>> 716b7ac2c103957df76441c3330130b99d777c34
}
