/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 20:01:11 by nsutter           #+#    #+#             */
/*   Updated: 2023/10/15 14:49:42 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	free_mem(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		ptr[i] = NULL;
		i++;
	}
	free(ptr);
	ptr = NULL;
}

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
