/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 20:05:04 by nsutter           #+#    #+#             */
/*   Updated: 2022/08/07 17:46:19 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_put_ptr(unsigned long int ptr)
{
	if (ptr >= 16)
	{
		ft_put_ptr(ptr / 16);
		ft_put_ptr(ptr % 16);
	}
	else
	{
		if (ptr >= 10)
			ft_putchar((ptr - 10) + 'a');
		else
			ft_putchar(ptr + '0');
	}
}

int	ft_len_ptr(unsigned long int ptr)
{
	int	tot;

	tot = 0;
	while (ptr != 0)
	{
		ptr = ptr / 16;
		tot++;
	}
	return (tot);
}

int	ft_tot_ptr(unsigned long int ptr)
{
	int	tot;

	tot = 0;
	if (ptr == 0)
		tot += ft_tot_str(PTR_NULL);
	else
	{
		tot += ft_tot_str("0x");
		ft_put_ptr(ptr);
		tot += ft_len_ptr(ptr);
	}
	return (tot);
}
