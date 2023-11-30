/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 21:44:47 by nsutter           #+#    #+#             */
/*   Updated: 2023/10/14 19:46:10 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	error_msg_check(t_data *data)
{
	if (data->error == ERROR_UNCLOSED_QUOTES)
		printf("Minishell> syntax error because expected closing quote\n");
	if (data->error == ERROR_PIPE)
	{
//		printf("Minishell> syntax error near unexpected token `|'\n");
		ft_putendl_fd("bash: ", STDERR_FILENO);
		ft_putendl_fd(" syntax error near unexpected token `|'", STDERR_FILENO);
	}
	if (data->error == ERROR_REDIR_INPUT)
		printf("Minishell> syntax error near unexpected token `<'\n");
	if (data->error == ERROR_REDIR_OUTPUT)
		printf("Minishell> syntax error near unexpected token `>'\n");
	if (data->error == ERROR_REDIR_OUTPUT_D)
		printf("Minishell> syntax error near unexpected token `>>'\n");
	if (data->error == ERROR_HEREDOC)
		printf("Minishell> syntax error near unexpected token `<<'\n");
	if (data->error == ERROR_NO_LINE)
		printf("Minishell> syntax error near unexpected token `newline'\n");
	if (data->error == ERROR_START)
		printf("Minishell>\n");
}
