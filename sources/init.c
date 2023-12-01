/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:48:09 by nsutter           #+#    #+#             */
/*   Updated: 2023/11/27 21:13:36 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

bool	init_env(t_data *data, char **envp)
{
	int	i;

	i = 0;
	while (envp && envp[i])
		i++;
	data->env = ft_calloc(i + 1, sizeof * data->env);
	if (data->env == NULL)
		return (false);
	i = 0;
	while (envp[i])
	{
		data->env[i] = ft_strdup(envp[i]);
		if (data->env[i] == NULL)
			return (false);
		i++;
	}
	return (true);
}

void	init_read_line(t_data *data)
{
	data->read_line = NULL;
	data->token_lst = NULL;
	data->token_lst_nb = 1;
	data->cmd_lst = NULL;
	data->nb_exec = 1;
	data->error = 0;
}

void	init_data(t_data *data)
{
	data->env = NULL;
	data->read_line = NULL;
	data->token_lst_nb = 1;
	data->token_lst = NULL;
	data->cmd_lst = NULL;
	data->nb_exec = 1;
	data->error = 0;
	data->exit = 0;
}

void	init_minishell(t_data *data, int argc, char **envp)
{
	// if (!isatty(0))
	// {
	// 	error_init(data, ERROR_ISATTY);
	// 	exit(EXIT_SUCCESS);
	// }
	if (argc != 1)
	{
		error_init(data, ERROR_NB_ARGUMENT);
		exit(EXIT_SUCCESS);
	}
	init_data(data);
	init_env(data, envp);
}
