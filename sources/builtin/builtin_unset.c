/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:36:13 by nsutter           #+#    #+#             */
/*   Updated: 2023/11/29 22:15:41 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**lst_move(char **lst, int tomove)
{
	lst[tomove] = lst[0];
	lst++;
	return (lst);
}

int	builtin_unset(char **cmd, t_data *data)
{
	int	i;

	i = 0;
	cmd = ft_varfetch(cmd, data);
	//THIS IS MERELY A "JUST TO MAKE IT WORK" SOLUTION
	cmd++;
	while (i < ft_arrlen(data->env) && cmd[0] != NULL)
	{
		if (ft_strcmp(cmd[0], ft_split(data->env[i], '=')[0]) == 0)
		{
			data->env = lst_move(data->env, i);
			return (0);
		}
		i++;
	}
//	ft_printf("Error - No matches were found sadpeepo\n");
	return (1);
}
