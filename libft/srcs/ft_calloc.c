/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:30:09 by nsutter           #+#    #+#             */
/*   Updated: 2022/06/24 13:31:49 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*dst;
	size_t			x;

	if (size > __INT_MAX__ / nmemb)
		return (NULL);
	dst = (void *)malloc(nmemb * size);
	if (dst == NULL)
		return (NULL);
	x = 0;
	while (x < (nmemb * size))
	{
		dst[x] = '\0';
		x++;
	}
	return (dst);
}
