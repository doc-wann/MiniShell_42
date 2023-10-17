/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaniele <hdaniele@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:48:09 by nsutter           #+#    #+#             */
/*   Updated: 2023/10/17 17:45:58 by hdaniele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_read_line(t_data *data)
{
	data->read_line = NULL;
	data->nb_execv = 0;
	data->error = 0;
}

void	init_data(t_data *data)
{
	data->env = NULL;
	data->read_line = NULL;
	data->nb_execv = 0;
	data->error = 0;
	data->exit = 0;
}

void	init_minishell(t_data *data, int argc, char **envp)
{
	if (!isatty(0))
	{
		error_msg(data, ERROR_ISATTY);
		exit(EXIT_SUCCESS);
	}
	if (argc != 1)
	{
		error_msg(data, ERROR_NB_ARGUMENT);
		exit(EXIT_SUCCESS);
	}
	init_data(data);
	if (!env_init(data, envp))
	{
		printf("error_env_init");
//		free & exit
	}
}
