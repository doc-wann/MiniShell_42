/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:36:56 by nsutter           #+#    #+#             */
/*   Updated: 2023/11/23 21:56:24 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	error_init(t_data *data, int error)
{
	(void)data;
	if (error == ERROR_ISATTY)
		printf("Minishell> Error : Descriptor does not relate to a terminal\n");
	if (error == ERROR_NB_ARGUMENT)
		printf("Minishell> Error : No need for arguments\n");
}
