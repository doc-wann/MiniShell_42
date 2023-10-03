/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:35:49 by nsutter           #+#    #+#             */
/*   Updated: 2023/10/03 23:26:23 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	count_args(char **args)
{
	int		count;

	count = 0;
	while (args[count])
		count++;
	return (count);
}

char	**ft_varfetch(char **args, t_data *data)
{
	int		i;
	int		j;
	char	**phrases;

	i = 0;
	while (i < count_args(args))
	{
		phrases = ft_split(args[i], ' ');
		j = 0;
		while (j < count_args(phrases))
		{
			if (ft_strncmp(phrases[j], "%", 1) == 0)
			{
				phrases[j] = get_env(data->env, phrases[j]);
			}
			phrases[j] = ft_strjoin(phrases[j], " ");
			j++;
		}
		j = 1;
		while (j < count_args(phrases))
		{
			phrases[0] = ft_strjoin(phrases[0], phrases[j]);
			j++;
		}
		args[i++] = phrases[0];
	}
	return (args);
}

int	builtin_echo(char **args, t_data *data)
{
	int		i;
	int		n_flag;

	i = 0;
	n_flag = 0;
	//THIS IS MERELY A "JUST TO MAKE IT WORK" SOLUTION
	args[0] += 4;
	args[0] = ft_strtrim(args[0], " ");
	args = ft_varfetch(args, data);
	if (count_args(args) == 1)
	{
		while (args[i])
		{
			printf("%s\n", args[i]);
			if (args[i + 1] && args[i][0] != '\0')
				write(1, " ", 1);
			i++;
		}
	}
	return (0);
}
