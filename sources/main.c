/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaniele <hdaniele@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:37:15 by nsutter           #+#    #+#             */
/*   Updated: 2023/10/18 15:33:05 by hdaniele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_minishell(t_data *data)
{
	data->error = lexer_minishell(data);
	if (data->error != 0)
		return (data->error);
	data->error = cmd_lst_create(data);
//	if (data->error != 0)
//		return (data->error);
	return (0);
}

void	loop_minishell(t_data *data)
{
	while (data->exit == 0)
	{
		data->read_line = readline("minishell> ");
		if (data->read_line == NULL || data->read_line[0] == '\0')
			printf("error ??\n");
		if (data->read_line[0] != 0)
			add_history(data->read_line);
		if (data->read_line[0] == '\0' || check_minishell(data) != 0)
			error_msg(data, data->error);
		else
			exec_cmd(data);
		init_read_line(data);
	}
}

int	main(int argc, char **argv, char **envp)
{

	t_data	data;

	(void)argc;
	(void)argv;
	(void)envp;
	signal_handler();
	init_minishell(&data, argc, envp);
	loop_minishell(&data);
//	exit_minishell(&data);
	return (0);
}
