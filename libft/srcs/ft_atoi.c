/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:23:54 by nsutter           #+#    #+#             */
/*   Updated: 2023/07/07 00:38:02 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

int	ft_atoi(const char *nptr)
{
	int	x;
	int	n;
	int	res;

	x = 0;
	while ((nptr[x] >= 9 && nptr[x] <= 13) || nptr[x] == 32)
		x++;
	n = 1;
	if (nptr[x] == '-' || nptr[x] == '+')
	{
		if (nptr[x] == '-')
			n = n * (-1);
		x++;
	}
	res = 0;
	while (nptr[x] >= '0' && nptr[x] <= '9')
	{
		res = res * 10 + nptr[x] - '0';
		x++;
	}
	return (n * res);
}
