/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:35:49 by nsutter           #+#    #+#             */
/*   Updated: 2023/11/21 22:12:11 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int datarelay(t_data *data);

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
	int	i;

	i = 0;
	while (i < count_args(args))
	{
		if (ft_strncmp(args[i], "$", 1) == 0)
			args[i] = get_env(data->env, args[i]);
		i++;
	}
	return (args);
}

int	builtin_echo(char **args, t_data *data)
{
	int		i;
	int		n_flag;

	i = 0;
	n_flag = 0;
	args += 1;

	if (args[0] == NULL)
		return (0);
	if (ft_strcmp(args[0], "-n") == 0)
	{
		args++;
		n_flag = 1;
	}
	args = ft_varfetch(args, data);
	while(args[i])
	{
		ft_putstr_fd(args[i], STDOUT_FILENO);
		if (i < ft_arrlen(args) - 1)
			ft_putstr_fd(" ", STDOUT_FILENO);
		i++;
	}
	if (n_flag == 0)
		ft_printf("\n");
//	exit (0);
	return (0);
}