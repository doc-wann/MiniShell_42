/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:15:28 by nsutter           #+#    #+#             */
/*   Updated: 2022/06/22 21:19:08 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*str1;
	const char	*str2;
	size_t		x;

	str1 = (char *)dest;
	str2 = (const char *)src;
	if (str1 > str2)
	{
		x = n;
		while (x > 0)
		{
			x--;
			str1[x] = str2[x];
		}
	}
	else
	{
		x = 0;
		while (x < n)
		{
			str1[x] = str2[x];
			x++;
		}
	}
	return (dest);
}
