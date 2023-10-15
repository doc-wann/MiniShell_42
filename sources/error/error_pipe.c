/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 21:44:51 by nsutter           #+#    #+#             */
/*   Updated: 2023/10/13 21:44:52 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	error_pipe(t_data *data)
{
	perror(NULL);
	exit_minishell(data);
}
