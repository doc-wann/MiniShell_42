/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 20:20:51 by nsutter           #+#    #+#             */
/*   Updated: 2022/07/13 20:56:41 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_put_hex(unsigned int nbr, const char format)
{
	if (nbr >= 16)
	{
		ft_put_hex(nbr / 16, format);
		ft_put_hex(nbr % 16, format);
	}
	else
	{
		if (nbr >= 10)
		{
			if (format == 'x')
				ft_putchar((nbr - 10) + 'a');
			if (format == 'X')
				ft_putchar((nbr - 10) + 'A');
		}
		else
			ft_putchar(nbr + '0');
	}
}

int	ft_len_hex(unsigned int nbr)
{
	int	tot;

	tot = 0;
	while (nbr != 0)
	{
		nbr = nbr / 16;
		tot++;
	}
	return (tot);
}

int	ft_tot_hex(unsigned int nbr, const char format)
{
	int	tot;

	tot = 0;
	if (nbr == 0)
		tot += ft_tot_chr('0');
	else
	{
		ft_put_hex(nbr, format);
		tot += ft_len_hex(nbr);
	}
	return (tot);
}
