/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:35:39 by nsutter           #+#    #+#             */
/*   Updated: 2023/11/29 22:29:11 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
/*
//maynotbeneeded :(
char	*ft_backtrack(char *track)
{
	int unsigned long	i;

	i = 0;
	while (track[i])
		i++;
	while (i > 0 && track[i] != '/')
		i--;
	if (i > 0 && i < ft_strlen(track))
		return (ft_strncpy(track, i));
	else
		return (track);
}
*/
int	ft_lstlen(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*get_env(char **envs, char *search)
{
	int	i;

	if (ft_strncmp(search, "$", 1) == 0 && ft_strlen(search) > 1)
		search += 1;
	i = 0;
	while (i++ < ft_lstlen(envs) - 1)
	{
		if (ft_strncmp(search, envs[i], ft_strlen(search)) == 0)
		{
			return (ft_substr(envs[i], ft_indexof(envs[i], "=") + 1, ft_strlen(envs[i]) - ft_indexof(envs[i], "=")));
		}
	}
	return (ft_strjoin("$", search));
}
/*
char	*path_parser(char *path)
{
	int	i;

	i = 0;
	while (!ft_isalnum(path[0]))
		path++;
	path = ft_strjoin("/", path);
	return (path);
}

int	builtin_cd(char **cmd, t_data *data)
{
	char	*homepath;
	char	*buffer;

	cmd = ft_varfetch(cmd, data);
	//THIS IS MERELY A "JUST TO MAKE IT WORK" SOLUTION
	if(ft_strcmp(cmd[0], "cd") == 0)
		cmd += 1;

	homepath = get_env(data->env, "$HOME");
	buffer = getcwd(NULL, 0);
	if (cmd[0] == NULL)
	{
		chdir(homepath);
	}
	else if (!chdir(cmd[0]))
	{
		if (ft_strncmp(cmd[0], "..\0", 3) == 0)
			chdir(ft_backtrack(buffer));
		if (ft_strncmp(cmd[0], "../", 3) == 0)
		{
			chdir(ft_backtrack(buffer));
			cmd[0] += 3;
			builtin_cd(cmd, data);
		}
	}
	free(buffer);
	return (0);
}*/

int	builtin_cd(char **cmd, t_data *data)
{
	int	status;

	status = 0;
	if (ft_lstlen(cmd) < 2)
		return (0);
	else if (ft_lstlen(cmd) > 2)
		status = error_builtin_cd_too_many_arg();
	else if (chdir(cmd[1]) != 0)
		status = error_builtin_cd_no_dir(cmd[1]);
	exit_minishell(data, status);
	return (0);
}
<<<<<<< HEAD
=======

>>>>>>> 716b7ac2c103957df76441c3330130b99d777c34
