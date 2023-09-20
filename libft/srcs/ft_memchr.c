/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:30:00 by nsutter           #+#    #+#             */
/*   Updated: 2022/06/22 21:20:51 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			x;
	unsigned char	*dst;
	unsigned char	str;

	x = 0;
	dst = (unsigned char *)s;
	str = (unsigned char )c;
	while (x < n)
	{
		if (dst[x] == str)
			return (&dst[x]);
		x++;
	}
	return (NULL);
}
