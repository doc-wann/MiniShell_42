/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsutter <nsutter@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 02:30:50 by nsutter           #+#    #+#             */
/*   Updated: 2022/06/22 21:20:24 by nsutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*dst1;
	unsigned char	*dst2;
	size_t			x;

	dst1 = (unsigned char *)s1;
	dst2 = (unsigned char *)s2;
	x = 0;
	while (dst1[x] != '\0' && dst2[x] != '\0' && dst1[x] == dst2[x] && x < n)
		x++;
	if (n != x)
		return (dst1[x] - dst2[x]);
	return (0);
}
