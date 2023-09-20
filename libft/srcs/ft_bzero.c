/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:40:42 by nsutter           #+#    #+#             */
/*   Updated: 2022/06/22 21:18:40 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			x;
	unsigned char	*dst;

	x = 0;
	dst = (unsigned char *)s;
	while (x < n)
	{
		dst[x] = '\0';
		x++;
	}
}
