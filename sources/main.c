/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:37:15 by nsutter           #+#    #+#             */
/*   Updated: 2023/11/28 21:55:40 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Verification phases
// 1 - check_arg			:	Separate CMD and TOKEN and create a first "token_lst"
// 2 - check_syntax			:	Check the correct syntax entry of each token inside "token_lst"
// 3 - check_to_token_lst	:	Create a second "token_lst" without SPACE
// 4 - Cmd_lst				:	Creating the list of commands with pipes to execute

int	check_minishell(t_data *data)
{
	data->error = check_arg(data);
	if (data->error != 0)
		return (data->error);

//////////////////////////////////////////////////////////////
/*	printf("check_arg     : ");
	t_token_lst	*token_lst;
	token_lst = data->token_lst;
	while (token_lst)
	{
		printf("%d ", token_lst->token);
		token_lst = token_lst->next;
	}
	printf("\n");*/
//////////////////////////////////////////////////////////////

	data->error = check_syntax(data);
	if (data->error != 0)
		return (data->error);
	data->error = check_to_token_lst(data);
	if (data->error != 0)
		return (data->error);

//////////////////////////////////////////////////////////////
/*	printf("check_syntax  : ");
	token_lst = data->token_lst;
	while (token_lst)
	{
		printf("%d ", token_lst->token);
		token_lst = token_lst->next;
	}
	printf("\n");*/
//////////////////////////////////////////////////////////////

//	CMD expand (environment variables $ & $?)
//	cmd_expand(data, data->token_lst);
//	CMD quotes (remove single & double quote (except for $))
//	cmd_quotes(data, data->token_lst);

//////////////////////////////////////////////////////////////
/*	printf("check_quotes  : ");
	t_token_lst	*token_lst;
	token_lst = data->token_lst;
	while (token_lst)
	{
		printf("%s ", token_lst->value);
		token_lst = token_lst->next;
	}
	printf("\n");*/
//////////////////////////////////////////////////////////////

	data->error = cmd_lst(data);
//	printf("cmd_lst          : ");
	if (data->error != 0)
		return (data->error);

//////////////////////////////////////////////////////////////
/*	t_cmd_lst	*cmd_lst;
	int			i;
	int			j;
	cmd_lst = data->cmd_lst;
	j = 0;
	while (cmd_lst)
	{
		i = 0;
		while (cmd_lst->cmd[i])
		{
			printf("cmd   : [%d][%d] %s\n", j, i, cmd_lst->cmd[i]);
	//		printf("index : [%d][%d] %d\n", j, i, cmd_lst->index);
			i++;
		}
		j++;
		cmd_lst = cmd_lst->next;
	}*/
//////////////////////////////////////////////////////////////

	return (0);
}

// Create a loop on the prompt as long as the "data->exit" value = 0
void	loop_minishell(t_data *data)
{
	while (data->exit == 0)
	{
		data->read_line = readline("minishell> ");
		if (data->read_line == NULL)
			exit_minishell(data);
		if (data->read_line[0] != 0)
			add_history(data->read_line);
		if (check_minishell(data) != 0)
			error_msg_check(data);
		else
			exec_minishell(data);
		exit (0);
		init_read_line(data);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	(void)argv;
//	signal_handler();
	init_minishell(&data, argc, envp);
	loop_minishell(&data);
//	exit_minishell(&data);
	return (0);
}
