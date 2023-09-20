/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 20:20:51 by nsutter           #+#    #+#             */
/*   Updated: 2022/07/13 19:12:25 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_len_uns(unsigned int nbr)
{
	int	tot;

	tot = 0;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		tot++;
	}
	return (tot);
}

char	*ft_itoa_uns(unsigned int nbr)
{
	int		len;
	char	*str;

	len = ft_len_uns(nbr);
	if (nbr == 0)
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len--] = '\0';
	while (len >= 0)
	{
		str[len] = nbr % 10 + '0';
		nbr = nbr / 10;
		len--;
	}
	return (str);
}

int	ft_tot_uns(unsigned int nbr)
{
	int		tot;
	char	*dst;

	tot = 0;
	dst = ft_itoa_uns(nbr);
	tot = ft_tot_str(dst);
	free(dst);
	return (tot);
}
