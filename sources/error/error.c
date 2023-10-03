/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:36:56 by nsutter           #+#    #+#             */
/*   Updated: 2023/10/02 02:15:41 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	error_msg(t_data *data, int error)
{
	(void)data;
	if (error == ERROR_ISATTY)
		printf("Error : Descriptor does not relate to a terminal\n");
	if (error == ERROR_NB_ARGUMENT)
		printf("Error : No need for arguments\n");
	if (error == ERROR_UNCLOSED_QUOTES)
		printf("Error : ERROR_UNCLOSED_QUOTES\n");
	if (error == ERROR_FORK)
	{
		printf("Error : ERROR_FORK\n");
//		free & exit;
	}
}
