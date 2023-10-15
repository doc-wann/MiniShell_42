/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:35:49 by nsutter           #+#    #+#             */
/*   Updated: 2023/10/15 15:33:10 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**ft_varfetch(char **cmd, t_data *data)
{
	int		i;
	int		j;
	char	**phrases;

	i = 0;
	while (i < builtin_len(cmd))
	{
		phrases = ft_split(cmd[i], ' ');
		j = 0;
		while (j < builtin_len(phrases))
		{
			if (ft_strncmp(phrases[j], "%", 1) == 0)
				phrases[j] = get_env(data->env, phrases[j]);
			phrases[j] = ft_strjoin(phrases[j], " ");
			j++;
		}
		j = 1;
		while (j < builtin_len(phrases))
		{
			phrases[0] = ft_strjoin(phrases[0], phrases[j]);
			j++;
		}
		cmd[i++] = phrases[0];
	}
	return (cmd);
}

int	builtin_echo(char **cmd, t_data *data)
{
	int		i;
	int		n_flag;

	i = 0;
	n_flag = 0;
	cmd[0] += 4;
	cmd[0] = ft_strtrim(cmd[0], " ");
	cmd = ft_varfetch(cmd, data);
	if (builtin_len(cmd) == 1)
	{
		while (cmd[i])
		{
			printf("%s\n", cmd[i]);
			if (cmd[i + 1] && cmd[i][0] != '\0')
				write(1, " ", 1);
			i++;
		}
	}
	return (0);
}
