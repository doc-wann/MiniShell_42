/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_builtin_exit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:36:56 by nsutter           #+#    #+#             */
/*   Updated: 2023/11/29 22:04:44 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	error_builtin_exit_too_many_arg(t_data *data)
{
	(void)data;
	printf("minishell> exit: too many arguments\n");
	ft_putendl_fd(" too many arguments\n", STDERR_FILENO);
	return (1);
}

int	error_builtin_exit_numeric_arg(t_data *data, char *cmd)
{
	(void)data;
	printf("minishell> exit: %s: ", cmd);
	printf("numeric argument required\n");
	ft_putendl_fd(" numeric argument required\n", STDERR_FILENO);
	return (2);
}

