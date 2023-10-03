/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:36:08 by nsutter           #+#    #+#             */
/*   Updated: 2023/10/02 01:33:14 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	put_endl(char *str, int fd)
{
	if (!str || fd < 0)
		return ;
	ft_putstr_fd(str, fd);
	write(fd, "\n", 1);
}

int	builtin_pwd(char **cmd)
{
	char	*buf;
	char	*cwd;

	(void)cmd;
	cwd = NULL;
	buf = NULL;
	cwd = getcwd(buf, 100);
	if (cwd)
	{
		put_endl(cwd, 1);
		free(buf);
		free(cwd);
		return (0);
	}
	if (!cwd)
		ft_printf("no pwd\n");
	return (1);
}
