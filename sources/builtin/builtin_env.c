/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:35:53 by nsutter           #+#    #+#             */
/*   Updated: 2023/10/02 01:32:42 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	builtin_env(t_data *data)
{
	char	**env;

	env = data->env;
	if (!env)
		return (1);
	while (*env)
	{
		ft_printf("%s\n", *env);
		env++;
	}
	return (0);
}
