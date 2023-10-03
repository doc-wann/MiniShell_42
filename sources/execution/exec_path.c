/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 20:01:11 by nsutter           #+#    #+#             */
/*   Updated: 2023/10/01 20:36:04 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*exec_path(char *cmd, char **envp)
{
	char	**path;
	char	*path_curr;
	char	*path_firm;
	int		i;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH", 4))
		i++;
	path = ft_split(envp[i] + 5, ':');
	i = 0;
	while (path[i])
	{
		path_curr = ft_strjoin(path[i], "/");
		path_firm = ft_strjoin(path_curr, cmd);
		free(path_curr);
		if (access(path_firm, F_OK) == 0)
		{
			free_mem(path);
			return (path_firm);
		}
		free(path_firm);
		i++;
	}
	free_mem(path);
	return (NULL);
}
