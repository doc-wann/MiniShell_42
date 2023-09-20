/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 20:05:04 by nsutter           #+#    #+#             */
/*   Updated: 2022/07/13 20:52:16 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_tot_nbr(int nbr)
{
	int		tot;
	char	*dst;

	tot = 0;
	dst = ft_itoa(nbr);
	tot = ft_tot_str(dst);
	free(dst);
	return (tot);
}
