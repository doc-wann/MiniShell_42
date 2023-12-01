/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:36:02 by nsutter           #+#    #+#             */
/*   Updated: 2023/11/29 22:22:44 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**add_to_array(char **list, char *input);

void	add_to_env(t_data *data, char *key, char *value)
{
	char *result;

	result = ft_strjoin(key, "=");
	result = ft_strjoin(result, value);

	data->env = add_to_array(data->env, result);
}

char	**add_to_array(char **list, char *input)
{
	char **ret;
	int		i;

	i = 0;
	ret = malloc((ft_arrlen(list) + 2) * sizeof(char *));
	while (i < ft_arrlen(list))
	{
		ret[i] = list[i];
		i++;
	}
	ret[i] = ft_strdup(input);
	ret[++i] = NULL;
	return(ret);
}

int	ft_indexof(char *str, char *set)
{
	int index;
	int subindex;
	int val;

	index = 0;
	subindex = 0;
	val = -1;

	while (set[index])
	{
		while(str[subindex])
		{
			if (set[index] == str[subindex])
			{
				if (val > subindex || val == -1)
				{
					val = subindex;
				}
			}
			subindex++;
		}
		index++;
	}
	return (val);
}

int	builtin_export(char **cmd, t_data *data)
{
	cmd += 1;

	if (!ft_isalpha(cmd[0][0]) || ft_indexof(cmd[0], "=") == (int)ft_strlen(cmd[0]) - 1)
	{
		ft_putstr_fd(" not a valid identifier", STDERR_FILENO);
		exit_minishell(data, 1);
		return (0);
	}
	if (cmd[0] == NULL || ft_indexof(cmd[0], "=") == -1)
	{
		if (cmd[0][ft_strlen(cmd[0]) - 1] == '-')
		{
			ft_putstr_fd(" not a valid identifier", STDERR_FILENO);
			exit_minishell(data, 1);
		}
		exit_minishell(data, 0);
		return (0);
	}
	else if (ft_indexof(cmd[0], "=") == (int)ft_strlen(cmd[0]) - 1)
	{
		exit_minishell(data, 1);
		return (0);
	}
	else if (ft_indexof(cmd[0], "=") == ft_indexof(cmd[0], "-") + 1)
	{
		ft_putstr_fd(" not a valid identifier", STDERR_FILENO);
		exit_minishell(data, 1);
		return (0);
	}
	else
		add_to_env(data, ft_split(cmd[0], '=')[0], ft_split(cmd[0], '=')[1]);
	return (0);
}