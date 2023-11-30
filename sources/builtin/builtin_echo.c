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

char	*catch_var(char *string, t_data *data)
{
	char *backup;
	int i;
	int j;

	j = 0;
	i = 0;
	while (string[i])
	{
		if (string[i] == '$' && string[i + 1] >= 65 && string[i + 1] <= 90)
		{
			j = i + 1;
			while (string[j] >= 65 && string[j] <= 90)
				j++;
<<<<<<< HEAD
			backup = ft_substr(string, j, (j - i) + (j - i) + 1);
			string = ft_strjoin(ft_substr(string, 0, i), get_env(data->env, ft_substr(string, i, j - i)));
			string = ft_strjoin(string, backup);
			i = 0;
=======
			backup = ft_substr(string, j, j - i);
			string = ft_strjoin(ft_substr(string, 0, i), get_env(data->env, ft_substr(string, i, j)));
			string = ft_strjoin(string, backup);
>>>>>>> 716b7ac2c103957df76441c3330130b99d777c34
		}
		else if (string[i] == '$' && string[i + 1] == '?')
		{
			backup = ft_substr(string, i + 2, ft_strlen(string) - i - 2);
			string = ft_strjoin(ft_substr(string, 0, i), ft_itoa(data->exit));
			string = ft_strjoin(string, backup);
<<<<<<< HEAD
			i = 0;
=======
>>>>>>> 716b7ac2c103957df76441c3330130b99d777c34
		}
		i++;
	}

	return (string);
}

char	**ft_varfetch(char **args, t_data *data)
{
	int	i;
	int j;
	char **list;

	i = 0;
	j = 0;
	while (i < count_args(args))
	{
<<<<<<< HEAD
		args[i] = catch_var(args[i], data);
=======
		list = ft_split(args[i], ' ');
		while(list[j])
		{
			list[j] = catch_var(list[j], data);
			j++;
		}
		j = 0;
		while(j < count_args(list) - 1)
		{
			list[j] = ft_strjoin(list[j], " ");
			list[j + 1] = ft_strjoin(list[j], list[j + 1]);
			j++;
		}
		j = 0;
		args[i] = list[count_args(list) - 1];
>>>>>>> 716b7ac2c103957df76441c3330130b99d777c34
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
