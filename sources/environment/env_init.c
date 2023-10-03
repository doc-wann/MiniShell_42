/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:01:23 by nsutter           #+#    #+#             */
/*   Updated: 2023/10/01 20:18:59 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

bool	env_init(t_data *data, char **envp)
{
	int	i;

	i = 0;
	while (envp && envp[i])
		i++;
	data->env = ft_calloc(i + 1, sizeof * data->env);
	if (data->env == NULL)
		return (false);
	i = 0;
	while (envp[i])
	{
		data->env[i] = ft_strdup(envp[i]);
		if (data->env[i] == NULL)
			return (false);
		i++;
	}
	return (true);
}
