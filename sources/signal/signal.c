/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaniele <hdaniele@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:36:48 by nsutter           #+#    #+#             */
/*   Updated: 2023/10/18 15:19:52 by hdaniele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	signal_handler(void)
{
	signal(SIGINT, &signal_handler_sigint);
	signal(SIGQUIT, &signal_handler_sigquit);
	if (signum == 56)
	{
		printf("There should be a leak here (signal_int) which will be solved with quit()");
		exit(1);
	}
}
