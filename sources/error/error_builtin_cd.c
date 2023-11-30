/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_builtin_cd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:36:56 by nsutter           #+#    #+#             */
/*   Updated: 2023/11/29 22:24:08 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	error_builtin_cd_too_many_arg(void)
{
	printf("minishell> cd: too many arguments\n");
	ft_putendl_fd(" too many arguments\n", STDERR_FILENO);
	return (1);
}

int	error_builtin_cd_no_dir(char *cmd)
{
	printf("minishell> cd: %s: ", cmd);
	printf("No such file or directory\n");
	ft_putendl_fd(" No such file or directory\n", STDERR_FILENO);
	return (1);
}
