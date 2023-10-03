/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:36:02 by nsutter           #+#    #+#             */
/*   Updated: 2023/10/03 22:39:21 by nsutter          ###   ########.fr       */
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
	ret = malloc((ft_lstlen(list) + 2) * sizeof(char *));
	while (i < ft_lstlen(list))
	{
		ret[i] = list[i];
		i++;
	}
	ret[i] = ft_strdup(input);
	ret[++i] = NULL;
	return(ret);
}

int	builtin_export(char **cmd, t_data *data)
{
	cmd[0] += ft_strlen("export ");

	add_to_env(data, ft_split(cmd[0], '=')[0], ft_split(cmd[0], '=')[1]);
	return (0);
}
