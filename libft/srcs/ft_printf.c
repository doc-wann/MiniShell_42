/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:11:33 by nsutter           #+#    #+#             */
/*   Updated: 2022/07/13 22:26:52 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_check_fmt(va_list args, const char format)
{
	if (format == 'c')
		return (ft_tot_chr(va_arg(args, int)));
	else if (format == 's')
		return (ft_tot_str(va_arg(args, char *)));
	else if (format == 'p')
		return (ft_tot_ptr((unsigned long int)va_arg(args, void *)));
	else if (format == 'd' || format == 'i')
		return (ft_tot_nbr(va_arg(args, int)));
	else if (format == 'u')
		return (ft_tot_uns(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_tot_hex(va_arg(args, unsigned int), format));
	else if (format == '%')
		return (ft_tot_chr('%'));
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		tot;

	len = 0;
	tot = 0;
	va_start(args, format);
	while (format[len] != '\0')
	{
		if (format[len] == '%')
		{
			len++;
			tot += ft_check_fmt(args, format[len]);
		}
		else
			tot += ft_tot_chr(format[len]);
		len++;
	}
	va_end(args);
	return (tot);
}
