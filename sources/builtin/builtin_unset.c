/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:36:13 by nsutter           #+#    #+#             */
/*   Updated: 2023/10/15 15:30:14 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**lst_move(char **lst, int tomove)
{
	lst[tomove] = lst[0];
	lst++;
	ft_printf("\n\n\n\n\n");
	return (lst);
}

int	builtin_unset(char **cmd, t_data *data)
{
	int	i;

	i = 0;
	cmd = ft_varfetch(cmd, data);
	cmd[0] += 5;
	cmd[0] = ft_strtrim(cmd[0], " ");
	while (i < builtin_len(data->env))
	{
		if (ft_strcmp(cmd[0], ft_split(data->env[i], '=')[0]) == 0)
		{
			data->env = lst_move(data->env, i);
			return (0);
		}
		i++;
	}
	ft_printf("No matches were found sadpeepo\n");
	return (1);
}
