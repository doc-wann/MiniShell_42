/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:36:08 by nsutter           #+#    #+#             */
/*   Updated: 2023/10/15 15:02:31 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	builtin_pwd(char **cmd)
{
	char	*buf;
	char	*cwd;

	(void)cmd;
	cwd = NULL;
	buf = NULL;
	cwd = getcwd(buf, 100);
	if (!cwd)
		return (error_builtin_pwd());
	ft_printf("%s\n", cwd);
	free(buf);
	free(cwd);
	return (0);
}
