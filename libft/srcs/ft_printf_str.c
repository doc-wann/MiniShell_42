/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 20:09:04 by nsutter           #+#    #+#             */
/*   Updated: 2022/10/25 21:21:55 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_put_str(char *str)
{
	int	tot;

	tot = 0;
	while (str[tot] != '\0')
		tot += ft_tot_chr(str[tot]);
	return (tot);
}

int	ft_tot_str(char *str)
{
	if (str == NULL)
		return (ft_put_str("(null)"));
	return (ft_put_str(str));
}
