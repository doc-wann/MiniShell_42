/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:35:39 by nsutter           #+#    #+#             */
/*   Updated: 2023/10/15 19:08:07 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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

char	*get_env(char **env, char *search)
{
	int	i;

	if (ft_strncmp(search, "%", 1) == 0 && ft_strlen(search) > 1)
		search += 1;
	i = 0;
	while (i++ < builtin_len(env) - 1)
	{
		if (ft_strncmp(search, env[i], ft_strlen(search)) == 0)
			return (env[i] + ft_strlen(search) + 1);
	}
	return (ft_strjoin("%", search));
}

int	builtin_cd(char **cmd, t_data *data)
{
	char	*homepath;
	char	*buffer;

	cmd = ft_varfetch(cmd, data);
	cmd[0] += 2;
	cmd[0] = ft_strtrim(cmd[0], " ");
	homepath = get_env(data->env, "$HOME");
	buffer = getcwd(NULL, 0);
	if (!chdir(cmd[0]))
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
}
/*
int	builtin_cd(char **cmd, t_data *data)
{
	(void)data;
	if (builtin_len(cmd) < 2)
		return (0);
	if (builtin_len(cmd) > 2)
		return (error_builtin_cd_too_many_arg());
	if (chdir(cmd[1]) != 0)
		return (error_builtin_cd_no_dir(cmd[1]));
	else
		return (0);	
}*/
