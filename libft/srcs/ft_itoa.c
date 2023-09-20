/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:52:48 by nsutter           #+#    #+#             */
/*   Updated: 2022/06/09 19:14:00 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_lenint(int nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		nb = nb * (-1);
		len++;
	}
	if (nb == 0)
		len++;
	else
	{
		while (nb > 0)
		{
			nb = nb / 10;
			len++;
		}
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		nb;
	int		len;
	char	*str;

	len = 0;
	if (n == -2147483648)
		return (str = ft_strdup("-2147483648"));
	len = ft_lenint(n);
	nb = n;
	if (nb < 0)
		nb = nb * (-1);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len--] = '\0';
	while (len >= 0)
	{
		str[len] = nb % 10 + '0';
		nb = nb / 10;
		len--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
